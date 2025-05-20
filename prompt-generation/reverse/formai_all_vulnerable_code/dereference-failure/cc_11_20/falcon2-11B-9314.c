//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    int i;
    int ch;
    char username[] = "ftp";
    char password[] = "password";

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket failed");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(21);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(0);
    }

    printf("Connected to FTP server\n");
    fflush(stdout);

    send(sockfd, "USER ", 5, 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    send(sockfd, username, strlen(username), 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    send(sockfd, "PASS ", 5, 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    send(sockfd, password, strlen(password), 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    printf("FTP authentication successful\n");
    fflush(stdout);

    send(sockfd, "LIST\r\n", 10, 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    printf("%s\n", buffer);
    fflush(stdout);

    send(sockfd, "QUIT\r\n", 10, 0);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving data");
        exit(0);
    }

    printf("%s\n", buffer);
    fflush(stdout);

    close(sockfd);
    return 0;
}