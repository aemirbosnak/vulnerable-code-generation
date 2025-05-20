//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ifaddrs.h>

#define MAX_DEVICES 1000
#define MAX_NAME_LENGTH 256

typedef struct {
    struct in_addr ip_address;
    char device_name[MAX_NAME_LENGTH];
} Device;

int main() {
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    struct ifaddrs *ifap, *ifa;
    if (getifaddrs(&ifap) == -1) {
        printf("Error getting interface addresses\n");
        exit(1);
    }

    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr != NULL && ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *sa = (struct sockaddr_in*) ifa->ifa_addr;
            char* hostname = malloc(MAX_NAME_LENGTH);
            
            if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), hostname, MAX_NAME_LENGTH, NULL, 0, 0) == 0) {
                Device device = { sa->sin_addr, hostname };
                devices[num_devices++] = device;
            }

            free(hostname);
        }
    }

    int num_rows = num_devices + 2;
    int num_cols = num_devices + 2;
    char topology_map[num_rows][num_cols];

    // Add device names to topology map
    int row = 0, col = 2;
    for (int i = 0; i < num_devices; i++) {
        Device device = devices[i];
        strncpy(topology_map[row++]+col, device.device_name, strlen(device.device_name));
    }

    // Add IP addresses to topology map
    row = 1, col = 2;
    for (int i = 0; i < num_devices; i++) {
        Device device = devices[i];
        char* ip_address_str = inet_ntoa(device.ip_address);
        strncpy(topology_map[row++]+col, ip_address_str, strlen(ip_address_str));
    }

    // Add labels
    strcpy(topology_map[0]+2, "Device");
    strcpy(topology_map[1]+2, "IP Address");
    for (int i = 0; i < num_rows-2; i++) {
        topology_map[i+2][0] = i + 'A';
        topology_map[i+2][1] = ':';
    }

    // Print topology map
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (topology_map[i][j] == '\0') {
                printf("  ");
            } else {
                printf("%c ", topology_map[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}