//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    char *host, *port;
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    if (argc != 3) {
        printf("usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    port = argv[2];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Get the server's IP address
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        exit(0);
    }

    // Set up the server's address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(0);
    }

    // Send the email
    printf("To: ");
    scanf("%s", sendline);
    write(sockfd, sendline, strlen(sendline));

    printf("From: ");
    scanf("%s", sendline);
    write(sockfd, sendline, strlen(sendline));

    printf("Subject: ");
    scanf("%s", sendline);
    write(sockfd, sendline, strlen(sendline));

    printf("Body: ");
    scanf("%s", sendline);
    write(sockfd, sendline, strlen(sendline));

    // Receive the response from the server
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(0);
    }
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Close the socket
    close(sockfd);

    return 0;
}