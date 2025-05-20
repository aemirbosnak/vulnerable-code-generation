//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define QOS_PORT 8080

struct sockaddr_in server_addr;
int sock = 0;

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int connect_to_server() {
    struct hostent *server;
    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        error_handling("No such host");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(QOS_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("connect failed");
    }

    return 0;
}

int send_data(char *data, int size) {
    if (send(sock, data, size, 0) < 0) {
        error_handling("send failed");
    }

    return 0;
}

int recv_data(char *buffer, int size) {
    if (recv(sock, buffer, size, 0) < 0) {
        error_handling("recv failed");
    }

    return 0;
}

int main(int argc, char **argv) {
    char data[MAX_DATA_SIZE];
    int size = 0;

    if (connect_to_server() < 0) {
        return 1;
    }

    while (1) {
        memset(data, 0, MAX_DATA_SIZE);
        size = recv_data(data, MAX_DATA_SIZE);

        if (size > 0) {
            printf("Received data: %s\n", data);
        } else {
            printf("Connection closed\n");
            break;
        }
    }

    close(sock);
    return 0;
}