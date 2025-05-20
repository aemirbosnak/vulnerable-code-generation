//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_usage(char* program_name) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", program_name);
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            printf("%d - Closed\n", i);
        } else {
            printf("%d - Open\n", i);
            close(sock);
        }
    }

    close(sock);
    return 0;
}