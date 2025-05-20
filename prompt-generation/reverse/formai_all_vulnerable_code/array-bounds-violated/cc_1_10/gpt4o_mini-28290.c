//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: decentralized
// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void process_message(char *message, struct sockaddr_in *client_addr) {
    time_t rawtime;
    struct tm *timeinfo;
    char time_buffer[80];

    // Get current time
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    
    printf("Received message from %s:%d at %s - Message: %s\n",
           inet_ntoa(client_addr->sin_addr),
           ntohs(client_addr->sin_port),
           time_buffer,
           message);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, 
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';
        
        process_message(buffer, &client_addr);
    }

    close(sockfd);
    return 0;
}