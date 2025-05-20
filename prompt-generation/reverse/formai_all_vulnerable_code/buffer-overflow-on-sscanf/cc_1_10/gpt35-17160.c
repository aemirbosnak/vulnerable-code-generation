//FormAI DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void scan_ports(unsigned char *ip_address, int start_port, int end_port);

int main(){
    printf("\n\tC Port Scanner Example Program\n\n");

    char target_ip[16];
    int start_port, end_port;

    printf("Enter IP Address: ");
    scanf("%s", target_ip);

    printf("Enter starting port number: ");
    scanf("%d", &start_port);

    printf("Enter ending port number: ");
    scanf("%d", &end_port);

    printf("\nScanning...\n");

    unsigned char *ip_address = (unsigned char *)malloc(4 * sizeof(unsigned char));
    sscanf(target_ip, "%hhu.%hhu.%hhu.%hhu", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    scan_ports(ip_address, start_port, end_port);

    free(ip_address);

    printf("\n\nPort scanning complete!");

    return 0;
}

void scan_ports(unsigned char *ip_address, int start_port, int end_port){
    int sockfd, connfd, port_number;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    bool is_open;

    for(port_number = start_port; port_number <= end_port; port_number++){
        is_open = false;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd == -1){
            printf("\nError: Could not create socket.");
            exit(EXIT_FAILURE);
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip_address);
        addr.sin_port = htons(port_number);

        if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1){
            is_open = false;
        } else {
            is_open = true;
            close(sockfd);
        }

        if(is_open){
            printf("\nPort %d is open.", port_number);
        }
    }
}