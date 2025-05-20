//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define MAX_RESPONSE_SIZE 1024
#define POP3_PORT 110
#define POP3_USER "username"
#define POP3_PASS "password"

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE_SIZE];
    char response[MAX_RESPONSE_SIZE];
    char *username = POP3_USER;
    char *password = POP3_PASS;
    char *cmd = "USER ";
    char *auth_cmd = "PASS ";
    char *stat_cmd = "STAT";
    int num_mails = 0;
    int i;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error: Unable to connect to server\n");
        exit(2);
    }

    printf("Connected to server\n");

    send(sockfd, cmd, strlen(cmd), 0);
    retval = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (retval == -1) {
        printf("Error: Unable to receive response\n");
        exit(3);
    }

    printf("Server response: %s", response);

    send(sockfd, auth_cmd, strlen(auth_cmd) + strlen(password), 0);
    retval = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (retval == -1) {
        printf("Error: Unable to receive response\n");
        exit(4);
    }

    printf("Server response: %s", response);

    send(sockfd, stat_cmd, strlen(stat_cmd), 0);
    retval = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);
    if (retval == -1) {
        printf("Error: Unable to receive response\n");
        exit(5);
    }

    printf("Server response: %s", response);

    while ((retval = recv(sockfd, buffer, MAX_LINE_SIZE, 0)) > 0) {
        buffer[retval] = '\0';
        printf("Server response: %s", buffer);
    }

    close(sockfd);

    return 0;
}