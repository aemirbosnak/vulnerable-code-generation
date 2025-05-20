//FormAI DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080 // the port number we're going to use

int main() {
    int fd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, client;
    char buffer[1024];

    // Creating a socket file descriptor
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("Socket creation failed.\n");
        exit(0);
    }
    else {
        printf("Socket successfully created.\n");
    }

    // Clearing the buffer
    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(fd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed.\n");
        exit(0);
    }
    else {
        printf("Socket bind successful.\n");
    }

    // Setting up a connection queue and listening
    if ((listen(fd, 5)) != 0) {
        printf("Listen failed.\n");
        exit(0);
    }
    else {
        printf("Server listening on port %d...\n", PORT);
    }

    // Accepting connections
    len = sizeof(client);
    connfd = accept(fd, (struct sockaddr*)&client, &len);
    if (connfd < 0) {
        printf("Server accept failed.\n");
        exit(0);
    }
    else {
        printf("Server accepted the client.\n");
    }

    // Receiving message from the client
    int n = read(connfd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("Client sent message: %s\n", buffer);

    // Closing the connection
    close(connfd);
    close(fd);

    return 0;
}