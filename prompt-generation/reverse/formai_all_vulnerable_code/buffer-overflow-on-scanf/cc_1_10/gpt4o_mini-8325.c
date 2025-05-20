//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void travelToYear(int year);
void displayCurrentYear();
void getRandomYear(int *year);

// Main Function
int main() {
    int choice, year;

    printf("Welcome to the C Time Travel Simulator!\n");
    printf("You will be able to travel to different points in time.\n");

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCurrentYear();
                break;
            case 2:
                printf("Enter the year you wish to travel to: ");
                scanf("%d", &year);
                travelToYear(year);
                break;
            case 3:
                getRandomYear(&year);
                travelToYear(year);
                break;
            default:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
        }
        printf("\n");
    }
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Time Travel Menu ---\n");
    printf("1. Display Current Year\n");
    printf("2. Travel to a Specific Year\n");
    printf("3. Travel to a Random Year\n");
    printf("4. Exit\n");
}

// Function to display the current year
void displayCurrentYear() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int currentYear = tm_info->tm_year + 1900; // Year is based on 1900
    printf("Current Year: %d\n", currentYear);
}

// Function to travel to a specific year
void travelToYear(int year) {
    printf("Engaging time travel protocol...\n");
    // Simulate delay during time travel
    for (int i = 0; i < 3; i++) {
        printf("Traveling...\n");
        sleep(1);
    }
    printf("Welcome to the year %d!\n", year);
    printf("Exploring the wonders and quirks of this year...\n");
    
    // Simple historical facts and events for the range 1900-2023
    if (year < 1900) {
        printf("You have traveled back to before the 20th century! A period of great change awaits.\n");
    } else if (year >= 1900 && year < 1950) {
        printf("Welcome to the early 20th century! The world is experiencing World War I and the Roaring Twenties.\n");
    } else if (year >= 1950 && year < 2000) {
        printf("It's the second half of the 20th century! Witness technological advancements and the Cold War.\n");
    } else if (year >= 2000 && year < 2023) {
        printf("Welcome to the 21st century! Enjoy the Internet, smartphones, and globalization.\n");
    } else {
        printf("You have entered the far future! The possibilities are endless.\n");
    }
}

// Function to get a random year within a specific range
void getRandomYear(int *year) {
    srand(time(NULL)); // Seed the random number generator
    *year = rand() % (2023 - 1900 + 1) + 1900; // Random year between 1900 and 2023
    printf("Random year selected: %d\n", *year);
}