//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of access points
#define MAX_AP 20

// Define the maximum length of SSID
#define MAX_SSID_LEN 32

// Structure to store access point data
typedef struct {
    char ssid[MAX_SSID_LEN];
    int signalStrength;
} AccessPoint;

// Function to sort access points based on signal strength
void sortAccessPoints(AccessPoint ap[], int numAps) {
    int i, j;

    // Bubble sort algorithm
    for (i = 0; i < numAps-1; i++) {
        for (j = 0; j < numAps-i-1; j++) {
            if (ap[j].signalStrength < ap[j+1].signalStrength) {
                // Swap the access points
                AccessPoint temp = ap[j];
                ap[j] = ap[j+1];
                ap[j+1] = temp;
            }
        }
    }
}

int main() {
    int numAps;

    // Get the number of access points
    printf("Enter the number of access points: ");
    scanf("%d", &numAps);

    // Check if the number of access points is within the limit
    if (numAps > MAX_AP) {
        printf("Error: Number of access points exceeded the limit %d.\n", MAX_AP);
        return 0;
    }

    // Create an array of access points
    AccessPoint ap[MAX_AP];

    // Get the data for each access point
    int i;
    for (i = 0; i < numAps; i++) {
        printf("Enter the SSID of access point %d: ", i+1);
        scanf("%s", ap[i].ssid);
        printf("Enter the signal strength of access point %d: ", i+1);
        scanf("%d", &ap[i].signalStrength);
    }

    // Sort the access points based on signal strength
    sortAccessPoints(ap, numAps);

    // Print the sorted list of access points
    printf("\nAccess points sorted by signal strength:\n");
    for (i = 0; i < numAps; i++) {
        printf("%d) SSID: %s, Signal Strength: %d\n", i+1, ap[i].ssid, ap[i].signalStrength);
    }

    return 0;
}