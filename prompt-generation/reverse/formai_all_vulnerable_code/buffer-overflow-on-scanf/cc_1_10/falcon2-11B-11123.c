//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    struct hostent *server;
    struct in_addr *ip_addr;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    printf("Enter the hostname or IP address of the server:\n");
    scanf("%s", &buffer);

    server = gethostbyname(buffer);
    if (server == NULL) {
        fprintf(stderr, "Error: Hostname not found\n");
        return 1;
    }

    ip_addr = (struct in_addr *)server->h_addr;
    portno = htons(5000);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *) ip_addr, (char *) &serv_addr.sin_addr.s_addr, sizeof(struct in_addr));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to server\n");

    for (;;) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("%s\n", buffer);
        send(sockfd, buffer, sizeof(buffer), 0);
    }

    return 0;
}