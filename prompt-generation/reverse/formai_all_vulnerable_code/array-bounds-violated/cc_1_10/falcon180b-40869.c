//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;
    char *ptr;
    time_t ticks;
    struct tm *tm;

    portno = 8080;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error: %s", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to server");

    // Send data to server
    while (1) {
        printf("Enter message: ");
        fgets(buffer, 1024, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("Sent %d bytes\n", n);
        bzero(buffer, 1024);
    }

    // Receive data from server
    while (1) {
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("Received %d bytes\n", n);
        ptr = strtok(buffer, "\n");
        while (ptr!= NULL) {
            printf("Message from server: %s\n", ptr);
            ptr = strtok(NULL, "\n");
        }
        bzero(buffer, 1024);
    }

    // Close the socket
    close(sockfd);

    return 0;
}