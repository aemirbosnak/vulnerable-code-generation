//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define MAX 100

// Function to convert IP address from integer to string
void ipToString(int ip, char str[16]) {
    sprintf(str, "%d.%d.%d.%d", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

// Function to scan wireless networks
void scanWirelessNetworks() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in si_other;
    char buffer[4096];
    char ssid[33];
    int len, i;

    if (sock == -1) {
        printf("socket failed\n");
        exit(1);
    }

    memset(&si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(33434);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&si_other, &len);
        if (len > 0) {
            printf("Received %d bytes\n", len);
            for (i = 0; i < len; i++) {
                if (buffer[i] == 0x1B) {
                    memcpy(ssid, &buffer[i + 1], 32);
                    ssid[32] = '\0';
                    printf("SSID: %s\n", ssid);
                }
            }
        }
    }

    close(sock);
}

int main() {
    int choice;

    do {
        printf("1. Scan wireless networks\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanWirelessNetworks();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (TRUE);

    return 0;
}