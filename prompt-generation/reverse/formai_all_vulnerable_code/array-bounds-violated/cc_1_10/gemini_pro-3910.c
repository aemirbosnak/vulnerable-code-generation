//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORT 65535

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[1024];
    int port;
    int n;

    // Creating a socket descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Scanning ports
    for (port = 1; port <= MAX_PORT; port++) {
        servaddr.sin_port = htons(port);

        // Connecting to the server
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
            continue;
        }

        // Sending a message to the server
        sprintf(buf, "Hello from port %d", port);
        send(sockfd, buf, strlen(buf), 0);

        // Receiving a message from the server
        n = recv(sockfd, buf, 1024, 0);
        buf[n] = '\0';
        printf("Received: %s\n", buf);

        // Closing the connection
        close(sockfd);
    }

    return 0;
}