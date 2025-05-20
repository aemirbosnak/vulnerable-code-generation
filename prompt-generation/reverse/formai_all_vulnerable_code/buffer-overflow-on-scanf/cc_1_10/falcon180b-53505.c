//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double latitude;
    double longitude;
    int speed;
    int direction;
} gps_data;

void gps_simulation(gps_data *gps) {
    srand(time(NULL));
    gps->latitude = rand() % 180 - 90;
    gps->longitude = rand() % 360 - 180;
    gps->speed = rand() % 100;
    gps->direction = rand() % 360;
}

void print_gps_data(gps_data *gps) {
    printf("latitude: %.2f\n", gps->latitude);
    printf("longitude: %.2f\n", gps->longitude);
    printf("speed: %d km/h\n", gps->speed);
    printf("direction: %d degrees\n\n", gps->direction);
}

int main() {
    gps_data gps;
    int choice;

    do {
        printf("gps navigation simulation\n");
        printf("1. start simulation\n");
        printf("2. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            gps_simulation(&gps);
            print_gps_data(&gps);
            break;
        case 2:
            printf("exiting program...\n");
            break;
        default:
            printf("invalid choice!\n");
        }
    } while (choice!= 2);

    return 0;
}