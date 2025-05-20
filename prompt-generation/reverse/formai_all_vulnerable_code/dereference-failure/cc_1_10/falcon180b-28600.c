//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_CHANNEL_LENGTH 10
#define MAX_RSSI_LENGTH 10
#define MAX_SECURITY_LENGTH 20
#define MAX_SSID_LIST_LENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    char channel[MAX_CHANNEL_LENGTH];
    char rssi[MAX_RSSI_LENGTH];
    char security[MAX_SECURITY_LENGTH];
} SSID;

typedef struct {
    int num_ssids;
    SSID ssid_list[MAX_SSID_LIST_LENGTH];
} SSIDList;

void add_ssid(SSIDList *list, char *ssid, char *bssid, char *channel, char *rssi, char *security) {
    list->num_ssids++;
    strncpy(list->ssid_list[list->num_ssids - 1].ssid, ssid, MAX_SSID_LENGTH);
    strncpy(list->ssid_list[list->num_ssids - 1].bssid, bssid, MAX_BSSID_LENGTH);
    strncpy(list->ssid_list[list->num_ssids - 1].channel, channel, MAX_CHANNEL_LENGTH);
    strncpy(list->ssid_list[list->num_ssids - 1].rssi, rssi, MAX_RSSI_LENGTH);
    strncpy(list->ssid_list[list->num_ssids - 1].security, security, MAX_SECURITY_LENGTH);
}

void print_ssid_list(SSIDList *list) {
    printf("SSID\tBSSID\tChannel\tRSSI\tSecurity\n");
    for (int i = 0; i < list->num_ssids; i++) {
        printf("%s\t%s\t%s\t%s\t%s\n", list->ssid_list[i].ssid, list->ssid_list[i].bssid, list->ssid_list[i].channel, list->ssid_list[i].rssi, list->ssid_list[i].security);
    }
}

int main(int argc, char **argv) {
    SSIDList ssid_list = {0};
    FILE *fp;
    char line[1024];
    char *ssid, *bssid, *channel, *rssi, *security;

    // Open the wireless network scanner output file
    fp = fopen("wireless_scan.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open wireless_scan.txt file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Parse the line for SSID, BSSID, channel, RSSI, and security information
        if (sscanf(line, "SSID: %s\nBSSID: %s\nChannel: %s\nRSSI: %s\nSecurity: %s\n", ssid, bssid, channel, rssi, security) == 5) {
            // Add the SSID information to the list
            add_ssid(&ssid_list, ssid, bssid, channel, rssi, security);
        }
    }

    fclose(fp);

    // Print the SSID list
    print_ssid_list(&ssid_list);

    return 0;
}