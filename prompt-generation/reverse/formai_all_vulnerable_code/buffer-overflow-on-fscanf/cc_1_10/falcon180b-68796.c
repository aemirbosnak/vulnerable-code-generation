//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10

struct City {
    char name[50];
    double latitude;
    double longitude;
};

struct City cities[MAX_CITIES];

void read_cities() {
    FILE *file = fopen("cities.txt", "r");
    if (file == NULL) {
        printf("Error: could not open cities file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %lf %lf\n", cities[i].name, &cities[i].latitude, &cities[i].longitude) == 3 && i < MAX_CITIES) {
        i++;
    }

    fclose(file);
}

void print_cities() {
    for (int i = 0; i < MAX_CITIES; i++) {
        if (cities[i].name[0]!= '\0') {
            printf("%s\n", cities[i].name);
        }
    }
}

void simulate_gps() {
    srand(time(NULL));

    int current_city = rand() % MAX_CITIES;
    double current_latitude = cities[current_city].latitude;
    double current_longitude = cities[current_city].longitude;

    while (1) {
        printf("Current city: %s\n", cities[current_city].name);
        printf("Latitude: %.2lf\n", current_latitude);
        printf("Longitude: %.2lf\n", current_longitude);

        char choice;
        printf("Enter a direction (n/s/e/w): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                current_latitude += 0.0001;
                break;
            case's':
                current_latitude -= 0.0001;
                break;
            case 'e':
                current_longitude += 0.0001;
                break;
            case 'w':
                current_longitude -= 0.0001;
                break;
            default:
                printf("Invalid direction\n");
        }

        if (current_latitude < -90.0 || current_latitude > 90.0 || current_longitude < -180.0 || current_longitude > 180.0) {
            printf("GPS signal lost\n");
            exit(0);
        }
    }
}

int main() {
    read_cities();
    print_cities();
    simulate_gps();

    return 0;
}