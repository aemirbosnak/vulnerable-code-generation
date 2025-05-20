//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, valread, portno, ch;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFF_SIZE];

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set up the server's address struct
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // bind to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Now we're listening
    listen(sockfd, 5);

    // Accept the client connection
    while ((portno = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &ch)) > 0) {
        printf("Connected to: %s\n", inet_ntoa(serv_addr.sin_addr));
        while ((valread = recv(portno, buffer, BUFF_SIZE - 1, 0)) > 0) {
            buffer[valread] = '\0';
            printf("Received: %s\n", buffer);
            send(portno, buffer, strlen(buffer), 0);
        }
        close(portno);
    }

    // clean up the socket
    close(sockfd);
    return 0;
}