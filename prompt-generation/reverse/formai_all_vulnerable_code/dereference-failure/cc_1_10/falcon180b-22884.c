//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int is_valid_ip(char *ip);
void scan_port(char *ip, int port);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 1;

    if (!is_valid_ip(ip)) {
        printf("Invalid IP Address!\n");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        scan_port(ip, i);
    }

    return 0;
}

int is_valid_ip(char *ip) {
    int count = 0;
    char *token = strtok(ip, ".");

    while (token!= NULL) {
        if (atoi(token) < 0 || atoi(token) > 255) {
            return FALSE;
        }

        count++;
        token = strtok(NULL, ".");
    }

    if (count!= 4) {
        return FALSE;
    }

    return TRUE;
}

void scan_port(char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Port %d is closed!\n", port);
    } else {
        printf("Port %d is open!\n", port);
        close(sock);
    }
}