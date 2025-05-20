//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sendfile.h>

#define PORT 21
#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFERSIZE];
    char filename[BUFFERSIZE];
    int n;
    int fd;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send username
    send(sockfd, "USER anonymous\r\n", strlen("USER anonymous\r\n"), 0);

    // Send password
    send(sockfd, "PASS anonymous\r\n", strlen("PASS anonymous\r\n"), 0);

    // Change directory to root
    send(sockfd, "CWD /\r\n", strlen("CWD /\r\n"), 0);

    // Get directory listing
    send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);

    // Read server response
    while ((n = recv(sockfd, buffer, BUFFERSIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}