//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

// Client Function
void client(char *ip) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(ip);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char message[256];
    printf("Enter your deductions, great detective: ");
    scanf("%s", message);

    // Send deductions to server
    send(sockfd, message, strlen(message), 0);

    // Close the connection
    close(sockfd);
}

// Server Function
void server() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Mark socket as listening
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[256];
        valread = read(new_socket, buffer, 256);
        printf("\nDeductions received: %s", buffer);

        char response[] = "Elementary, my dear Watson!";
        send(new_socket, response, strlen(response), 0);
        printf("\nResponse sent\n");
        close(new_socket);
    }
}

// Main Function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return -1;
    }

    int role;
    printf("Choose your role, detective:\n1. Client\n2. Server\n");
    scanf("%d", &role);

    switch (role) {
    case 1:
        client(argv[1]);
        break;
    case 2:
        server();
        break;
    default:
        printf("Invalid role. Please choose 1 or 2.\n");
        break;
    }

    return 0;
}