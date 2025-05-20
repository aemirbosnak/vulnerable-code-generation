//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    char host[256], buf[256];
    struct hostent *h;
    struct in_addr **addr_list;
    int sock, i, n;

    printf("Enter the hostname or IP address to ping: ");
    scanf("%s", host);

    h = gethostbyname(host);
    if (h == NULL) {
        printf("Host not found\n");
        return 1;
    }

    addr_list = (struct in_addr **)h->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++) {
        printf("Pinging %s...\n", inet_ntoa(*addr_list[i]));

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Socket creation failed\n");
            return 1;
        }

        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr = *addr_list[i];
        sin.sin_port = htons(80);

        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
            printf("Connection failed\n");
            return 1;
        }

        printf("Connection established\n");

        n = read(sock, buf, sizeof(buf));
        if (n < 0) {
            printf("Read failed\n");
            return 1;
        }

        printf("Received %d bytes from %s\n", n, inet_ntoa(*addr_list[i]));
        printf("Data: %s\n", buf);

        close(sock);
    }

    return 0;
}