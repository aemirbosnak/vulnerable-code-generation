//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 5

typedef struct {
    char era[30];
    char event[100];
} TimeEvent;

TimeEvent timeTravelEvents[MAX_EVENTS] = {
    {"The Age of Dinosaurs", "You witness a Tyrannosaurus Rex roaring in the distance."},
    {"Ancient Rome", "You see gladiators battling in the Colosseum."},
    {"The Renaissance", "Artists are painting masterpieces; the Mona Lisa is being created right before your eyes."},
    {"The Roaring Twenties", "Jazz music fills the air; flappers are dancing at a speakeasy."},
    {"The Future", "You see flying cars and robots serving coffee!"}
};

void welcomeMessage() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Prepare yourself for an adventure through time!\n");
    printf("-------------------------------------------------\n");
}

void displayEraOptions() {
    printf("Choose an era to visit:\n");
    for (int i = 0; i < MAX_EVENTS; i++) {
        printf("%d. %s\n", i + 1, timeTravelEvents[i].era);
    }
    printf("0. Exit\n");
}

void travelToEra(int choice) {
    if (choice > 0 && choice <= MAX_EVENTS) {
        printf("Traveling to '%s'...\n", timeTravelEvents[choice - 1].era);
        printf("%s\n", timeTravelEvents[choice - 1].event);
        printf("You have successfully returned to the present!\n");
    } else if (choice == 0) {
        printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

void runSimulation() {
    int choice;
    while (1) {
        displayEraOptions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            travelToEra(choice);
            break;
        }

        travelToEra(choice);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    welcomeMessage();
    runSimulation();
    return 0;
}