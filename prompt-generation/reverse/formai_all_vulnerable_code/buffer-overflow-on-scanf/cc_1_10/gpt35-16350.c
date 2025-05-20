//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[BUFFER_SIZE], response[BUFFER_SIZE];
    char email[50], password[50];
    int i;

    // check command line arguments
    if (argc != 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(1);
    }

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // get user email and password
    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter password: ");
    scanf("%s", password);

    // send authentication
    sprintf(message, "USER %s\r\n", email);
    send(sock, message, strlen(message), 0);
    sprintf(message, "PASS %s\r\n", password);
    send(sock, message, strlen(message), 0);

    // check response
    recv(sock, response, BUFFER_SIZE, 0);
    if (strstr(response, "+OK") == NULL) {
        printf("Error authenticating user: %s\n", response);
        exit(1);
    }

    // list messages
    sprintf(message, "LIST\r\n");
    send(sock, message, strlen(message), 0);

    // print message list
    i = 0;
    while (1) {
        char *p;
        int message_no, message_size;

        // receive response
        recv(sock, response, BUFFER_SIZE, 0);

        // check for end of message list
        if (strcmp(response, ".\r\n") == 0) {
            break;
        }

        // parse message list entry
        p = strtok(response, " ");
        message_no = atoi(p);
        p = strtok(NULL, " ");
        message_size = atoi(p);

        printf("%d. %d bytes\n", message_no, message_size);

        i++;
    }

    // select message to download
    printf("Enter message number to download: ");
    scanf("%d", &i);

    // download message
    sprintf(message, "RETR %d\r\n", i);
    send(sock, message, strlen(message), 0);

    // print message
    while (1) {
        int n = recv(sock, response, BUFFER_SIZE, 0);
        if (n == 0) {
            // end of stream
            break;
        }
        fwrite(response, n, 1, stdout);
    }

    // close socket
    close(sock);

    return 0;
}