//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <imap_server_name> <imap_port_num> <username>\n", argv[0]);
        exit(1);
    }

    char *server_name = argv[1];
    char *port_num = argv[2];
    char *username = argv[3];

    //create socket
    struct hostent *server = gethostbyname(server_name);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: cannot create socket\n");
        exit(1);
    }

    //connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port_num));

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: cannot connect to server\n");
        exit(1);
    }

    //read welcome message from server
    char buf[MAX_BUF];
    int n = read(sockfd, buf, MAX_BUF-1);
    if (n < 0) {
        printf("Error: cannot read server message\n");
        exit(1);
    }

    //send login command
    char login[MAX_BUF];
    snprintf(login, sizeof(login), "LOGIN %s \r\n", username);
    n = write(sockfd, login, strlen(login));
    if (n < 0) {
        printf("Error: cannot send command to server\n");
        exit(1);
    }

    //read login response from server
    n = read(sockfd, buf, MAX_BUF-1);
    if (n < 0) {
        printf("Error: cannot read server message\n");
        exit(1);
    }

    if (strstr(buf, "OK LOGIN Completed") == NULL) {
        printf("Error: login failed\n");
        exit(1);
    }

    bool quit = false;

    while (!quit) {
        printf("Enter command: ");
        char command[MAX_BUF];
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "QUIT\n") == 0) {
            quit = true;
            char quit_command[10] = "LOGOUT\r\n";
            n = write(sockfd, quit_command, strlen(quit_command));
            if (n < 0) {
                printf("Error: cannot send command to server\n");
                exit(1);
            }
            
            //read logout response from server
            n = read(sockfd, buf, MAX_BUF-1);
            if (n < 0) {
                printf("Error: cannot read server message\n");
                exit(1);
            }

            if (strstr(buf, "OK LOGOUT Completed") == NULL) {
                printf("Error: logout failed\n");
                exit(1);
            }

            printf("Connection closed\n");
            break;
        }

        n = write(sockfd, command, strlen(command));
        if (n < 0) {
            printf("Error: cannot send command to server\n");
            exit(1);
        }

        n = read(sockfd, buf, MAX_BUF-1);
        if (n < 0) {
            printf("Error: cannot read server message\n");
            exit(1);
        }

        printf("%s\n", buf);
    }

    close(sockfd);
    return 0;
}