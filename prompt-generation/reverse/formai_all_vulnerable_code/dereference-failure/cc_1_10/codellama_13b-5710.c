//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define QOS_MONITOR_PORT 12345
#define QOS_MONITOR_BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, new_fd, portno, clilen, n;
    char buffer[QOS_MONITOR_BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t client_len;

    if (argc < 2) {
        fprintf(stderr, "usage: qos_monitor <port>\n");
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    listen(sockfd, 5);
    client_len = sizeof(cli_addr);

    while (1) {
        new_fd = accept(sockfd, (struct sockaddr *) &cli_addr, &client_len);
        if (new_fd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        bzero(buffer, QOS_MONITOR_BUFSIZE);
        n = read(new_fd, buffer, QOS_MONITOR_BUFSIZE);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }

        printf("Received message: %s\n", buffer);

        close(new_fd);
    }

    return 0;
}