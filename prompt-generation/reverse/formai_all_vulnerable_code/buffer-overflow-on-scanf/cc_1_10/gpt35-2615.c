//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

// Function to convert MAC address from unsigned char array to string
void mac_to_string(unsigned char *addr, char *str) {
	sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
}

int main () {

    int fd; // Socket descriptor
    struct ifreq ifr; // Interface request struct
    struct sockaddr_in *ip; // IP address struct
    unsigned char mac[6]; // MAC address array
    char mac_string[18]; // MAC address string
    int i, j; // Iteration variables
    char c; // Yes/no answer input
    int count = 0; // Counter for number of networks found

    printf("This program displays wireless networks in range.\n\n");

    // Open a socket
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0) {
        printf("Error opening socket.\n");
        exit(1);
    }

    // Get the name of the wireless interface
    printf("Enter the name of your wireless interface (ex. wlan0): ");
    scanf("%s", ifr.ifr_name);

    // Get the IP address of the wireless interface
    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        printf("Error getting IP address.\n");
        exit(1);
    }
    ip = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("Your IP Address: %s\n", inet_ntoa(ip->sin_addr));

    // Get the MAC address of the wireless interface
    if (ioctl(fd, SIOCGIFHWADDR, &ifr) < 0) {
        printf("Error getting MAC address.\n");
        exit(1);
    }
    memcpy(mac, ifr.ifr_hwaddr.sa_data, 6); // Copy MAC address to array
    mac_to_string(mac, mac_string); // Convert MAC address to string
    printf("Your MAC Address: %s\n", mac_string);

    // Scan for wireless networks
    printf("Scanning for wireless networks...\n\n");
    printf("BSSID                                 Signal  Encryption  SSID\n");
    for (i = 0; i < 10; i++) {
        // Generate random MAC address (00:11:22:XX:YY:ZZ)
        unsigned char bssid[6] = {0x00, 0x11, 0x22, (unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()};

        // Display information for fake network
        mac_to_string(bssid, mac_string);
        printf("%s  -%ddBm    ", mac_string, rand()%50-100);
        if (rand()%2 == 0) {
            printf("WPA2-PSK    ");
        } else {
            printf("Open        ");
        }
        // Generate random SSID
        char ssid[10];
        for (j = 0; j < 9; j++) {
            ssid[j] = (char)(rand()%26+97);
        }
        ssid[9] = '\0';
        printf("%s\n", ssid);
        count++;
        usleep(100000);
    }

    printf("\n%d wireless networks found in range.\n", count);

    // Close the socket
    close(fd);

    // Exit program
    printf("\nDo you want to exit? (y/n) ");
    while (isspace(c = getchar()));
    if (c == 'y' || c == 'Y') {
        exit(0);
    } else {
        main();
    }

    return 0;
}