//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
// A simple TCP/IP server-client model in C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MYPORT 8080 // the port users will be connecting to

#define MAXBUFLEN 100

int main(int argc, char *argv[]) {
    int sockfd, new_fd; // listen on sockfd, new connection on new_fd
    struct sockaddr_in my_addr; // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t sin_size;
    char buf[MAXBUFLEN];
    int numbytes;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&my_addr, 0, sizeof my_addr); // make sure the struct is empty
    my_addr.sin_family = AF_INET; // use IPv4
    my_addr.sin_port = htons(MYPORT); // network byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // bind to all local interfaces

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server: waiting for connections...\n");

    while (1) { // main accept() loop
        sin_size = sizeof their_addr;
        if ((new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1) {
            perror("accept");
            continue;
        }

        printf("Server: got connection from %s\n", inet_ntoa(their_addr.sin_addr));

        if (!fork()) { // this is the child process
            close(sockfd); // child doesn't need the listener

            if ((numbytes = recv(new_fd, buf, MAXBUFLEN - 1, 0)) == -1) {
                perror("recv");
                close(new_fd);
                exit(1);
            }
            buf[numbytes] = '\0';

            printf("Client says: %s\n", buf);

            if (send(new_fd, "Hello, world!", 13, 0) == -1) {
                perror("send");
            }
            close(new_fd);
            exit(0);
        }
        close(new_fd); // parent doesn't need this
    }

    return 0;
}