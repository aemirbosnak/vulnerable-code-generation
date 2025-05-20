//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LAT_MIN -90.0
#define LAT_MAX 90.0
#define LON_MIN -180.0
#define LON_MAX 180.0

typedef struct {
    double latitude;
    double longitude;
} coordinate_t;

void generate_random_coordinate(coordinate_t *coordinate) {
    coordinate->latitude = LAT_MIN + (LAT_MAX - LAT_MIN) * (rand() / (RAND_MAX + 1.0));
    coordinate->longitude = LON_MIN + (LON_MAX - LON_MIN) * (rand() / (RAND_MAX + 1.0));
}

int main() {
    srand(time(NULL));

    coordinate_t current_coordinate;
    generate_random_coordinate(&current_coordinate);

    printf("Current coordinate: %.6f, %.6f\n", current_coordinate.latitude, current_coordinate.longitude);

    while (1) {
        int choice;
        printf("1. Move north\n");
        printf("2. Move east\n");
        printf("3. Move south\n");
        printf("4. Move west\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                current_coordinate.latitude += 0.1;
                break;
            case 2:
                current_coordinate.longitude += 0.1;
                break;
            case 3:
                current_coordinate.latitude -= 0.1;
                break;
            case 4:
                current_coordinate.longitude -= 0.1;
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }

        printf("New coordinate: %.6f, %.6f\n", current_coordinate.latitude, current_coordinate.longitude);
    }

    return 0;
}