//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 65535
#define PORTNUM 8000

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock, fd, n;
    char file_name[MAX];
    char buf[MAX];
    struct sockaddr_in serv_addr;

    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(PORTNUM);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    printf("Enter file name: ");
    scanf("%s", file_name);

    write(sock, file_name, strlen(file_name));
    read(sock, buf, MAX);

    if (!strcmp(buf, "OK")) {
        fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);

        while ((n = read(sock, buf, MAX)) > 0) {
            write(fd, buf, n);
        }

        close(fd);

        printf("Download complete.\n");
    } else if (!strcmp(buf, "NO")) {
        printf("File not found.\n");
    }

    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}