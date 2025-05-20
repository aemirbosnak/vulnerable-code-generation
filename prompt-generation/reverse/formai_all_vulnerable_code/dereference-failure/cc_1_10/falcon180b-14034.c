//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port_num, bytes_sent, bytes_recv;
    struct sockaddr_in target;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    strcpy(buffer, "GET / HTTP/1.1\r\nHost:\r\n\r\n");

    for (port_num = atoi(argv[2]); port_num <= MAX_PORTS; port_num++) {
        bzero(&target, sizeof(target));
        target.sin_family = AF_INET;
        target.sin_port = htons(port_num);
        inet_pton(AF_INET, argv[1], &target.sin_addr);

        bytes_sent = sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr *)&target, sizeof(target));
        if (bytes_sent == -1) {
            printf("Error sending request to port %d\n", port_num);
        } else {
            printf("Request sent to port %d\n", port_num);
        }

        bzero(buffer, BUFFER_SIZE);
        bytes_recv = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_recv > 0) {
            printf("Response received from port %d:\n%s", port_num, buffer);
        } else {
            printf("No response received from port %d\n", port_num);
        }
    }

    close(sock);
    return 0;
}