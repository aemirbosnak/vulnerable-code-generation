//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Structure to hold time travel data
typedef struct {
    int year;
    int month;
    int day;
} Time;

// Function to display the menu
void displayMenu() {
    printf("==== Time Travel Simulator ====\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Check current time\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

// Function to get the current date
Time getCurrentTime() {
    Time current;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current.year = tm.tm_year + 1900;
    current.month = tm.tm_mon + 1;
    current.day = tm.tm_mday;
    return current;
}

// Function to travel to the past
Time travelToPast(Time current) {
    int years;
    printf("Enter number of years to travel to the past: ");
    scanf("%d", &years);
    current.year -= years;
    printf("You have traveled to: %d-%02d-%02d\n", current.year, current.month, current.day);
    return current;
}

// Function to travel to the future
Time travelToFuture(Time current) {
    int years;
    printf("Enter number of years to travel to the future: ");
    scanf("%d", &years);
    current.year += years;
    printf("You have traveled to: %d-%02d-%02d\n", current.year, current.month, current.day);
    return current;
}

// Function to check the current time
void checkCurrentTime() {
    Time current = getCurrentTime();
    printf("Current time is: %d-%02d-%02d\n", current.year, current.month, current.day);
}

int main() {
    Time currentTime = getCurrentTime();
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                currentTime = travelToPast(currentTime);
                break;
            case 2:
                currentTime = travelToFuture(currentTime);
                break;
            case 3:
                checkCurrentTime();
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    
    return 0;
}