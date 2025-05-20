//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVEL 5
#define TIME_LINES 10

typedef struct {
    char *event;
    int year;
} TimeEvent;

TimeEvent timeline[TIME_LINES];

void initializeTimeline() {
    timeline[0].event = "The first breath of the universe";
    timeline[0].year = 0;

    timeline[1].event = "The rise of the dinosaurs";
    timeline[1].year = 200000000;

    timeline[2].event = "The fall of the dinosaurs";
    timeline[2].year = 65000000;

    timeline[3].event = "The first bipeds walk";
    timeline[3].year = 4000000;

    timeline[4].event = "Rise of humanity";
    timeline[4].year = 10000;

    timeline[5].event = "Coding emerges in the ether";
    timeline[5].year = 1940;

    timeline[6].event = "The Digital Awakening";
    timeline[6].year = 2000;

    timeline[7].event = "First sentient AI declared";
    timeline[7].year = 2080;

    timeline[8].event = "Reality fractures into parallel dimensions";
    timeline[8].year = 2200;

    timeline[9].event = "New cosmic understandings abound";
    timeline[9].year = 3000;
}

void displayTimeline() {
    printf("Timeline of Time Events:\n");
    for (int i = 0; i < TIME_LINES; i++) {
        printf("%d: %s in year %d\n", i+1, timeline[i].event, timeline[i].year);
    }
}

void timeTravel(int choice) {
    if (choice < 1 || choice > TIME_LINES) {
        printf("The choice spirals into the void, unreachable.\n");
        return;
    }

    TimeEvent chosenEvent = timeline[choice - 1];
    printf("You have traveled to %s, the year is %d.\n", chosenEvent.event, chosenEvent.year);
    printf("The air is thick with echoes of forgotten memories.\n");

    // Surreal twist on the journey
    int surrealFactor = rand() % 3;
    switch (surrealFactor) {
        case 0:
            printf("Flowers sing in binary and the ground hums with ancient tales.\n");
            break;
        case 1:
            printf("The sun melts like the mind of a wandering poet while shadows perform ballet.\n");
            break;
        case 2:
            printf("Time itself begins to flash dance, handing you riddles in random performances.\n");
            break;
    }
}

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Step through the doors of time:\n");
    for (int i = 1; i <= TIME_LINES; i++) {
        printf("%d - Travel to: %s (Year: %d)\n", i, timeline[i - 1].event, timeline[i - 1].year);
    }
    printf("Press 0 to exit the simulation.\n");
}

int main() {
    srand(time(NULL));
    initializeTimeline();
    
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("The portals of time whisper goodbye.\n");
            break;
        }
        
        timeTravel(choice);
    }
    
    return 0;
}