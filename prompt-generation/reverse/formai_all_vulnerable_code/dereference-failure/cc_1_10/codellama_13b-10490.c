//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_SERVERS 5
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_names[MAX_SERVERS] = {
        "speedtest.wdc01.softlayer.com",
        "speedtest.wdc02.softlayer.com",
        "speedtest.wdc03.softlayer.com",
        "speedtest.wdc04.softlayer.com",
        "speedtest.wdc05.softlayer.com"
    };

    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *message = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    char buf[BUF_SIZE];
    int bytes_sent, bytes_received;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s <server_name>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < MAX_SERVERS; i++) {
        if (strcmp(argv[1], server_names[i]) == 0) {
            break;
        }
    }

    if (i == MAX_SERVERS) {
        printf("Invalid server name\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname(server_names[i]);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        close(sock);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sock);
        return 1;
    }

    bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("Error sending message");
        close(sock);
        return 1;
    }

    bytes_received = recv(sock, buf, BUF_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving message");
        close(sock);
        return 1;
    }

    printf("Bytes sent: %d\nBytes received: %d\n", bytes_sent, bytes_received);

    close(sock);

    return 0;
}