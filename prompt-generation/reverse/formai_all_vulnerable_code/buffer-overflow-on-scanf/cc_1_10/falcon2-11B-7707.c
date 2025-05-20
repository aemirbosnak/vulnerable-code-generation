//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to scan ports
int port_scan(int port, char *host) {
    int sockfd, valread, n;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        printf("ERROR with address\n");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting to port %d\n", port);
        return -1;
    }

    printf("Port %d is open\n", port);

    valread = recv(sockfd, &n, sizeof(n), 0);
    printf("Received %d bytes\n", n);

    close(sockfd);
    return 0;
}

int main() {
    char host[100];
    int port;

    printf("Enter the host name or IP address: ");
    scanf("%s", host);

    printf("Enter the port number to scan: ");
    scanf("%d", &port);

    port_scan(port, host);

    return 0;
}