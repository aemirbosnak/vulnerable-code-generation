//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char host[BUFFER_SIZE];
    char user[BUFFER_SIZE];
    char pass[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int port = 110;
    int fd;
    int bytes_read;

    printf("Enter POP3 server hostname: ");
    fgets(host, BUFFER_SIZE, stdin);
    host[strcspn(host, "\n")] = '\0';

    printf("Enter username: ");
    fgets(user, BUFFER_SIZE, stdin);
    user[strcspn(user, "\n")] = '\0';

    printf("Enter password: ");
    fgets(pass, BUFFER_SIZE, stdin);
    pass[strcspn(pass, "\n")] = '\0';

    snprintf(command, BUFFER_SIZE, "USER %s\r\n", user);
    send(fd, command, strlen(command), 0);

    bytes_read = recv(fd, response, BUFFER_SIZE, 0);
    response[bytes_read] = '\0';

    if (strncmp(response, "+OK", 4)!= 0) {
        printf("Authentication failed.\n");
        close(fd);
        return 1;
    }

    snprintf(command, BUFFER_SIZE, "PASS %s\r\n", pass);
    send(fd, command, strlen(command), 0);

    bytes_read = recv(fd, response, BUFFER_SIZE, 0);
    response[bytes_read] = '\0';

    if (strncmp(response, "+OK", 4)!= 0) {
        printf("Authentication failed.\n");
        close(fd);
        return 1;
    }

    snprintf(command, BUFFER_SIZE, "STAT\r\n");
    send(fd, command, strlen(command), 0);

    bytes_read = recv(fd, response, BUFFER_SIZE, 0);
    response[bytes_read] = '\0';

    printf("Message count: %s\n", response);

    close(fd);
    return 0;
}