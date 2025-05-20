//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <unistd.h>

void list_devices() {
    // Define variables needed for scanning
    struct if_nameindex *if_list;
    struct if_nameindex *if_name;
    struct ifreq ifr;
    int sock;
    int i;
    int len;

    // Get a list of available network devices
    if_list = if_nameindex();

    printf("Available network devices: \n");

    // Iterate through the list of devices and print them out
    for(if_name = if_list; if_name->if_index != 0 || if_name->if_name != NULL; if_name++) {
        printf("%s\n", if_name->if_name);
    }

    // Free the list of devices to prevent memory leaks
    if_freenameindex(if_list);
}

void scan_network(char* device) {
    // Define variables needed for scanning
    char subnet[16];
    struct in_addr ip;
    struct in_addr netmask;
    struct in_addr network;
    struct in_addr host;
    struct ifreq ifr;
    int sock;
    int i;
    int len;

    // Get the IP address of the device to scan from
    sock = socket(AF_INET, SOCK_STREAM, 0);
    strncpy(ifr.ifr_name, device, IFNAMSIZ-1);
    ioctl(sock, SIOCGIFADDR, &ifr);
    close(sock);
    ip = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr;

    // Get the netmask of the device to scan from
    sock = socket(AF_INET, SOCK_STREAM, 0);
    strncpy(ifr.ifr_name, device, IFNAMSIZ-1);
    ioctl(sock, SIOCGIFNETMASK, &ifr);
    close(sock);
    netmask = ((struct sockaddr_in *)&ifr.ifr_netmask)->sin_addr;

    // Calculate the network address and the number of hosts in the network
    network.s_addr = ip.s_addr & netmask.s_addr;
    len = 32 - __builtin_popcount(netmask.s_addr);

    printf("Network address: %s\n", inet_ntoa(network));
    printf("Number of hosts: %u\n", (1 << len) - 2);

    // Scan each host in the network
    for(i = 1; i < (1 << len) - 1; i++) {
        host.s_addr = network.s_addr | htonl(i);
        snprintf(subnet, sizeof(subnet), "%s/%u", inet_ntoa(host), len);
        printf("Scanning host: %s\n", inet_ntoa(host));
        system(subnet); // Run nmap command to check for open ports on the host
    }
}

int main() {
    // Define variables needed for user input
    int option;
    char device[IFNAMSIZ];

    // Ask the user to enter a device name or list available devices
    printf("Enter the name of the device you want to scan or enter 0 to list available devices: ");
    scanf("%s", device);

    // If the user enters 0, list available devices
    if(strcmp(device, "0") == 0) {
        list_devices();
        return 0;
    }

    // Validate the device name entered by the user
    if(strlen(device) >= IFNAMSIZ) {
        printf("Device name too long\n");
        return 1;
    }

    // Scan the network using the device name entered by the user
    scan_network(device);

    return 0;
}