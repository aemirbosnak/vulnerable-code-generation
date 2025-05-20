//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    int signal_strength;
} AccessPoint;

int main(int argc, char *argv[]) {
    int num_access_points = 0;
    AccessPoint *access_points = NULL;

    // get number of access points
    printf("Enter the number of access points: ");
    scanf("%d", &num_access_points);

    // allocate memory for access_points
    access_points = (AccessPoint*) malloc(num_access_points * sizeof(AccessPoint));
    if (access_points == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // get information for each access point
    for (int i = 0; i < num_access_points; i++) {
        printf("Access point %d:\n", i+1);

        printf("\tEnter SSID (up to %d characters): ", MAX_SSID_LENGTH);
        scanf("%s", access_points[i].ssid);

        printf("\tEnter signal strength (0-%d): ", MAX_SIGNAL_STRENGTH);
        scanf("%d", &access_points[i].signal_strength);
    }

    // print information for each access point
    printf("\nAccess Point Information:\n");
    printf("----------------------------------------\n");
    printf("     SSID           | Signal Strength\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < num_access_points; i++) {
        printf("%-19s | %-3d%%\n", access_points[i].ssid, access_points[i].signal_strength);
    }
    printf("\n");

    // calculate average signal strength
    int sum_signal_strength = 0;
    for (int i = 0; i < num_access_points; i++) {
        sum_signal_strength += access_points[i].signal_strength;
    }
    int avg_signal_strength = sum_signal_strength / num_access_points;

    // determine best and worst signals
    int best_signal_strength = -1;
    int worst_signal_strength = MAX_SIGNAL_STRENGTH + 1;
    char best_ssid[MAX_SSID_LENGTH + 1];
    char worst_ssid[MAX_SSID_LENGTH + 1];
    for (int i = 0; i < num_access_points; i++) {
        if (access_points[i].signal_strength > best_signal_strength) {
            best_signal_strength = access_points[i].signal_strength;
            strcpy(best_ssid, access_points[i].ssid);
        }
        if (access_points[i].signal_strength < worst_signal_strength) {
            worst_signal_strength = access_points[i].signal_strength;
            strcpy(worst_ssid, access_points[i].ssid);
        }
    }

    // print statistics
    printf("Signal Strength Statistics:\n");
    printf("----------------------------------------\n");
    printf("Average Signal Strength: %d%%\n", avg_signal_strength);
    printf("Best Signal: %s (%d%%)\n", best_ssid, best_signal_strength);
    printf("Worst Signal: %s (%d%%)\n", worst_ssid, worst_signal_strength);

    free(access_points);
    return 0;
}