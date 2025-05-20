//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LOCATIONS 10

typedef struct {
    char name[50];
    float latitude;
    float longitude;
} Location;

void displayMenu() {
    printf("\n--- GPS Navigation Simulation ---\n");
    printf("1. Add a location\n");
    printf("2. Get directions\n");
    printf("3. Exit\n");
    printf("---------------------------------\n");
    printf("Enter your choice: ");
}

void addLocation(Location locations[], int *count) {
    if (*count >= MAX_LOCATIONS) {
        printf("Location list is full. Cannot add more locations.\n");
        return;
    }

    printf("Enter location name: ");
    scanf("%s", locations[*count].name);
    printf("Enter latitude: ");
    scanf("%f", &locations[*count].latitude);
    printf("Enter longitude: ");
    scanf("%f", &locations[*count].longitude);
    (*count)++;

    printf("Location '%s' added successfully.\n", locations[*count - 1].name);
}

void getDirections(Location locations[], int count) {
    char start[50], destination[50];
    int startIndex = -1, destinationIndex = -1;

    printf("Enter starting location: ");
    scanf("%s", start);
    printf("Enter destination location: ");
    scanf("%s", destination);

    for (int i = 0; i < count; i++) {
        if (strcmp(locations[i].name, start) == 0) {
            startIndex = i;
        }
        if (strcmp(locations[i].name, destination) == 0) {
            destinationIndex = i;
        }
    }

    if (startIndex == -1) {
        printf("Starting location not found.\n");
        return;
    }
    if (destinationIndex == -1) {
        printf("Destination location not found.\n");
        return;
    }

    printf("Getting directions from %s to %s...\n", locations[startIndex].name, locations[destinationIndex].name);
    printf("Latitude difference: %.2f\n", locations[destinationIndex].latitude - locations[startIndex].latitude);
    printf("Longitude difference: %.2f\n", locations[destinationIndex].longitude - locations[startIndex].longitude);
    printf("You can move in a straight line towards the destination!\n");
}

int main() {
    Location locations[MAX_LOCATIONS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLocation(locations, &count);
                break;
            case 2:
                getDirections(locations, count);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}