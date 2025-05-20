//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
int getChoice();
void travelToTimePeriod(int choice);
void displayHistory(int period);
void handleTimePeriod(int choice);

int main() {
    int choice;

    while (1) {
        displayMenu();
        choice = getChoice();

        if (choice == 0) {
            printf("Exiting the Time Travel Simulator. Goodbye!\n");
            break;
        }

        travelToTimePeriod(choice);
    }

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("Choose a time period to travel to:\n");
    printf("1. Prehistoric Era\n");
    printf("2. Ancient Egypt\n");
    printf("3. Middle Ages\n");
    printf("4. Industrial Revolution\n");
    printf("5. Modern Day\n");
    printf("0. Exit\n");
    printf("-----------------------------\n");
}

// Function to get the user's choice
int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function that simulates traveling to a selected time period
void travelToTimePeriod(int choice) {
    printf("Initiating time travel sequence...\n");
    sleep(1); // Simulate some travel time
    handleTimePeriod(choice);
}

// Function to handle the specific time period
void handleTimePeriod(int choice) {
    switch (choice) {
        case 1:
            displayHistory(1);
            break;
        case 2:
            displayHistory(2);
            break;
        case 3:
            displayHistory(3);
            break;
        case 4:
            displayHistory(4);
            break;
        case 5:
            displayHistory(5);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

// Function to display historical facts about selected period
void displayHistory(int period) {
    switch (period) {
        case 1:
            printf("Welcome to the Prehistoric Era!\n");
            printf("You will see early humans, their tools, and cave paintings.\n");
            break;
        case 2:
            printf("Welcome to Ancient Egypt!\n");
            printf("You will encounter the Pyramids, Pharaohs, and the Nile River.\n");
            break;
        case 3:
            printf("Welcome to the Middle Ages!\n");
            printf("Knights, castles, and feudal systems are prevalent here.\n");
            break;
        case 4:
            printf("Welcome to the Industrial Revolution!\n");
            printf("Witness the era of invention, steam engines, and factories.\n");
            break;
        case 5:
            printf("Welcome to the Modern Day!\n");
            printf("You are surrounded by technology, globalization, and space travel!\n");
            break;
        default:
            printf("This time period is not recognized...\n");
            break;
    }
}