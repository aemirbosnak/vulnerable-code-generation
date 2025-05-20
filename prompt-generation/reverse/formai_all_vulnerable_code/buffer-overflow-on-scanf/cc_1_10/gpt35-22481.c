//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT_MIN 1024
#define PORT_MAX 65535

/* function for scanning ports */
void scan_ports(char *ip, int start_port, int end_port) {
    int sockfd, connfd, port_num;
    struct sockaddr_in serv_addr;

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    /* iterate through ports */
    for (port_num = start_port; port_num <= end_port; port_num++) {
        /* set server address */
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(ip);
        serv_addr.sin_port = htons(port_num);

        /* attempt to connect to port */
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            /* display open port */
            printf("Port %d is open\n", port_num);
        }

        /* close connection */
        close(sockfd);
        /* create new socket for next iteration */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
    }

    /* close socket */
    close(sockfd);
}

int main() {
    char ip[16];
    int start_port, end_port;

    /* ask for IP address to scan */
    printf("Enter IP address to scan: ");
    scanf("%s", ip);

    /* ask for starting port */
    printf("Enter starting port: ");
    scanf("%d", &start_port);

    /* ask for ending port */
    printf("Enter ending port: ");
    scanf("%d", &end_port);

    /* validate port range */
    if (start_port < PORT_MIN || end_port > PORT_MAX || start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    /* scan ports */
    scan_ports(ip, start_port, end_port);

    return 0;
}