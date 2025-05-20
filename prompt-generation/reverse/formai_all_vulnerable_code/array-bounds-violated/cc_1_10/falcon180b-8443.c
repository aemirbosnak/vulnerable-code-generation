//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <netdb.h>

#define BUFLEN 1024
#define QOS_PORT 5000
#define QOS_IP "127.0.0.1"
#define QOS_INTERVAL 5 //seconds

int main() {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd;
    char buffer[BUFLEN];
    int n;
    int qos_level = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(QOS_IP);

    if (host == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(QOS_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        n = recv(sockfd, buffer, BUFLEN, 0);

        if (n <= 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        buffer[n] = '\0';
        printf("QoS level: %s\n", buffer);

        if (strcmp(buffer, "high") == 0) {
            qos_level = 1;
        } else if (strcmp(buffer, "medium") == 0) {
            qos_level = 0;
        } else if (strcmp(buffer, "low") == 0) {
            qos_level = -1;
        }

        if (qos_level!= 0) {
            char qos_cmd[50];
            sprintf(qos_cmd, "sudo tc qdisc add dev eth0 root handle 1: cbq avpkt 1000 bandwidth 10mbit burst 15kbit");
            system(qos_cmd);
        }

        sleep(QOS_INTERVAL);
    }

    close(sockfd);

    return 0;
}