//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double latitude, longitude, temperature;
    char location[50];
    int choice;

    printf("Welcome to the Temperature Monitor!\n");
    printf("Please enter your location (e.g. New York, NY): ");
    scanf("%s", location);

    printf("Please enter the latitude of your location: ");
    scanf("%lf", &latitude);

    printf("Please enter the longitude of your location: ");
    scanf("%lf", &longitude);

    latitude = latitude * PI / 180;
    longitude = longitude * PI / 180;

    temperature = 25 - (latitude - 0.5) * (latitude - 0.5) - (longitude - 0.5) * (longitude - 0.5) * 0.5;

    printf("The temperature in %s is %.2lf degrees Celsius.\n", location, temperature);

    while(1) {
        printf("\nPlease choose an option:\n1. Check temperature\n2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Please enter the latitude of your location: ");
            scanf("%lf", &latitude);

            printf("Please enter the longitude of your location: ");
            scanf("%lf", &longitude);

            latitude = latitude * PI / 180;
            longitude = longitude * PI / 180;

            temperature = 25 - (latitude - 0.5) * (latitude - 0.5) - (longitude - 0.5) * (longitude - 0.5) * 0.5;

            printf("The temperature in your new location is %.2lf degrees Celsius.\n", temperature);
        }
        else if(choice == 2) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}