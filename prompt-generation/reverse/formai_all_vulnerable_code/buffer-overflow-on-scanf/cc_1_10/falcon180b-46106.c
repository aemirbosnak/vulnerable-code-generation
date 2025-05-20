//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int sport;
    for (sport = start_port; sport <= end_port; sport++) {
        if (sport == 80) { // HTTP port
            printf("Port %d is open (HTTP)\n", sport);
        } else if (sport == 443) { // HTTPS port
            printf("Port %d is open (HTTPS)\n", sport);
        } else if (sport == 22) { // SSH port
            printf("Port %d is open (SSH)\n", sport);
        } else if (sport == 21) { // FTP port
            printf("Port %d is open (FTP)\n", sport);
        } else if (sport == 53) { // DNS port
            printf("Port %d is open (DNS)\n", sport);
        } else if (sport == 25) { // SMTP port
            printf("Port %d is open (SMTP)\n", sport);
        } else {
            printf("Port %d is closed\n", sport);
        }
    }
}

int main() {
    int sock, target_sock, target_ip, port;
    struct sockaddr_in server_addr, target_addr;
    char target_ip_str[16];
    printf("Enter the target IP address: ");
    scanf("%s", target_ip_str);
    target_ip = inet_addr(target_ip_str);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(sock, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Waiting for connection...\n");
    target_sock = accept(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));
    if (target_sock == -1) {
        printf("Error accepting connection\n");
        exit(1);
    }

    close(sock);

    printf("Connected to target IP: %s\n", inet_ntoa(target_addr.sin_addr));

    scan_ports(target_sock, target_addr.sin_addr.s_addr, 1, MAX_PORTS);

    close(target_sock);
    return 0;
}