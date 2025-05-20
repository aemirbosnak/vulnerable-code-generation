#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *he;
    struct sockaddr_in server_addr;

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("gethostbyname");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Vulnerability: No error checking after connect
    send(sockfd, "HELO localhost\r\n", 14, 0);
    send(sockfd, "MAIL FROM:<sender@example.com>\r\n", 35, 0);
    send(sockfd, "RCPT TO:<recipient@example.com>\r\n", 36, 0);
    send(sockfd, "DATA\r\n", 6, 0);
    send(sockfd, "Subject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n", 58, 0);
    send(sockfd, "QUIT\r\n", 6, 0);

    close(sockfd);
    return 0;
}
