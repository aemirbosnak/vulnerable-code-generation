//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_PORT_LEN 16
#define MAX_DATA_LEN 1024

struct sockaddr_in server_addr;
int sockfd;

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <hostname> <port> <QoS_level> <data_size>\n", argv[0]);
        exit(1);
    }

    strcpy(server_addr.sin_zero, "");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    int qos_level = atoi(argv[3]);
    int data_size = atoi(argv[4]);

    char *data = malloc(data_size);
    if (data == NULL) {
        printf("Error: Failed to allocate memory for data\n");
        exit(1);
    }

    memset(data, 'A', data_size);

    if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char *)&qos_level, sizeof(qos_level)) == -1) {
        printf("Error: Failed to set QoS level\n");
        exit(1);
    }

    if (send(sockfd, data, data_size, 0)!= data_size) {
        printf("Error: Failed to send data\n");
        exit(1);
    }

    if (recv(sockfd, data, data_size, 0)!= data_size) {
        printf("Error: Failed to receive data\n");
        exit(1);
    }

    close(sockfd);

    printf("Data sent and received successfully\n");

    return 0;
}