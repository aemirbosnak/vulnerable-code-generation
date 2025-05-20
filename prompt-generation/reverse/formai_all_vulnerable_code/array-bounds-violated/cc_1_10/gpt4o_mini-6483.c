//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Function to create and initialize a UDP socket
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// UDP Echo Server
void udp_echo_server() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;
    ssize_t n;

    sockfd = create_socket();

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);
    
    // Server loop
    while (1) {
        addr_len = sizeof(client_addr);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }

        buffer[n] = '\0';  // Null-terminate the received data
        printf("Received: %s\n", buffer);

        sendto(sockfd, buffer, n, 0, (const struct sockaddr *)&client_addr, addr_len);
        printf("Echoed back: %s\n", buffer);
    }

    close(sockfd);
}

// UDP Echo Client
void udp_echo_client(const char *message) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;
    ssize_t n;

    sockfd = create_socket();

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    sendto(sockfd, message, strlen(message), 0, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Sent: %s\n", message);

    addr_len = sizeof(server_addr);
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
    if (n < 0) {
        perror("Receive failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    buffer[n] = '\0'; // Null-terminate buffer
    printf("Received echo back: %s\n", buffer);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <message to send>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) {
        // Child process: run the server
        udp_echo_server();
    } else {
        // Parent process: run the client
        sleep(1); // Give the server time to start
        udp_echo_client(argv[1]);
    }

    return 0;
}