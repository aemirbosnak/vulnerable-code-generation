//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define PORT 21

char hostname[64];
int port;
char username[64];
char password[64];
char filename[256];
char ftp_command[256];
char response[1024];

int main(int argc, char *argv[]) {
    printf("FTP Client\n");

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number (default 21): ");
    if (scanf("%d", &port)!= 1) {
        port = PORT;
    }

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter filename to retrieve: ");
    scanf("%s", filename);

    sprintf(ftp_command, "USER %s\r\n", username);
    send(ftp_command, strlen(ftp_command), 0);

    sprintf(ftp_command, "PASS %s\r\n", password);
    send(ftp_command, strlen(ftp_command), 0);

    sprintf(ftp_command, "RETR %s\r\n", filename);
    send(ftp_command, strlen(ftp_command), 0);

    while (1) {
        memset(response, 0, sizeof(response));
        int bytes_received = recv(response, sizeof(response), 0);

        if (bytes_received <= 0) {
            break;
        }

        response[bytes_received - 1] = '\0';
        printf("%s", response);
    }

    return 0;
}