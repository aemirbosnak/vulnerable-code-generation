//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        perror("gethostbyname");
        close(sock);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char buf[1024];
    int len;

    len = read(sock, buf, sizeof(buf) - 1);
    if (len == -1) {
        perror("read");
        close(sock);
        return 1;
    }
    buf[len] = '\0';

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    len = write(sock, buf, strlen(buf));
    if (len == -1) {
        perror("write");
        close(sock);
        return 1;
    }

    len = read(sock, buf, sizeof(buf) - 1);
    if (len == -1) {
        perror("read");
        close(sock);
        return 1;
    }
    buf[len] = '\0';

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    len = write(sock, buf, strlen(buf));
    if (len == -1) {
        perror("write");
        close(sock);
        return 1;
    }

    len = read(sock, buf, sizeof(buf) - 1);
    if (len == -1) {
        perror("read");
        close(sock);
        return 1;
    }
    buf[len] = '\0';

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "LIST\r\n");
    len = write(sock, buf, strlen(buf));
    if (len == -1) {
        perror("write");
        close(sock);
        return 1;
    }

    len = read(sock, buf, sizeof(buf) - 1);
    if (len == -1) {
        perror("read");
        close(sock);
        return 1;
    }
    buf[len] = '\0';

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    len = write(sock, buf, strlen(buf));
    if (len == -1) {
        perror("write");
        close(sock);
        return 1;
    }

    close(sock);

    return 0;
}