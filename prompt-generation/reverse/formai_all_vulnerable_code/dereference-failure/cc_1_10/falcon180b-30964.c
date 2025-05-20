//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 10240
#define IMAP_PORT 143

void usage() {
    printf("Usage: imap_client <server> <username> <password>\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        usage();
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct hostent *server_info = gethostbyname(server);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *login_command = "LOGIN ";
    strcat(login_command, username);
    strcat(login_command, " ");
    strcat(login_command, password);

    send(server_socket, login_command, strlen(login_command), 0);

    char response[MAX_RESPONSE_LENGTH];
    memset(response, 0, MAX_RESPONSE_LENGTH);

    int bytes_received = recv(server_socket, response, MAX_RESPONSE_LENGTH, 0);

    printf("Response: %s\n", response);

    close(server_socket);

    return 0;
}