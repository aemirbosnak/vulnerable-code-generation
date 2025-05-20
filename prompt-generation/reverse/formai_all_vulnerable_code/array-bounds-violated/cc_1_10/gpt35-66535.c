//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define IP_ADDRESS "127.0.0.1"

int main(){
    int sock, length;
    char buffer[1024];
    struct sockaddr_in server_addr;
    socklen_t addr_len;

    // Create a TCP Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set Server Address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IP_ADDRESS, &server_addr.sin_addr) <= 0){
        perror("Invalid IP Address");
        exit(EXIT_FAILURE);
    }

    // Connect to Server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }

    printf("Connected to Server\n");

    // Send Data to Server
    char message[] = "Hello Server!";
    if (send(sock, message, strlen(message), 0) < 0){
        perror("Failed to send data");
        exit(EXIT_FAILURE);
    }

    printf("Data Sent to Server\n");

    // Receive Data from Server
    if ((length = recv(sock, buffer, 1024, 0)) < 0){
        perror("Failed to receive data");
        exit(EXIT_FAILURE);
    }

    buffer[length] = '\0';
    printf("Received Data: %s\n", buffer);

    close(sock);
    return 0;
}