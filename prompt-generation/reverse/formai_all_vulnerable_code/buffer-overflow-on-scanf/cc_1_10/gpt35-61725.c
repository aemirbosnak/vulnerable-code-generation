//FormAI DATASET v1.0 Category: Client Server Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in server_addr;
    int sock_fd;
    char message[1024];
    char server_response[1024];
    int valread;

    // Creating socket file descriptor
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Socket creation error.");
        return -1;
    }

    memset(&server_addr, '0', sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported.");
        return -1;
    }

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error.");
        return -1;
    }

    // Chat code
    while(1) {
        printf("You: ");
        scanf("%s", message);

        // Check for Chat end condition
        if (strcasecmp(message, "Bye") == 0) {
            printf("Connection severed by client.");
            break;
        }

        send(sock_fd, message, strlen(message), 0);
        printf("Message Sent.\n");

        valread = read(sock_fd, server_response, 1024);
        printf("Server: %s\n", server_response);
    }

    close(sock_fd);
    return 0;
}