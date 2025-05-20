//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRAVELS 10

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char destination[50];
    Date travelDate;
} TimeTravel;

void displayWelcomeMessage() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("You can time travel to various destinations on your specified date.\n");
}

void getTravelDate(Date *date) {
    printf("Enter the year (e.g., 2023): ");
    scanf("%d", &date->year);
    printf("Enter the month (1-12): ");
    scanf("%d", &date->month);
    while (date->month < 1 || date->month > 12) {
        printf("Invalid month. Please enter a valid month (1-12): ");
        scanf("%d", &date->month);
    }
    printf("Enter the day (1-31): ");
    scanf("%d", &date->day);
    while (date->day < 1 || date->day > 31) {
        printf("Invalid day. Please enter a valid day (1-31): ");
        scanf("%d", &date->day);
    }
}

void selectDestination(char *destination) {
    printf("Select your travel destination:\n");
    printf("1. The Great Wall of China\n");
    printf("2. Ancient Egypt\n");
    printf("3. Renaissance Italy\n");
    printf("4. Future City (2050)\n");
    printf("5. Dinosaur Age\n");
    printf("Enter the number corresponding to your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            strcpy(destination, "The Great Wall of China");
            break;
        case 2:
            strcpy(destination, "Ancient Egypt");
            break;
        case 3:
            strcpy(destination, "Renaissance Italy");
            break;
        case 4:
            strcpy(destination, "Future City (2050)");
            break;
        case 5:
            strcpy(destination, "Dinosaur Age");
            break;
        default:
            printf("Invalid choice. Defaulting to 'Unknown Destination'.\n");
            strcpy(destination, "Unknown Destination");
            break;
    }
}

void displayTravelInfo(TimeTravel travel) {
    printf("Time Travel Summary:\n");
    printf("Destination: %s\n", travel.destination);
    printf("Date of Travel: %04d-%02d-%02d\n", travel.travelDate.year, travel.travelDate.month, travel.travelDate.day);
}

void simulateTravel(TimeTravel travel) {
    printf("Traveling to %s on %04d-%02d-%02d...\n", travel.destination, travel.travelDate.year, travel.travelDate.month, travel.travelDate.day);
    
    // Simulating some travel duration with sleep
    for (int i = 0; i < 3; i++) {
        printf("... Time traveling in progress... %d\n", 3 - i);
        sleep(1);
    }

    printf("Arrival at %s!\n", travel.destination);
    printf("Enjoy your adventure!\n");
}

int main() {
    TimeTravel travels[MAX_TRAVELS];
    int travelCount = 0;

    displayWelcomeMessage();

    while (travelCount < MAX_TRAVELS) {
        printf("\nTime Travel Entry %d:\n", travelCount + 1);
        
        getTravelDate(&travels[travelCount].travelDate);
        selectDestination(travels[travelCount].destination);
        
        displayTravelInfo(travels[travelCount]);
        simulateTravel(travels[travelCount]);

        travelCount++;
        
        char choice;
        if (travelCount < MAX_TRAVELS) {
            printf("Do you want to schedule another time travel? (y/n): ");
            getchar(); // To consume newline
            choice = getchar();
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    }

    printf("\nThank you for using the C Time Travel Simulator! Travel safely through time!\n");
    return 0;
}