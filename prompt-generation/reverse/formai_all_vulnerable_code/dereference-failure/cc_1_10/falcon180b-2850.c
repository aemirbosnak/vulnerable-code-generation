//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sock;
    struct hostent *host;
    struct sockaddr_in server;

    char username[50];
    char password[50];
    char command[50];

    int port = 110;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    host = gethostbyname(argv[1]);

    if (host == NULL) {
        printf("Error: Invalid server name.\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        if (strcasecmp(command, "USER") == 0) {
            sprintf(command, "USER %s\r\n", username);
        } else if (strcasecmp(command, "PASS") == 0) {
            sprintf(command, "PASS %s\r\n", password);
        } else if (strcasecmp(command, "QUIT") == 0) {
            sprintf(command, "QUIT\r\n");
        }

        send(sock, command, strlen(command), 0);

        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Error: Failed to receive data from server.\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}