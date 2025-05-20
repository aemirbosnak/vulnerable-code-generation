//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_YEARS 100
#define MAX_LOCATIONS 30

typedef struct {
    char year[5];
    char location[50];
    char event[100];
} TimeTravel;

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Choose a time period to travel to:\n");
    printf("1. 1000 AD - Medieval Europe\n");
    printf("2. 1776 AD - American Revolution\n");
    printf("3. 1920 AD - Roaring Twenties\n");
    printf("4. 1969 AD - Moon Landing\n");
    printf("5. 2023 AD - Future Tech\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void travelToPeriod(TimeTravel tt) {
    printf("\n*** Time Travel Initiated ***\n");
    printf("Year: %s\n", tt.year);
    printf("Location: %s\n", tt.location);
    printf("Event: %s\n", tt.event);
    printf("Enjoy your adventure!\n");
}

int main() {
    TimeTravel timePeriods[MAX_YEARS] = {
        {"1000", "Medieval Europe", "Witness the life of knights and castles."},
        {"1776", "Philadelphia", "Join the signing of the Declaration of Independence."},
        {"1920", "Chicago", "Experience the Jazz Age and speakeasies."},
        {"1969", "The Moon", "Watch humans walk on the moon for the first time."},
        {"2023", "Silicon Valley", "Explore the latest in AI and quantum computing."}
    };
    
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please try again.\n");
            continue;
        }

        travelToPeriod(timePeriods[choice - 1]);
        printf("\nPress Enter to continue...\n");
        while (getchar() != '\n');  // Clear the input buffer
        getchar();  // Wait for user to press Enter
    }

    return 0;
}