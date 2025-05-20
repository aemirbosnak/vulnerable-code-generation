//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024
#define TIMEOUT 5

int main(int argc, char *argv[])
{
    int sock = -1;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME_LEN];
    char data[MAX_DATA_LEN];
    int data_len;
    int timeout_ms = TIMEOUT * 1000;
    int ret;

    if (argc < 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("Error: socket() failed\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0)
    {
        printf("Error: Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: connect() failed\n");
        close(sock);
        return 1;
    }

    snprintf(data, MAX_DATA_LEN, "PING\r\n");
    send(sock, data, strlen(data), 0);

    memset(data, 0, MAX_DATA_LEN);
    data_len = recv(sock, data, MAX_DATA_LEN - 1, MSG_DONTWAIT);

    if (data_len <= 0)
    {
        printf("Error: No response from server\n");
        close(sock);
        return 1;
    }

    close(sock);

    if (strstr(data, "PONG") == NULL)
    {
        printf("Error: Invalid response from server\n");
        return 1;
    }

    printf("Server is alive\n");

    return 0;
}