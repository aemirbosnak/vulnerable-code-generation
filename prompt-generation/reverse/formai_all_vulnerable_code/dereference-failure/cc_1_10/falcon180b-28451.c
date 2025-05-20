//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 25
#define MAX_LINE 1024
#define BUFFER_SIZE 4096

void send_command(int sock, char* cmd) {
    write(sock, cmd, strlen(cmd));
    write(sock, "\r\n", 2);
}

void read_response(int sock, char* buffer) {
    char* line = buffer;
    int len = 0;
    while ((len < BUFFER_SIZE - 1) && (line = strchr(line, '\n'))) {
        *line = '\0';
        len += strlen(buffer);
        line++;
        strcat(buffer, line);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <file>\n", argv[0]);
        return 1;
    }

    char* server = argv[1];
    char* filename = argv[2];
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: socket() failed\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connect() failed\n");
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        close(sock);
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        line[read - 1] = '\0';
        send_command(sock, line);
        read_response(sock, buffer);
        printf("%s", buffer);
    }

    free(line);
    fclose(fp);
    close(sock);
    return 0;
}