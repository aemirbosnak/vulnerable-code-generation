//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE_LEN 1024

void fatal(const char* msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    char* server = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fatal("Could not create socket");
    }

    struct hostent* host = gethostbyname(server);
    if (host == NULL) {
        fatal("Could not resolve host");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(110);
    addr.sin_addr.s_addr = *(unsigned long*)host->h_addr;

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        fatal("Could not connect to server");
    }

    char* auth = malloc(strlen(username) + strlen(password) + 2);
    sprintf(auth, "%s %s", username, password);
    auth[strlen(auth)-1] = '\r';
    auth[strlen(auth)] = '\n';

    send(sock, auth, strlen(auth), 0);
    free(auth);

    char buffer[MAX_LINE_LEN];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        if (recv(sock, buffer, sizeof(buffer), 0) <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}