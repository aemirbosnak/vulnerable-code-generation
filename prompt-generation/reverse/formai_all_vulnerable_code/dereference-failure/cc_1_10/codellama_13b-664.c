//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
/*
 *  Port Scanner - Post-Apocalyptic Edition
 *  By: Anonymous
 *
 *  This program is designed to scan for open ports on a target host
 *  in a post-apocalyptic style. It uses a customized language
 *  and aesthetic to make it feel more like a survival guide.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_START 1024
#define PORT_END 65535
#define BUFFER_SIZE 1024

struct hostent *host;
struct sockaddr_in server_addr;

void scan_ports(char *hostname, int port_start, int port_end) {
    int sock, n, i;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_start);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    for (i = port_start; i <= port_end; i++) {
        printf("[*] Scanning port %d\n", i);
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("[!] Port %d is closed.\n", i);
        } else {
            printf("[!] Port %d is open.\n", i);
            close(sock);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: portscan <hostname>\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    scan_ports(host->h_name, PORT_START, PORT_END);
    return 0;
}