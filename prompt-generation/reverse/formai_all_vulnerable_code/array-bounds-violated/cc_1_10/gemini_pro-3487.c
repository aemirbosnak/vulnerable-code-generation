//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 8080

int main() {
    int sockfd;
    char buffer[MAX_LINE];
    char *hello = "Hello from client!";
    struct sockaddr_in servaddr;

    // Let's create a socket that will allow us to talk to the server.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Now, let's set up the server's address so we know where to send our message.
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("invalid server address");
        exit(EXIT_FAILURE);
    }

    // Time to connect to the server. Let's hope it's listening!
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Okay, we're connected! Let's send our cheerful hello message.
    send(sockfd, hello, strlen(hello), 0);
    printf("Client: %s\n", hello);

    // Now, let's wait for the server's happy reply.
    int n;
    n = recv(sockfd, buffer, MAX_LINE, 0);
    buffer[n] = '\0';
    printf("Server: %s\n", buffer);

    // We're done! Let's clean up and say goodbye.
    close(sockfd);
    return 0;
}