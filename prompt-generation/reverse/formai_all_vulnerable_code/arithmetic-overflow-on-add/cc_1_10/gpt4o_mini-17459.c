//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PAST  0
#define PRESENT 1
#define FUTURE 2

// Structure to represent time
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

// Function to validate time
bool is_valid_time(Time t) {
    if (t.year < 0 || t.month < 1 || t.month > 12 || t.day < 1 || t.day > 31) return false;
    if (t.month == 2) {
        // Check for leap year
        if ((t.year % 4 == 0 && t.year % 100 != 0) || (t.year % 400 == 0)) {
            if (t.day > 29) return false;
        } else {
            if (t.day > 28) return false;
        }
    } else if ((t.month == 4 || t.month == 6 || t.month == 9 || t.month == 11) && t.day > 30) {
        return false;
    }
    return true;
}

// Function to display current time
void display_time(Time t) {
    printf("Current time: %04d-%02d-%02d %02d:%02d:%02d\n", 
           t.year, t.month, t.day, t.hour, t.minute, t.second);
}

// Function to travel through time
void time_travel(Time *current_time, int direction, int amount) {
    if (direction == PAST) {
        current_time->year -= amount;
    } else if (direction == FUTURE) {
        current_time->year += amount;
    }
}

// Function to simulate time travel
void simulate_time_travel() {
    Time current_time;

    // Set initial time to now
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    
    current_time.year = local_time->tm_year + 1900;
    current_time.month = local_time->tm_mon + 1;
    current_time.day = local_time->tm_mday;
    current_time.hour = local_time->tm_hour;
    current_time.minute = local_time->tm_min;
    current_time.second = local_time->tm_sec;

    int choice, amount;
    // Main loop for the simulator
    while (true) {
        display_time(current_time);
        
        printf("\nTime Travel Simulator Menu:\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 3) break;

        printf("Enter the number of years to travel: ");
        scanf("%d", &amount);

        // Time travel logic
        if (choice == 1) {
            time_travel(&current_time, PAST, amount);
        } else if (choice == 2) {
            time_travel(&current_time, FUTURE, amount);
        }

        // Validate time
        if (!is_valid_time(current_time)) {
            printf("Warning: You've entered an invalid time!\n");
            current_time.year = local_time->tm_year + 1900; // Reset to current time
            current_time.month = local_time->tm_mon + 1;
            current_time.day = local_time->tm_mday;
            current_time.hour = local_time->tm_hour;
            current_time.minute = local_time->tm_min;
            current_time.second = local_time->tm_sec;
        }
    }
}

int main() {
    printf("Welcome to the C Time Travel Simulator!\n");
    simulate_time_travel();
    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}