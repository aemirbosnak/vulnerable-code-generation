//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void travelToTime(int year, int month, int day);
void viewCurrentDate();
void setTimeTravelDestination(int *year, int *month, int *day);
void timeTravel(int year, int month, int day);
void displayTravelInfo(int year, int month, int day);

int main() {
    int choice;
    int year = 2023, month = 10, day = 1; // Start date: 1st October 2023
    
    while (1) {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewCurrentDate();
                break;
            case 2:
                printf("Setting time travel destination...\n");
                setTimeTravelDestination(&year, &month, &day);
                travelToTime(year, month, day);
                break;
            case 3:
                printf("Exiting the Time Travel Simulator...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("1. View Current Date\n");
    printf("2. Travel to a Specific Date\n");
    printf("3. Exit\n");
}

void viewCurrentDate() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    printf("Current date: %02d-%02d-%04d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
}

void setTimeTravelDestination(int *year, int *month, int *day) {
    printf("Enter target year: ");
    scanf("%d", year);
    printf("Enter target month (1-12): ");
    scanf("%d", month);
    printf("Enter target day (1-31): ");
    scanf("%d", day);

    // Input validation
    if (*month < 1 || *month > 12 || *day < 1 || *day > 31) {
        printf("Invalid date. Please enter a correct date.\n");
        *year = 2023; *month = 10; *day = 1; // reset to current date
    }
}

void travelToTime(int year, int month, int day) {
    printf("Traveling to %02d-%02d-%d...\n", day, month, year);
    timeTravel(year, month, day);
}

void timeTravel(int year, int month, int day) {
    printf("You have arrived in the year %d on %02d-%02d.\n",
           year, month, day);
    displayTravelInfo(year, month, day);
}

void displayTravelInfo(int year, int month, int day) {
    printf("Travel Info:\n");
    printf("Year: %d\n", year);
    printf("Month: %02d\n", month);
    printf("Day: %02d\n", day);

    // Optional feature: display what happened on this day
    printf("Events of %02d-%02d-%d:\n", day, month, year);
    
    // Example events; in a real app, you might pull this from a database
    if (year == 1969 && month == 7 && day == 20) {
        printf("- First Moon Landing!\n");
    } else if (year == 1989 && month == 11 && day == 9) {
        printf("- Fall of the Berlin Wall.\n");
    } else if (year == 2000 && month == 1 && day == 1) {
        printf("- Start of the new millennium!\n");
    } else {
        printf("- No significant events recorded on this date.\n");
    }
}