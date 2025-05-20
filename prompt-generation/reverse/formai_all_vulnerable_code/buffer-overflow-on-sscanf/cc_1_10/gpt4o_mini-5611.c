//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_AP 100
#define SSID_LEN 32
#define SIGNAL_STRENGTH_LEN 10

typedef struct {
    char ssid[SSID_LEN];
    int signal_strength; // in dBm
} AccessPoint;

void print_access_points(AccessPoint aps[], int count) {
    for (int i = 0; i < count; i++) {
        printf("SSID: %s | Signal Strength: %d dBm ", aps[i].ssid, aps[i].signal_strength);
        
        // Displaying shape based on the signal strength
        if (aps[i].signal_strength >= -50) {
            printf("[****]\n"); // Excellent Signal
        } else if (aps[i].signal_strength >= -60) {
            printf("[*** ]\n"); // Good Signal
        } else if (aps[i].signal_strength >= -70) {
            printf("[**  ]\n"); // Fair Signal
        } else if (aps[i].signal_strength >= -80) {
            printf("[*   ]\n"); // Weak Signal
        } else {
            printf("[    ]\n"); // No Signal
        }
    }
}

int parse_wifi_info(AccessPoint aps[]) {
    FILE* fp;
    char buffer[256];
    int count = 0;

    // Command to fetch Wi-Fi information
    fp = popen("nmcli -f SSID,SIGNAL device wifi", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return 0;
    }

    // Reading the data returned by the command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (count > 0) { // Skip the first line
            sscanf(buffer, "%[^,],%d", aps[count-1].ssid, &aps[count-1].signal_strength);
            count++;
        } else {
            count++; // Skip the header line
        }
    }
    pclose(fp);

    return count - 1; // Return the number of Access Points found
}

int main() {
    AccessPoint aps[MAX_AP];
    int count;

    printf("Collecting Wi-Fi signal strength information...\n");
    
    count = parse_wifi_info(aps);
    
    if (count > 0) {
        printf("\nFound %d Access Points:\n", count);
        print_access_points(aps, count);
    } else {
        printf("No Access Points found.\n");
    }

    return 0;
}