//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

// A simple function to convert a string to lowercase
char *toLower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

// A function to scan for wireless networks
int scanForNetworks(char *interface) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Set the socket options
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(55555);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }

    // Set the broadcast option
    int broadcast = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("setsockopt");
        return -1;
    }

    // Create a buffer to receive the data
    char buf[1024];

    // Send a broadcast message to scan for networks
    char *msg = "scan";
    sendto(sock, msg, strlen(msg), 0, (struct sockaddr *)&addr, sizeof(addr));

    // Receive the data from the networks
    int num_networks = 0;
    while (1) {
        int len = sizeof(addr);
        int n = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &len);
        if (n < 0) {
            perror("recvfrom");
            break;
        }
        if (n == 0) {
            break;
        }
        buf[n] = '\0';

        // Convert the data to lowercase
        char *data = toLower(buf);

        // Check if the data contains the SSID of a network
        if (strstr(data, "ssid") != NULL) {
            // Extract the SSID from the data
            char *ssid = strstr(data, "ssid:");
            if (ssid != NULL) {
                ssid += 5;
                printf("%s\n", ssid);
                num_networks++;
            }
        }
    }

    // Close the socket
    close(sock);

    return num_networks;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Scan for wireless networks
    int num_networks = scanForNetworks(argv[1]);
    if (num_networks == 0) {
        printf("No wireless networks found.\n");
    } else {
        printf("Found %d wireless networks:\n", num_networks);
    }

    return 0;
}