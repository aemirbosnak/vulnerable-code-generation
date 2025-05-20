//FormAI DATASET v1.0 Category: Networking ; Style: rigorous
// A simple networking example program using sockets in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(server_addr);

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, addr_len);
    memset(&client_addr, 0, sizeof(client_addr));
     
    // Filling server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
     
    // Binding the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int len = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[len] = '\0';
        printf("Message from client: %s\n", buffer);

        char *reply = "Hello from server";
        sendto(sockfd, (const char *)reply, strlen(reply), MSG_CONFIRM, (const struct sockaddr *)&client_addr, addr_len);
        printf("Reply message sent\n");
    }

    close(sockfd);
    return 0;
}