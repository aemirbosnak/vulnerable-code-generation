//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define signal strength threshold
#define THRESHOLD -70

// Define maximum number of access points
#define MAX_APS 10

// Define access point struct
typedef struct {
    char ssid[20];
    int signal_strength;
} AccessPoint;

// Function to check if access point is above threshold
bool is_above_threshold(AccessPoint* ap) {
    return ap->signal_strength > THRESHOLD;
}

// Function to sort access points by signal strength
void sort_by_signal_strength(AccessPoint* aps, int num_aps) {
    for (int i = 0; i < num_aps; i++) {
        for (int j = 0; j < num_aps - 1; j++) {
            if (aps[j].signal_strength < aps[j+1].signal_strength) {
                // Swap access points
                AccessPoint temp = aps[j];
                aps[j] = aps[j+1];
                aps[j+1] = temp;
            }
        }
    }
}

int main() {
    AccessPoint access_points[MAX_APS];
    int num_aps = 0;
    bool running = true;
    
    // Loop to continuously scan for access points until user quits
    while (running) {
        // TODO: scan for access points and add to array
        
        // Sort access points by signal strength
        sort_by_signal_strength(access_points, num_aps);
        
        // Print out list of access points above threshold
        for (int i = 0; i < num_aps; i++) {
            if (is_above_threshold(&access_points[i])) {
                printf("%s\t%d dBm\n", access_points[i].ssid, access_points[i].signal_strength);
            }
        }
        
        // Check if user wants to quit
        char input[3];
        printf("Scan again? (y/n)");
        scanf("%s", input);
        if (input[0] == 'n') {
            running = false;
        }
    }
    
    return 0;
}