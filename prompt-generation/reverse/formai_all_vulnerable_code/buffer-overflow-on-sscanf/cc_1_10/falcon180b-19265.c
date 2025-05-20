//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int channel;
    int signal_strength;
} access_point;

void print_access_point(access_point *ap) {
    printf("SSID: %s\n", ap->ssid);
    printf("BSSID: %s\n", ap->bssid);
    printf("Channel: %d\n", ap->channel);
    printf("Signal strength: %d\n\n", ap->signal_strength);
}

int main() {
    char *interface = "wlan0";
    char cmd[100];
    FILE *fp;
    access_point *aps = NULL;
    int num_aps = 0;

    // Get the list of access points
    sprintf(cmd, "iwlist %s scan | grep ESSID | cut -d'' -f 2-", interface);
    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("Error: Failed to get access point list.\n");
        exit(1);
    }

    // Parse the access point list
    while (fgets(cmd, sizeof(cmd), fp)!= NULL) {
        access_point *ap = malloc(sizeof(access_point));
        sscanf(cmd, "%s %s %d %d", ap->ssid, ap->bssid, &ap->channel, &ap->signal_strength);
        aps = realloc(aps, sizeof(access_point) * ++num_aps);
        aps[num_aps - 1] = *ap;
        free(ap);
    }

    // Print the access point list
    for (int i = 0; i < num_aps; i++) {
        print_access_point(&aps[i]);
    }

    // Free the access point list
    for (int i = 0; i < num_aps; i++) {
        free(aps[i].ssid);
        free(aps[i].bssid);
    }
    free(aps);

    return 0;
}