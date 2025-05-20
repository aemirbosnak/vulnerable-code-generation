//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
    double speed;
    double direction;
} gps_data;

void gps_update(gps_data *data) {
    data->latitude += 0.0001;
    data->longitude += 0.0001;
    data->speed += 0.1;
    data->direction += 1;
}

void gps_display(gps_data *data) {
    printf("Latitude: %f\nLongitude: %f\nSpeed: %f\nDirection: %f\n", data->latitude, data->longitude, data->speed, data->direction);
}

int main() {
    srand(time(NULL));
    gps_data gps;
    int choice;

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Update GPS data\n2. Display GPS data\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                gps_update(&gps);
                printf("GPS data updated.\n");
                break;
            case 2:
                gps_display(&gps);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}