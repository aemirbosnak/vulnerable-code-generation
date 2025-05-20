//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define SERVER_PORT 8080
#define SERVER_IP "localhost"

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    char *message;
    int n, i;
    char *server_ip = SERVER_IP;
    int server_port = SERVER_PORT;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_ip);
    serv_addr.sin_port = htons(server_port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send message to the server
    message = "Hello, world!";
    n = strlen(message);
    write(sockfd, message, n);

    // Receive message from the server
    n = read(sockfd, buffer, MAX_LINE);
    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}