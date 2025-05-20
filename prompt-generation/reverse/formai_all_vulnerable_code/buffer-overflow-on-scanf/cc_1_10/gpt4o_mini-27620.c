//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <linux/wireless.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_AP 100
#define BUF_LEN 512
#define SSID_LEN 32

typedef struct {
    char ssid[SSID_LEN];
    char mac[18];
    int signal_level;
} AccessPoint;

AccessPoint ap_list[MAX_AP];
int ap_count = 0;

void clear_ap_list() {
    memset(ap_list, 0, sizeof(ap_list));
    ap_count = 0;
}

void print_ap_list() {
    printf("\nAvailable Access Points:\n");
    printf("%-20s %-17s %-10s\n", "SSID", "MAC Address", "Signal");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < ap_count; i++) {
        printf("%-20s %-17s %-10d dBm\n", ap_list[i].ssid, ap_list[i].mac, ap_list[i].signal_level);
    }
}

int scan_networks() {
    FILE *fp;
    char command[BUF_LEN];
    char buffer[BUF_LEN];

    clear_ap_list();
    
    // Execute the 'iwlist' command to scan wireless networks
    snprintf(command, sizeof(command), "iwlist wlan0 scan 2>/dev/null");
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        // Parse the SSID
        if (strstr(buffer, "ESSID:") != NULL) {
            char *ssid = strchr(buffer, '\"') + 1;
            char *end = strchr(ssid, '\"');
            if (end != NULL) {
                *end = '\0';
                strcpy(ap_list[ap_count].ssid, ssid);
            }
        }
        // Parse the MAC Address
        if (strstr(buffer, "Address:") != NULL) {
            char *mac = strchr(buffer, ' ') + 1;
            strncpy(ap_list[ap_count].mac, mac, 17);
            ap_list[ap_count].mac[17] = '\0';
            ap_count++;
        }
        // Parse Signal level
        if (strstr(buffer, "Signal level=")) {
            int signal_level;
            sscanf(buffer, " Signal level=%d", &signal_level);
            ap_list[ap_count - 1].signal_level = signal_level;
        }
    }

    pclose(fp);
    return 0;
}

void display_menu() {
    printf("Wireless Network Scanner\n");
    printf("========================\n");
    printf("1. Scan for Networks\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (scan_networks() == 0) {
                    print_ap_list();
                } else {
                    printf("Failed to scan wireless networks.\n");
                }
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        usleep(500000); // Sleep for half a second before displaying the menu again
    }
    return 0;
}