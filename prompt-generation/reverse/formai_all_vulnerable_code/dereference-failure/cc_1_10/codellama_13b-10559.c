//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: irregular
// A unique C TCP/IP Programming example program in an irregular style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the program is run with the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <server port>\n", argv[0]);
        return 1;
    }

    // Get the server IP and port from the command line arguments
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // Create a socket for communicating with the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char msg[MAX_MSG_SIZE];
    printf("Enter a message to send to the server: ");
    fgets(msg, MAX_MSG_SIZE, stdin);
    send(sock, msg, strlen(msg), 0);

    // Receive a message from the server
    char buf[MAX_MSG_SIZE];
    recv(sock, buf, MAX_MSG_SIZE, 0);
    printf("Message from server: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}