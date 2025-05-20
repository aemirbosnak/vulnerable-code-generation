//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <file>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    char *file = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        die("socket");

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        die("connect");

    char buf[BUFFER_SIZE];
    FILE *fp = fopen(file, "rb");
    if (!fp)
        die("fopen");

    while (fgets(buf, BUFFER_SIZE, fp)!= NULL) {
        send(sock, buf, strlen(buf), 0);
    }

    fclose(fp);
    close(sock);

    return 0;
}