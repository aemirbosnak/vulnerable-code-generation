//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

void scan_ports(int sock, char* ip, int start_port, int end_port)
{
    int i;
    struct sockaddr_in target;
    int opt = 1;
    char buffer[1024];

    for (i = start_port; i <= end_port; i++) {
        target.sin_family = AF_INET;
        target.sin_port = htons(i);
        inet_pton(AF_INET, ip, &target.sin_addr);

        if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
        } else {
            printf("Port %d is closed\n", i);
        }
    }
}

int main()
{
    char* ip;
    int start_port, end_port;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter start port: ");
    scanf("%d", &start_port);

    printf("Enter end port: ");
    scanf("%d", &end_port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    scan_ports(sock, ip, start_port, end_port);

    close(sock);

    return 0;
}