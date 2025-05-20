//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (buffer[0] == '.') break;  // A simple condition to stop on message end
    }
}

void get_mail(int sockfd, const char *user, const char *pass) {
    char command[BUFFER_SIZE];

    sprintf(command, "USER %s", user);
    send_command(sockfd, command);
    read_response(sockfd);

    sprintf(command, "PASS %s", pass);
    send_command(sockfd, command);
    read_response(sockfd);

    send_command(sockfd, "LIST");
    read_response(sockfd);

    send_command(sockfd, "RETR 1");
    read_response(sockfd);

    send_command(sockfd, "QUIT");
    read_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    read_response(sockfd);

    get_mail(sockfd, argv[2], argv[3]);

    close(sockfd);
    
    return 0;
}