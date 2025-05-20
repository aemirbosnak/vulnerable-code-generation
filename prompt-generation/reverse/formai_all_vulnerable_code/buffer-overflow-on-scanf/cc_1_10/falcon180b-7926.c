//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct location {
    double latitude;
    double longitude;
};

void generate_random_location(struct location *location) {
    srand(time(NULL));
    location->latitude = rand() % 90 + -45;
    location->longitude = rand() % 180 + -90;
}

int main() {
    struct location current_location, destination;
    int choice;

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Please enter your current location (latitude and longitude): ");
    scanf("%lf %lf", &current_location.latitude, &current_location.longitude);

    generate_random_location(&destination);

    while (1) {
        printf("\nYou are currently at: (%lf, %lf)\n", current_location.latitude, current_location.longitude);
        printf("Your destination is: (%lf, %lf)\n", destination.latitude, destination.longitude);
        printf("What would you like to do?\n");
        printf("1. Get directions\n");
        printf("2. Change destination\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Getting directions...\n");
                break;
            case 2:
                printf("Enter new destination (latitude and longitude): ");
                scanf("%lf %lf", &destination.latitude, &destination.longitude);
                printf("Destination set to: (%lf, %lf)\n", destination.latitude, destination.longitude);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}