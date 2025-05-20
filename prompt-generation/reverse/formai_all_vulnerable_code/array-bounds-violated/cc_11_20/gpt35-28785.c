//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(0);
    }

    char buf[MAX_BUF_SIZE];

    // Connect to server
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent* host;
    const char* ip_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    ip_addr = inet_ntoa(*((struct in_addr*) host->h_addr_list[0]));
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, ip_addr, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Get greeting message from server
    memset(buf, 0, sizeof(buf));
    ssize_t recv_bytes = recv(sockfd, buf, sizeof(buf)-1, 0);
    if (recv_bytes < 0) {
        perror("recv");
        exit(1);
    }
    buf[recv_bytes] = '\0';
    printf("%s\n", buf);

    // Log in
    char username[MAX_BUF_SIZE] = {'\0'};
    char password[MAX_BUF_SIZE] = {'\0'};
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    char login_cmd[MAX_BUF_SIZE] = {'\0'};
    sprintf(login_cmd, "USER %s\r\nPASS %s\r\n", username, password);
    if (send(sockfd, login_cmd, strlen(login_cmd), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Check login result
    memset(buf, 0, sizeof(buf));
    recv_bytes = recv(sockfd, buf, sizeof(buf)-1, 0);
    if (recv_bytes < 0) {
        perror("recv");
        exit(1);
    }
    buf[recv_bytes] = '\0';
    printf("%s\n", buf);

    // List messages
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Check message list
    memset(buf, 0, sizeof(buf));
    recv_bytes = recv(sockfd, buf, sizeof(buf)-1, 0);
    if (recv_bytes < 0) {
        perror("recv");
        exit(1);
    }
    buf[recv_bytes] = '\0';
    printf("%s\n", buf);

    // Quit
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Close connection
    close(sockfd);

    return 0;
}