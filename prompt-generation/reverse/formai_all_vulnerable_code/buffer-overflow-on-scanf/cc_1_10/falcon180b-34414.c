//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define BUF_SIZE 1024

// Function to scan for wireless networks
void scan_wireless_networks(int sock) {
    char buf[BUF_SIZE];
    int i = 0;
    while (i < MAX_DEVICES) {
        memset(buf, 0, BUF_SIZE);
        snprintf(buf, BUF_SIZE, "iwlist wlan0 scan | grep ESSID | awk '{print $2}'");
        system(buf);
        if (fgets(buf, BUF_SIZE, stdin)!= NULL) {
            printf("Wireless Network %d: %s\n", i+1, buf);
            i++;
        } else {
            break;
        }
    }
}

// Function to connect to a wireless network
void connect_to_network(int sock, char* essid, char* key) {
    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "iwconfig wlan0 essid %s key %s", essid, key);
    system(buf);
    printf("Connected to wireless network %s\n", essid);
}

int main(int argc, char* argv[]) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    scan_wireless_networks(sock);

    int choice;
    char essid[50];
    char key[50];

    printf("Enter the number of the wireless network you want to connect to: ");
    scanf("%d", &choice);

    printf("Enter the ESSID of the wireless network: ");
    scanf("%s", essid);

    printf("Enter the key of the wireless network: ");
    scanf("%s", key);

    connect_to_network(sock, essid, key);

    close(sock);

    return 0;
}