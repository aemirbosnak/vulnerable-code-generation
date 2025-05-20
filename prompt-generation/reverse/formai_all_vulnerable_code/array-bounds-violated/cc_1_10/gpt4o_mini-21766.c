//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void setup_server(int *server_socket, struct sockaddr_in *server_addr) {
    *server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (*server_socket < 0) {
        handle_error("Socket creation failed");
    }

    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(SERVER_PORT);

    if (bind(*server_socket, (const struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        handle_error("Bind failed");
    }
}

void receive_data(int server_socket, struct sockaddr_in *client_addr) {
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(*client_addr);
    int bytes_received;

    while (1) {
        bytes_received = recvfrom(server_socket, buffer, BUFFER_SIZE, 0, 
                                  (struct sockaddr *)client_addr, &addr_len);
        if (bytes_received < 0) {
            handle_error("Receive failed");
        }
        buffer[bytes_received] = '\0';
        printf("Received %d bytes from client: %s\n", bytes_received, buffer);
    }
}

void test_speed(const char *server_ip) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timespec start_time, end_time;
    int total_bytes_sent = 0;

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_socket < 0) {
        handle_error("Client socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address");
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    for (int i = 0; i < TEST_DURATION; i++) {
        snprintf(buffer, BUFFER_SIZE, "Ping %d", i);
        ssize_t bytes_sent = sendto(client_socket, buffer, strlen(buffer), 0, 
                                     (const struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0) {
            handle_error("Send failed");
        }
        total_bytes_sent += bytes_sent;
        usleep(1000000); // Sleep for 1 second
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    double speed_mbps = (total_bytes_sent * 8) / (elapsed_time * 1e6);
    
    printf("Total bytes sent: %d\n", total_bytes_sent);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Speed: %.2f Mbps\n", speed_mbps);

    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;

    setup_server(&server_socket, &server_addr);
    printf("Server started on port %d...\n", SERVER_PORT);
  
    if (fork() == 0) {
        // This is the child process that runs the speed test
        sleep(1); // Allow the server to start first
        test_speed("127.0.0.1"); // Testing speed on localhost
        exit(0);
    }

    // This is the parent process that handles receiving data
    receive_data(server_socket, &client_addr);

    close(server_socket);
    return 0;
}