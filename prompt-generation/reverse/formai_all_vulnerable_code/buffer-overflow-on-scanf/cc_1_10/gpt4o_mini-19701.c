//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HISTORY 100

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char description[256];
} TimeTravelEntry;

typedef struct {
    TimeTravelEntry history[MAX_HISTORY];
    int count;
} TimeTravelHistory;

TimeTravelHistory history;

// Function to initialize time travel history
void initializeHistory() {
    history.count = 0;
}

// Function to display the options
void displayOptions() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Travel to a specific date\n");
    printf("2. Display travel history\n");
    printf("3. Reset travel history\n");
    printf("4. Exit\n");
}

// Function to input a date
Date inputDate() {
    Date d;
    printf("Enter year: ");
    scanf("%d", &d.year);
    printf("Enter month (1-12): ");
    scanf("%d", &d.month);
    printf("Enter day (1-31): ");
    scanf("%d", &d.day);
    return d;
}

// Function to validate a date
int validateDate(Date d) {
    if (d.year < 0 || d.month < 1 || d.month > 12 || d.day < 1 || d.day > 31) {
        return 0;
    }

    // Simple month-day validation
    if ((d.month == 2 && d.day > 29) || 
        (d.month == 2 && d.day == 29 && (d.year % 4 != 0)) || 
        ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day > 30)) {
        return 0;
    }
    return 1;
}

// Function to add a time travel entry
void addTimeTravelEntry(Date d, const char *description) {
    if (history.count < MAX_HISTORY) {
        history.history[history.count].date = d;
        strncpy(history.history[history.count].description, description, sizeof(history.history[history.count].description) - 1);
        history.history[history.count].description[sizeof(history.history[history.count].description) - 1] = '\0'; // Null-terminate
        history.count++;
    } else {
        printf("Travel history is full! Unable to add more entries.\n");
    }
}

// Function to show travel history
void displayHistory() {
    if (history.count == 0) {
        printf("Travel history is empty.\n");
    } else {
        printf("Travel History:\n");
        for (int i = 0; i < history.count; i++) {
            printf("%d. Travelled to %04d-%02d-%02d: %s\n", 
                   i + 1, 
                   history.history[i].date.year, 
                   history.history[i].date.month, 
                   history.history[i].date.day, 
                   history.history[i].description);
        }
    }
}

// Main function to run the simulator
int main() {
    int option;
    initializeHistory();

    while (1) {
        displayOptions();
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                Date d = inputDate();
                if (validateDate(d)) {
                    printf("Time travelling to %04d-%02d-%02d...\n", d.year, d.month, d.day);
                    char description[256];
                    snprintf(description, sizeof(description), "Visited date: %04d-%02d-%02d", d.year, d.month, d.day);
                    addTimeTravelEntry(d, description);
                } else {
                    printf("Invalid date entered!\n");
                }
                break;
            }
            case 2:
                displayHistory();
                break;
            case 3:
                initializeHistory();
                printf("Travel history has been reset.\n");
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }
    return 0;
}