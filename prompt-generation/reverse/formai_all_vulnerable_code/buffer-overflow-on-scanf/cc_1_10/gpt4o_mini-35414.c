//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_DEVICES 100
#define DEVICE_NAME_LEN 50
#define MAX_IP_LEN 16

typedef struct Device {
    char name[DEVICE_NAME_LEN];
    char ip_address[MAX_IP_LEN];
} Device;

Device networkDevices[MAX_DEVICES];
int deviceCount = 0;

int add_device(const char* name, const char* ip) {
    if (deviceCount >= MAX_DEVICES) {
        fprintf(stderr, "Device limit reached. Cannot add more devices!\n");
        return -1;
    }
    strcpy(networkDevices[deviceCount].name, name);
    strcpy(networkDevices[deviceCount].ip_address, ip);
    deviceCount++;
    return 0;
}

void display_network_map() {
    printf("Network Topology Map:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("Device %d: %s (%s)\n", i + 1, networkDevices[i].name, networkDevices[i].ip_address);
    }
}

void scan_network(const char* subnet) {
    char command[100];
    snprintf(command, sizeof(command), "nmap -sn %s/24", subnet);
    printf("Scanning network: %s. Please wait...\n", subnet);
    
    if (system(command) == -1) {
        fprintf(stderr, "Error scanning the network. Permissions might be insufficient.\n");
    }
}

int validate_ip(const char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

void paranoid_input(char* input, int length) {
    printf("Enter Device Name (max %d characters): ", length - 1);
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline
}

void paranoid_ip_input(char* ip, int length) {
    do {
        printf("Enter Device IP Address (xxx.xxx.xxx.xxx): ");
        fgets(ip, length, stdin);
        ip[strcspn(ip, "\n")] = '\0'; // remove trailing newline
    } while (!validate_ip(ip));
}

int main() {
    char deviceName[DEVICE_NAME_LEN];
    char deviceIp[MAX_IP_LEN];
    
    printf("Welcome to the paranoid C Network Topology Mapper!\n");

    while (1) {
        printf("Options:\n");
        printf("1. Add Device\n");
        printf("2. Display Network Map\n");
        printf("3. Scan Network\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // clear the newline left by scanf

        switch (choice) {
            case 1:
                paranoid_input(deviceName, DEVICE_NAME_LEN);
                paranoid_ip_input(deviceIp, MAX_IP_LEN);
                if (add_device(deviceName, deviceIp) == 0) {
                    printf("Device added successfully!\n");
                }
                break;
            case 2:
                display_network_map();
                break;
            case 3:
                {
                    char subnet[MAX_IP_LEN];
                    printf("Enter subnet to scan (e.g., 192.168.1): ");
                    fgets(subnet, sizeof(subnet), stdin);
                    subnet[strcspn(subnet, "\n")] = '\0'; // remove trailing newline
                    scan_network(subnet);
                }
                break;
            case 4:
                printf("Exiting the paranoid program!\n");
                exit(0);
            default:
                printf("Invalid option! Choose wisely...\n");
        }
    }

    return 0;
}