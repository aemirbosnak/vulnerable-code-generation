//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEAR_START 1900
#define YEAR_END 3000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char destination[50];
    Date date;
} TimeTravel;

void displayMenu() {
    printf("\n=== Time Travel Simulation ===\n");
    printf("1. Travel to the Past\n");
    printf("2. Travel to the Future\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void getTravelDate(TimeTravel* travel) {
    printf("Enter year (from %d to %d): ", YEAR_START, YEAR_END);
    scanf("%d", &travel->date.year);
    if (travel->date.year < YEAR_START || travel->date.year > YEAR_END) {
        printf("Year out of range!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter month (1-12): ");
    scanf("%d", &travel->date.month);
    if (travel->date.month < 1 || travel->date.month > 12) {
        printf("Invalid month!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter day (1-31): ");
    scanf("%d", &travel->date.day);
    if (travel->date.day < 1 || travel->date.day > 31) {
        printf("Invalid day!\n");
        exit(EXIT_FAILURE);
    }

    printf("Choose a destination: ");
    scanf("%s", travel->destination);
}

void travelToDestination(TimeTravel* travel) {
    printf("\n=== Initiating Time Travel ===\n");
    printf("Traveling to %s on %d-%02d-%02d...\n", travel->destination,
           travel->date.year, travel->date.month, travel->date.day);
    
    // Simulate time travel process
    for (int i = 0; i < 5; i++) {
        printf("... Traveling...\n");
        sleep(1);  // Simulate delay for dramatic effect
    }
    
    printf("You have arrived at %s on %d-%02d-%02d!\n",
           travel->destination, travel->date.year, travel->date.month, travel->date.day);
}

void travelToPast() {
    TimeTravel travel;
    travel.date.year = 0; // Default initialization
    travel.date.month = 0;
    travel.date.day = 0;
    strcpy(travel.destination, "Unknown");

    printf("=== Travel to the Past ===\n");
    getTravelDate(&travel);
    travelToDestination(&travel);
}

void travelToFuture() {
    TimeTravel travel;
    travel.date.year = 0; // Default initialization
    travel.date.month = 0;
    travel.date.day = 0;
    strcpy(travel.destination, "Unknown");

    printf("=== Travel to the Future ===\n");
    getTravelDate(&travel);
    travelToDestination(&travel);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToPast();
                break;
            case 2:
                travelToFuture();
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}