//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct sockaddr_in addr;
    int sock, n;
    char buf[1024];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error: could not connect to host\n");
        exit(1);
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("ftp> ");
        fgets(buf, sizeof(buf), stdin);
        if (buf[0] == '\n') {
            continue;
        }
        if (strncmp(buf, "quit", 4) == 0) {
            break;
        }
        n = strlen(buf);
        if (buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
        }
        if (write(sock, buf, n) < 0) {
            fprintf(stderr, "Error: could not write to socket\n");
            exit(1);
        }
        n = read(sock, buf, sizeof(buf));
        if (n < 0) {
            fprintf(stderr, "Error: could not read from socket\n");
            exit(1);
        }
        printf("%s\n", buf);
    }

    close(sock);
    return 0;
}