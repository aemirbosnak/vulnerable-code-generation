//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define POLL_DELAY 1 // in seconds

void log_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        log_error("Socket creation failed");
    }
    return sockfd;
}

void set_socket_options(int sockfd) {
    int option_value = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &option_value, sizeof(option_value)) < 0) {
        log_error("Setting socket options failed");
    }
}

struct sockaddr_in create_server_address() {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    return server_addr;
}

void bind_socket(int sockfd, struct sockaddr_in *server_addr) {
    if (bind(sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        log_error("Binding socket failed");
    }
}

void receive_data(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    while (1) {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        int recv_len = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        
        if (recv_len < 0) {
            log_error("Receiving data failed");
        }

        buffer[recv_len] = '\0';
        printf("Received: %s\n", buffer);

        // Implement basic QoS monitoring logic
        struct timeval time_received;
        gettimeofday(&time_received, NULL);
        printf("Timestamp: %ld.%06ld\n", time_received.tv_sec, time_received.tv_usec);
        // Add more QoS evaluation and metrics here (e.g. packet loss, latency)
    }
}

void monitor_qos() {
    int sockfd = create_socket();
    set_socket_options(sockfd);
    
    struct sockaddr_in server_addr = create_server_address();
    bind_socket(sockfd, &server_addr);
    
    printf("QoS Monitor running on port %d...\n", SERVER_PORT);
    
    receive_data(sockfd);
    
    close(sockfd);
}

int main() {
    monitor_qos();
    return 0;
}