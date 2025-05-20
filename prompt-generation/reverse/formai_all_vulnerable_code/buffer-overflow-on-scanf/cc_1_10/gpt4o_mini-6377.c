//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAVELS 10
#define TIMESTAMP_LENGTH 30

typedef struct {
    char destination[50];
    time_t timestamp;
} Travel;

typedef struct {
    Travel travels[MAX_TRAVELS];
    int count;
} TimeTraveler;

void initializeTimeTraveler(TimeTraveler *traveler) {
    traveler->count = 0;
}

void addTravel(TimeTraveler *traveler, const char *destination) {
    if (traveler->count < MAX_TRAVELS) {
        strncpy(traveler->travels[traveler->count].destination, destination, 50);
        traveler->travels[traveler->count].timestamp = time(NULL);
        traveler->count++;
        printf("Travel added to destination: %s\n", destination);
    } else {
        printf("Maximum travel limit reached!\n");
    }
}

void displayTravels(const TimeTraveler *traveler) {
    printf("\nList of Time Travels:\n");
    for (int i = 0; i < traveler->count; i++) {
        char buffer[TIMESTAMP_LENGTH];
        strftime(buffer, TIMESTAMP_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&traveler->travels[i].timestamp));
        printf("Travel #%d: Destination: %s | Timestamp: %s\n", i + 1, traveler->travels[i].destination, buffer);
    }
}

void timeTravel(const char *destination) {
    printf("\nEngaging time travel protocol...\n");
    printf("Destination: %s\n", destination);
    printf("Navigating through the temporal flux...\n");
    // Simulate a time travel event with a delay
    for (int countdown = 3; countdown > 0; countdown--) {
        printf("T-minus %d...\n", countdown);
        sleep(1);
    }
    printf("Time travel successful! You have arrived at %s.\n", destination);
}

void mainMenu(TimeTraveler *traveler) {
    int choice;
    char destination[50];

    while (1) {
        printf("\n--- Time Travel Simulator ---\n");
        printf("1. Add Travel Destination\n");
        printf("2. View Travel History\n");
        printf("3. Time Travel\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter time travel destination: ");
                fgets(destination, sizeof(destination), stdin);
                strtok(destination, "\n"); // Remove trailing newline
                addTravel(traveler, destination);
                break;

            case 2:
                displayTravels(traveler);
                break;

            case 3:
                if (traveler->count > 0) {
                    printf("Select a travel destination from history:\n");
                    for (int i = 0; i < traveler->count; i++) {
                        printf("%d. %s\n", i + 1, traveler->travels[i].destination);
                    }
                    int travelChoice;
                    printf("Enter number of destination to travel to: ");
                    scanf("%d", &travelChoice);
                    if (travelChoice > 0 && travelChoice <= traveler->count) {
                        timeTravel(traveler->travels[travelChoice - 1].destination);
                    } else {
                        printf("Invalid selection!\n");
                    }
                } else {
                    printf("No travel history available to time travel!\n");
                }
                break;

            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                return;

            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
}

int main() {
    TimeTraveler traveler;
    initializeTimeTraveler(&traveler);
    mainMenu(&traveler);
    return 0;
}