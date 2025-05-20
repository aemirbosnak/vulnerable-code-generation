//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./ping <IP address> <number of pings>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int num_pings = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip_address);

    char data[MAX_DATA_SIZE];
    memset(data, 0, MAX_DATA_SIZE);
    strcpy(data, "PING");

    for (int i = 0; i < num_pings; i++) {
        sendto(sock, data, strlen(data), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        int bytes_received = recv(sock, data, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        char *response = strstr(data, "PING");
        if (response == NULL) {
            printf("No response received\n");
        } else {
            printf("Response received\n");
        }
    }

    close(sock);
    return 0;
}