//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct access_point {
    char ssid[MAX];
    char bssid[MAX];
    int signal_strength;
};

int main() {
    int n, i, j, k;
    printf("Enter the number of access points: ");
    scanf("%d", &n);

    struct access_point ap[n];
    printf("Enter the details of each access point: \n");
    for(i=0; i<n; i++) {
        printf("Access Point %d \n", i+1);
        printf("SSID: ");
        scanf("%s", ap[i].ssid);
        printf("BSSID: ");
        scanf("%s", ap[i].bssid);
        printf("Signal Strength (in dBm): ");
        scanf("%d", &ap[i].signal_strength);
        printf("\n");
    }

    printf("The WiFi Signal Strength Analyzer Results: \n\n");
    printf("SSID \t\t BSSID \t\t Signal Strength \n");
    for(i=0; i<n; i++) {
        printf("%s \t\t %s \t\t %d dBm \n", ap[i].ssid, ap[i].bssid, ap[i].signal_strength);
    }

    // Sorting the access points by signal strength
    struct access_point temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(ap[j].signal_strength < ap[j+1].signal_strength) {
                temp = ap[j];
                ap[j] = ap[j+1];
                ap[j+1] = temp;
            }
        }
    }

    printf("\nThe access points sorted by signal strength (in descending order): \n\n");
    printf("SSID \t\t BSSID \t\t Signal Strength \n");
    for(i=0; i<n; i++) {
        printf("%s \t\t %s \t\t %d dBm \n", ap[i].ssid, ap[i].bssid, ap[i].signal_strength);
    }

    // Calculating the average signal strength and closest access point
    float avg=0;
    int min_diff=9999, closest=-1;
    for(i=0; i<n; i++) {
        avg += ap[i].signal_strength;

        if(abs(ap[i].signal_strength - (-50)) < min_diff) {
            min_diff = abs(ap[i].signal_strength - (-50));
            closest = i;
        }
    }
    avg /= n;

    printf("\n\nThe average signal strength of all access points: %.2f dBm \n", avg);
    printf("The closest access point to the ideal strength (-50dBm): \n");
    printf("SSID \t\t BSSID \t\t Signal Strength \n");
    printf("%s \t\t %s \t\t %d dBm \n", ap[closest].ssid, ap[closest].bssid, ap[closest].signal_strength);

    return 0;
}