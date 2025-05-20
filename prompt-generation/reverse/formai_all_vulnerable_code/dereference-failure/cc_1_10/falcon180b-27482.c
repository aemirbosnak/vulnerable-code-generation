//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT_NUMBER 65535
#define BUFFER_SIZE 1024

void print_usage(char *program_name) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", program_name);
}

int is_valid_port(int port_number) {
    if (port_number < 1 || port_number > MAX_PORT_NUMBER) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char ip_address[16];
    strcpy(ip_address, argv[1]);

    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port number(s)\n");
        return 1;
    }

    if (end_port < start_port) {
        printf("End port number must be greater than or equal to start port number\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "Scanning %s:%d - %d...\n", ip_address, start_port, end_port);
    printf("%s", buffer);

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            close(sock);
            sprintf(buffer, "Port %d is open\n", i);
            printf("%s", buffer);
        } else {
            sprintf(buffer, "Port %d is closed\n", i);
            printf("%s", buffer);
        }
    }

    close(sock);
    return 0;
}