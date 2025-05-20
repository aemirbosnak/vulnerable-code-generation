//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *username = argv[2];

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(POP3_PORT),
        .sin_addr = {
            .s_addr = *(uint32_t *)host->h_addr_list[0],
        },
    };

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[1024];

    // Receive welcome message
    int bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read == -1) {
        perror("recv");
        exit(1);
    }

    // Send USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to USER command
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    // Send PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to PASS command
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    // Send LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive response to LIST command
    bytes_read = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_read == -1) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    // Send QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}