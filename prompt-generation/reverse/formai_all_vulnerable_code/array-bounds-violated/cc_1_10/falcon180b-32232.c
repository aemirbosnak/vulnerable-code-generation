//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <SSID>\n", argv[0]);
        exit(1);
    }

    char *ssid = argv[1];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in si_other;
    memset(&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(9);

    if (inet_pton(AF_INET, "255.255.255.255", &si_other.sin_addr) <= 0) {
        printf("Error converting IP address\n");
        exit(1);
    }

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", ssid);

    if (sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&si_other, sizeof(si_other)) == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    char response[BUF_SIZE];
    int len = recv(sock, response, BUF_SIZE, 0);
    if (len <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[len] = '\0';
    printf("Response:\n%s\n", response);

    close(sock);
    return 0;
}