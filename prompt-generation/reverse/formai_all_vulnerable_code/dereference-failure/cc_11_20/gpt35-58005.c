//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sock_fd, port_num, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *host = "localhost";
    char *user = NULL;
    char *password = NULL;

    if(argc < 4) {
        fprintf(stderr, "Usage: %s hostname port username password\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port_num = atoi(argv[2]);
    user = argv[3];
    password = argv[4];

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        perror("Failed to create socket\n");
        exit(1);
    }

    server = gethostbyname(host);
    if(server == NULL) {
        perror("Failed to find server by name\n");
        exit(1);
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port_num);

    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server\n");
        exit(1);
    }

    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if(n < 0) {
        perror("Failed to read greeting from server\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "LOGIN %s %s\r\n", user, password);
    n = write(sock_fd, buffer, strlen(buffer));
    if(n < 0) {
        perror("Failed to send login command to server\n");
        exit(1);
    }

    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if(n < 0) {
        perror("Failed to read response from server\n");
        exit(1);
    }
    buffer[n] = '\0';

    if(strstr(buffer, "OK") == NULL) {
        perror("Failed to login to server\n");
        exit(1);
    }

    sprintf(buffer, "SELECT inbox\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if(n < 0) {
        perror("Failed to send select command to server\n");
        exit(1);
    }

    n = read(sock_fd, buffer, BUFFER_SIZE - 1);
    if(n < 0) {
        perror("Failed to read select response from server\n");
        exit(1);
    }
    buffer[n] = '\0';
    if(strstr(buffer, "OK") == NULL) {
        perror("Failed to select inbox\n");
        exit(1);
    }

    sprintf(buffer, "FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if(n < 0) {
        perror("Failed to send fetch command to server\n");
        exit(1);
    }

    while(1) {
        n = read(sock_fd, buffer, BUFFER_SIZE - 1);
        if(n < 0) {
            perror("Failed to read fetch response from server\n");
            exit(1);
        }
        if(n == 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }

    close(sock_fd);
    exit(0);

}