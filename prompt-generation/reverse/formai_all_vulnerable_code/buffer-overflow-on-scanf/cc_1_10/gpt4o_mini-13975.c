//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRAVEL_DESTINATIONS 5
#define TIME_GATES 3

typedef struct {
    char destination[50];
    int year;
} TimeTravelDestination;

TimeTravelDestination destinations[MAX_TRAVEL_DESTINATIONS] = {
    {"The Age of Dinosaurs", -65},
    {"The Renaissance", 1500},
    {"The Industrial Revolution", 1800},
    {"The Moon Landing", 1969},
    {"The Future", 3000}
};

void displayDestinations() {
    printf("Available Time Travel Destinations:\n");
    for (int i = 0; i < MAX_TRAVEL_DESTINATIONS; i++) {
        printf("%d: %s in year %d\n", i+1, destinations[i].destination, destinations[i].year);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    int choice;
    char response[10];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Prepare for an adventure through the ages...\n");

    // Start the time travel loop
    while (1) {
        displayDestinations();

        // Ask user to select a destination
        printf("Enter the number of your desired destination (1-%d) or 0 to exit: ", MAX_TRAVEL_DESTINATIONS);
        scanf("%d", &choice);

        // Exit condition
        if (choice == 0) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        }

        // Validate user's choice
        if (choice < 1 || choice > MAX_TRAVEL_DESTINATIONS) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Time travel experience
        printf("Traveling to %s in the year %d...\n", destinations[choice - 1].destination, destinations[choice - 1].year);
        
        // Random encounter during time travel
        int encounter = rand() % 3;
        switch (encounter) {
            case 0:
                printf("You've encountered a friendly dinosaur! It offers to show you around...\n");
                break;
            case 1:
                printf("You meet a revolutionary artist, inspiring you with his creativity!\n");
                break;
            case 2:
                printf("You've stumbled upon a secret invention in the Industrial era!\n");
                break;
            default:
                printf("A time anomaly occurred! You are disoriented!\n");
                break;
        }

        // Ask if user wants to continue or return
        printf("Do you wish to return to your own time or continue exploring? (type 'return' or 'continue'): ");
        scanf("%s", response);

        // Check response
        if (strcmp(response, "return") == 0) {
            printf("Returning to present time...\n");
        } else if (strcmp(response, "continue") == 0) {
            printf("Stay tuned for more adventures in time!\n");
            continue;
        } else {
            printf("I didn't understand that. Returning to present time...\n");
        }

        // Brief pause before the next loop iteration
        printf("...\n");
        for (int i = 0; i < 3; i++) {
            printf("Time traveling...\n");
            sleep(1);
        }
    }

    return 0;
}