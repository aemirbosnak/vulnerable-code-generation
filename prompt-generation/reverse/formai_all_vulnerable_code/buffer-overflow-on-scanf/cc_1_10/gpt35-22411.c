//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} access_point;

void get_access_points(int num_points, access_point **points);
void print_access_points(int num_points, access_point *points);

int main() {
    int num_points;
    access_point *points;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    printf("Enter the number of access points: ");
    scanf("%d", &num_points);

    get_access_points(num_points, &points);
    print_access_points(num_points, points);

    free(points);

    return 0;
}

void get_access_points(int num_points, access_point **points) {
    *points = calloc(num_points, sizeof(access_point));

    for (int i = 0; i < num_points; i++) {
        printf("Access point %d:\n", i+1);

        printf("  SSID: ");
        scanf("%s", (*points)[i].ssid);

        printf("  Signal Strength (dBm): ");
        scanf("%d", &((*points)[i].signal_strength));
    }
}

void print_access_points(int num_points, access_point *points) {
    printf("\nAccess Points:\n");

    for (int i = 0; i < num_points; i++) {
        printf("%d. SSID: %s\tSignal Strength: %d dBm\n", i+1, points[i].ssid, points[i].signal_strength);
    }
}