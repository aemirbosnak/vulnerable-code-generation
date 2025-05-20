//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_DEVICES 100
#define HOSTNAME_LEN 256

typedef struct {
    char hostname[HOSTNAME_LEN];
    struct sockaddr_in address;
} Device;

Device networkDevices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char *hostname, const char *ip) {
    if (deviceCount >= MAX_DEVICES) {
        fprintf(stderr, "Error: Maximum device limit reached.\n");
        return;
    }

    strcpy(networkDevices[deviceCount].hostname, hostname);
    inet_pton(AF_INET, ip, &networkDevices[deviceCount].address.sin_addr);
    networkDevices[deviceCount].address.sin_family = AF_INET;
    deviceCount++;
    printf("Added device: %s (%s)\n", hostname, ip);
}

void listDevices() {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device %d: %s, IP: %s\n", i + 1,
               networkDevices[i].hostname,
               inet_ntoa(networkDevices[i].address.sin_addr));
    }
}

int findDevice(const char *hostname) {
    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(networkDevices[i].hostname, hostname) == 0) {
            return i;
        }
    }
    return -1;
}

void removeDevice(const char *hostname) {
    int index = findDevice(hostname);
    if (index == -1) {
        printf("Device '%s' not found.\n", hostname);
        return;
    }
    
    for (int i = index; i < deviceCount - 1; i++) {
        networkDevices[i] = networkDevices[i + 1];
    }
    deviceCount--;
    printf("Removed device: %s\n", hostname);
}

void displayMenu() {
    printf("\nNetwork Topology Mapper\n");
    printf("1. Add Device\n");
    printf("2. List Devices\n");
    printf("3. Remove Device\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char hostname[HOSTNAME_LEN];
    char ip[16];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter hostname: ");
                scanf("%s", hostname);
                printf("Enter IP address: ");
                scanf("%s", ip);
                addDevice(hostname, ip);
                break;
            case 2:
                listDevices();
                break;
            case 3:
                printf("Enter hostname to remove: ");
                scanf("%s", hostname);
                removeDevice(hostname);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}