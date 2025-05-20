//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_LINE_LEN 512
#define POP3_PORT 110
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main() {
    int sd, ret;
    struct sockaddr_in server_addr;
    char hostname[32];
    char line[MAX_LINE_LEN];
    char *p;
    struct hostent *host_ent;
    FILE *fp;
    time_t now;

    printf("Enter POP3 server hostname or IP address: ");
    scanf("%s", hostname);

    if ((host_ent = gethostbyname(hostname)) == NULL) {
        printf("Error: Invalid hostname or IP address.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host_ent->h_addr, host_ent->h_length);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    if (connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Failed to connect to server.\n");
        close(sd);
        return 1;
    }

    printf("Connected to server.\n");

    fp = fopen("pop3_response.txt", "w");
    if (fp == NULL) {
        printf("Error: Failed to open file for writing.\n");
        close(sd);
        return 1;
    }

    while (1) {
        fprintf(fp, "%s", "Client: ");
        fflush(fp);
        if (fgets(line, MAX_LINE_LEN, stdin) == NULL) {
            printf("Error: Failed to read input.\n");
            break;
        }
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == 'q') {
            fprintf(fp, "%s", "Server: +OK POP3 server signing off.\r\n");
            break;
        } else if (line[0] == 'u') {
            fprintf(fp, "%s", "Server: +OK\r\n");
        } else if (line[0] == 'p') {
            fprintf(fp, "%s", "Server: +OK\r\n");
        } else if (line[0] == 'd') {
            fprintf(fp, "%s", "Server: -ERR Invalid command.\r\n");
        } else {
            fprintf(fp, "%s", "Server: -ERR Invalid command.\r\n");
        }
    }

    fclose(fp);
    close(sd);

    return 0;
}