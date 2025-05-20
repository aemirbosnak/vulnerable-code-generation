//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 5
#define MAX_YEARS 10

typedef struct {
    int year;
    char event[256];
} HistoricalEvent;

HistoricalEvent events[MAX_YEARS] = {
    {1776, "American Declaration of Independence"},
    {1865, "End of the American Civil War"},
    {1914, "Start of World War I"},
    {1969, "Apollo 11 Moon Landing"},
    {1989, "Fall of the Berlin Wall"}
};

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a year to travel to:\n");
    for (int i = 0; i < MAX_YEARS; i++) {
        printf("%d. %d\n", i + 1, events[i].year);
    }
    printf("6. Exit\n");
}

void displayEvent(int yearIndex) {
    if (yearIndex < 0 || yearIndex >= MAX_YEARS) {
        printf("Invalid selection! Please choose a valid year.\n");
        return;
    }
    
    printf("You have traveled to the year %d.\n", events[yearIndex].year);
    printf("Event: %s\n", events[yearIndex].event);
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        if (choice == 6) {
            printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
            break;
        } else {
            displayEvent(choice - 1);
        }
    }
    
    return 0;
}