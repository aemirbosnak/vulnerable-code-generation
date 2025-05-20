//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 10000
#define MIN_YEAR 1583 // The year when the Gregorian calendar was adopted
#define INTERVALS_NUM 6 // Number of time travel intervals

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function prototypes
void displayMenu();
Date travelTo(int choice);
void displayDate(Date date);
void announceTravelling(Date date);

int main() {
    int choice;
    Date destination;

    printf("Welcome to the C Time Travel Simulator!\n");
    printf("========================================\n");
    
    while (1) {
        displayMenu();
        printf("Choose a time period to travel to (1 - %d, or -1 to exit): ", INTERVALS_NUM);
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting the Time Travel Simulator. Safe travels!\n");
            break;
        }
        
        if (choice < 1 || choice > INTERVALS_NUM) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        // Get the destination date based on the selected choice
        destination = travelTo(choice);
        announceTravelling(destination);
        displayDate(destination);
    }

    return 0;
}

void displayMenu() {
    printf("\n*** Time Travel Options ***\n");
    printf("1. Travel to Ancient Egypt (Around 3000 BC)\n");
    printf("2. Witness the Renaissance (15th Century)\n");
    printf("3. Experience the Industrial Revolution (18th Century)\n");
    printf("4. Participate in the Roaring Twenties (1920s)\n");
    printf("5. Explore the Space Age (1960s)\n");
    printf("6. Future Exploration (Year 3000)\n");
}

Date travelTo(int choice) {
    Date date;
    
    switch (choice) {
        case 1: // Ancient Egypt
            date.year = -3000;
            date.month = 12; // December
            date.day = 31;
            break;
        case 2: // Renaissance
            date.year = 1500;
            date.month = 7; // July
            date.day = 1;
            break;
        case 3: // Industrial Revolution
            date.year = 1780;
            date.month = 5; // May
            date.day = 20;
            break;
        case 4: // Roaring Twenties
            date.year = 1927;
            date.month = 12; // December
            date.day = 31;
            break;
        case 5: // Space Age
            date.year = 1969;
            date.month = 7; // July
            date.day = 20; // Apollo 11 Moon Landing
            break;
        case 6: // Future Exploration
            date.year = 3000;
            date.month = 1; // January
            date.day = 1;
            break;
        default:
            date.year = 0;
            date.month = 0;
            date.day = 0;
            break;
    }

    return date;
}

void displayDate(Date date) {
    if (date.year < 0) {
        printf("You have traveled to the year %d BC, %02d/%02d!\n", -date.year, date.month, date.day);
    } else {
        printf("You have arrived in the year %d AD, %02d/%02d!\n", date.year, date.month, date.day);
    }
}

void announceTravelling(Date date) {
    printf("Initiating time travel sequence...\n");
    for (int i = 3; i > 0; i--) {
        printf("Time travel in T-%d...\n", i);
        sleep(1);
    }
    printf("3... 2... 1... Blast Off!\n");
    printf("You've successfully traversed through time!\n");
}