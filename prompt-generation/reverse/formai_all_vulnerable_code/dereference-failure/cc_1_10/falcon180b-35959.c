//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define PORT 7

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int data_len;
    int ret;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);
    strncpy(data, argv[2], MAX_DATA - 1);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error: socket() failed with error %d\n", errno);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Error: inet_pton() failed\n");
        close(sock);
        return 1;
    }

    data_len = strlen(data);
    ret = sendto(sock, data, data_len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: sendto() failed with error %d\n", errno);
        close(sock);
        return 1;
    }

    ret = recvfrom(sock, data, MAX_DATA, 0, NULL, NULL);
    if (ret == -1) {
        printf("Error: recvfrom() failed with error %d\n", errno);
        close(sock);
        return 1;
    }

    printf("Received %d bytes of data:\n%s\n", ret, data);

    close(sock);
    return 0;
}