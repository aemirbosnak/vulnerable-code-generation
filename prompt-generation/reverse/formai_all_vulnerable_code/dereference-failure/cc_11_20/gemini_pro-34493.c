//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recvline[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Resolve the server's address
    struct hostent *hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        fprintf(stderr, "gethostbyname error for %s\n", argv[1]);
        exit(1);
    }

    // Fill in the server's address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, hp->h_addr, hp->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive the welcome message
    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", recvline);

    // Send the USER command
    char user_cmd[MAX_LINE];
    sprintf(user_cmd, "USER %s\r\n", getenv("USER"));
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the response to the USER command
    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", recvline);

    // Send the PASS command
    char pass_cmd[MAX_LINE];
    sprintf(pass_cmd, "PASS %s\r\n", getenv("PASSWORD"));
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the response to the PASS command
    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", recvline);

    // Send the STAT command
    if (send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the response to the STAT command
    if (recv(sockfd, recvline, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", recvline);

    // Send the LIST command
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the response to the LIST command
    while (recv(sockfd, recvline, MAX_LINE, 0) > 0) {
        printf("%s", recvline);
    }

    // Send the RETR command
    if (send(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the response to the RETR command
    FILE *fp = fopen("email.txt", "w");
    while (recv(sockfd, recvline, MAX_LINE, 0) > 0) {
        fprintf(fp, "%s", recvline);
    }
    fclose(fp);

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}