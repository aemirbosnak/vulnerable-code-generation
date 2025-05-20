//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <net/if.h>
#include <ifaddrs.h>

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[100];
    char ssid[100];
    struct ifaddrs *ifaddr, *ifa;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    if (getifaddrs(&ifaddr) == -1) {
        fprintf(stderr, "Error getting network interfaces\n");
        return 1;
    }

    for (ifa = ifaddr; ifa!= NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        if (strcmp(argv[1], ifa->ifa_name) == 0) {
            break;
        }
    }

    if (ifa == NULL) {
        fprintf(stderr, "Interface %s not found\n", argv[1]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(521);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    strcpy(ssid, ifa->ifa_name);

    while (1) {
        if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
            fprintf(stderr, "Error receiving data\n");
            return 1;
        }

        printf("%s: %s\n", ssid, buffer);

        if (strcmp(buffer, "DONE") == 0) {
            break;
        }
    }

    close(sock);
    freeifaddrs(ifaddr);

    return 0;
}