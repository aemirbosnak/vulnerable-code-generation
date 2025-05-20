//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    struct hostent *host = gethostbyname(server);
    if (!host) {
        fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    addr.sin_port = htons(POP3_PORT);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[1024];
    int n;

    // Read server greeting
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send username
    sprintf(buf, "USER %s\r\n", username);
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send password
    sprintf(buf, "PASS %s\r\n", password);
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send QUIT command
    strcpy(buf, "QUIT\r\n");
    n = send(sock, buf, strlen(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    close(sock);
    return EXIT_SUCCESS;
}