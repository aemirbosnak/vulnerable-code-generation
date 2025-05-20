//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "80"

void scan_network(char* network, char* mask) {
    struct sockaddr_in address;
    struct hostent* host;
    int sock;
    char ip[16];
    int i;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Could not create socket\n");
        return;
    }

    for (i = 1; i < 256; i++) {
        sprintf(ip, "%d.%d.%d.%d", (i & 0xff), ((i >> 8) & 0xff), ((i >> 16) & 0xff), ((i >> 24) & 0xff));

        if (inet_aton(ip, &address.sin_addr) == 0) {
            continue;
        }

        address.sin_family = AF_INET;
        address.sin_port = htons(atoi(PORT));

        if (connect(sock, (struct sockaddr*)&address, sizeof(address)) == 0) {
            host = gethostbyaddr((char*)&address.sin_addr, sizeof(address.sin_addr), AF_INET);

            if (host == NULL) {
                printf("Host not found: %s\n", inet_ntoa(address.sin_addr));
            } else {
                printf("Host found: %s\n", host->h_name);
            }
        } else {
            printf("Connection refused: %s\n", inet_ntoa(address.sin_addr));
        }
    }

    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <network> <mask>\n", argv[0]);
        return 1;
    }

    scan_network(argv[1], argv[2]);

    return 0;
}