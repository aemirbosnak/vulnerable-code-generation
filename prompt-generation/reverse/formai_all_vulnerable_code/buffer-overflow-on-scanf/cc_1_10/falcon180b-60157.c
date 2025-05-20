//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void ftp_connect(char *host, int port) {
    struct hostent *he;
    struct sockaddr_in server;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Error: Unknown host\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(0, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Unable to connect\n");
        exit(1);
    }
}

int ftp_login(char *username, char *password) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "USER %s\r\n", username);
    send(0, buffer, strlen(buffer), 0);
    recv(0, buffer, BUFFER_SIZE, 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(0, buffer, strlen(buffer), 0);
    recv(0, buffer, BUFFER_SIZE, 0);

    if (strstr(buffer, "230")) {
        return 1;
    } else {
        return 0;
    }
}

void ftp_download(char *filename, int filesize) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    FILE *fp;

    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    while (bytes_received < filesize) {
        recv(0, buffer, BUFFER_SIZE, 0);
        fwrite(buffer, strlen(buffer), 1, fp);
        bytes_received += strlen(buffer);
    }

    fclose(fp);
    printf("Download complete\n");
}

int main(int argc, char *argv[]) {
    char hostname[256];
    char username[256];
    char password[256];
    char filename[256];
    int port;

    printf("FTP Client\n");
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port number: ");
    scanf("%d", &port);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter filename to download: ");
    scanf("%s", filename);

    ftp_connect(hostname, port);

    if (ftp_login(username, password)) {
        ftp_download(filename, 0);
    } else {
        printf("Login failed\n");
    }

    return 0;
}