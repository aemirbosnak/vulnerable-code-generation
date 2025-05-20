//FormAI DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAX_PORTS 65535

void print_banner() {
    printf("\n\n8888888b.           888       888 8888888\n");
    printf("888  %sY88b          888   o   888   888\n", "88");
    printf("888    888          888  d8b  888   888\n");
    printf("888    888  .d88b.  888 d888b 888   888\n");
    printf("888    888 d88''88b 888d88888b888   888\n");
    printf("888    888 888  888 88888P Y88888   888\n");
    printf("888  .d88P Y88..88P 8888P   Y8888   888\n");
    printf("8888888P'   'Y88P'  888P     Y888 8888888\n\n\n");
    printf("Post-apocalyptic Port Scanner - Detecting Survivors or Thieves...\n\n\n");
}

void usage(char *prog) {
    printf("Usage: %s <IP address>\n", prog);
}

int main(int argc, char *argv[]) {
    int sock, i, scan_result, start_port, end_port;
    struct sockaddr_in target;
    char *ip_addr, banner[1024], response[4096], send_packet[1024], recv_packet[1024];

    print_banner();

    if (argc != 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    ip_addr = argv[1];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip_addr);

    printf("Enter start port number: ");
    scanf("%d", &start_port);
    printf("Enter end port number: ");
    scanf("%d", &end_port);

    printf("\nScanning ports %d to %d...\n\n", start_port, end_port);

    for (i = start_port; i <= end_port; i++) {
        memset(&send_packet, 0, sizeof(send_packet));
        memset(&recv_packet, 0, sizeof(recv_packet));
        scan_result = 0;

        target.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open!\n", i);
            scan_result = 1;
            if (recv(sock, banner, sizeof(banner), 0) > 0) {
                printf("Banner:\n%s\n", banner);
            }
            close(sock);
        }

        if (!scan_result) {
            printf("Port %d is closed.\n", i);
        }
    }

    printf("\nScan completed.\n");

    return 0;
}