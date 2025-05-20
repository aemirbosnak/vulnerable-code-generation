//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TIME_TRAVELERS 10

typedef struct {
    char *name;
    int age;
    int destinationYear;
} TimeTraveler;

int main() {
    // Initialize the array of time travelers
    TimeTraveler timeTravelers[MAX_TIME_TRAVELERS];

    // Get the number of time travelers
    int numTimeTravelers;
    printf("Enter the number of time travelers: ");
    scanf("%d", &numTimeTravelers);

    // Get the details of each time traveler
    for (int i = 0; i < numTimeTravelers; i++) {
        TimeTraveler *timeTraveler = &timeTravelers[i];

        // Get the time traveler's name
        printf("Enter the name of time traveler %d: ", i + 1);
        timeTraveler->name = malloc(100);
        scanf("%s", timeTraveler->name);

        // Get the time traveler's age
        printf("Enter the age of time traveler %d: ", i + 1);
        scanf("%d", &timeTraveler->age);

        // Get the time traveler's destination year
        printf("Enter the destination year of time traveler %d: ", i + 1);
        scanf("%d", &timeTraveler->destinationYear);
    }

    // Print the list of time travelers
    printf("\nList of time travelers:\n");
    for (int i = 0; i < numTimeTravelers; i++) {
        TimeTraveler *timeTraveler = &timeTravelers[i];

        printf("Name: %s\n", timeTraveler->name);
        printf("Age: %d\n", timeTraveler->age);
        printf("Destination year: %d\n\n", timeTraveler->destinationYear);
    }

    // Free the memory allocated for the time travelers' names
    for (int i = 0; i < numTimeTravelers; i++) {
        TimeTraveler *timeTraveler = &timeTravelers[i];

        free(timeTraveler->name);
    }

    return 0;
}