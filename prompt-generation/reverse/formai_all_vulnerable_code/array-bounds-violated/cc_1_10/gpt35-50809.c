//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

void check_command(int code, char* response)
{
    if (code >= 400) {
        printf("Error: %s\n", response);
        exit(code);
    }
}

void receive_response(int sockfd)
{
    char response[BUF_SIZE];
    int code;

    memset(response, 0, BUF_SIZE);
    recv(sockfd, response, BUF_SIZE, 0);

    sscanf(response, "%d", &code);
    check_command(code, response);
}

void send_command(int sockfd, const char* command, const char* arguments)
{
    char request[BUF_SIZE];

    memset(request, 0, BUF_SIZE);
    sprintf(request, "%s %s\r\n", command, arguments);
    send(sockfd, request, strlen(request), 0);
}

void receive_lines(int sockfd)
{
    char buf[BUF_SIZE];
    int nbytes;

    while ((nbytes = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
        buf[nbytes] = '\0';
        printf("%s", buf);
        if (buf[nbytes - 1] == '\n') {
            break;
        }
    }
}

int main(int argc, char** argv)
{
    char* servername = "pop3.example.com";
    int serverport = 110;
    char* username = "user";
    char* password = "pass";

    if (argc > 1) {
        servername = argv[1];
    }
    if (argc > 2) {
        serverport = atoi(argv[2]);
    }
    if (argc > 3) {
        username = argv[3];
    }
    if (argc > 4) {
        password = argv[4];
    }

    // resolve server name to ip address
    struct hostent* server = gethostbyname(servername);
    if (server == NULL) {
        perror("Could not resolve server hostname");
        exit(1);
    }
    char* serverip = inet_ntoa(*((struct in_addr*) server->h_addr_list[0]));

    // create socket and connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(1);
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(serverip);
    serveraddr.sin_port = htons(serverport);
    if (connect(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    // receive greeting message
    receive_lines(sockfd);

    // send username
    send_command(sockfd, "USER", username);
    receive_response(sockfd);

    // send password
    send_command(sockfd, "PASS", password);
    receive_response(sockfd);

    // send list command and receive number of messages and total size
    send_command(sockfd, "LIST", "");
    receive_response(sockfd);
    receive_lines(sockfd);

    // send quit command
    send_command(sockfd, "QUIT", "");
    receive_response(sockfd);

    close(sockfd);
    return 0;
}