//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define QOS_PRIORITY 0x80
#define QOS_MASK 0x7f

int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buf[BUF_SIZE];
    while (1) {
        memset(buf, 0, BUF_SIZE);
        int bytes_received = recv(sock, buf, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        char *token = strtok(buf, " ");
        int qos_priority = atoi(token);
        if (qos_priority == QOS_PRIORITY) {
            printf("QoS enabled\n");
        } else {
            printf("QoS disabled\n");
        }

        close(sock);
        break;
    }

    return 0;
}