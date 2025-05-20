//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 10000
#define MAX_EVENTS 100

typedef struct {
    char description[256];
    int year;
} TimeEvent;

TimeEvent timeline[MAX_EVENTS];
int event_count = 0;

// Function to simulate time travel and record events
void time_travel(int target_year) {
    if (event_count >= MAX_EVENTS) {
        printf("Event log is full. Can't record new events!\n");
        return;
    }
    
    // Simulate a random event in the target year
    snprintf(timeline[event_count].description, sizeof(timeline[event_count].description), 
             "Visited the year %d, experiencing the wonders of time!", target_year);
    timeline[event_count].year = target_year;
    event_count++;
    
    printf("Time travel successful! You've arrived in the year %d.\n", target_year);
}

// Function to display all time travel events
void display_events() {
    if (event_count == 0) {
        printf("No events recorded in your time travel log.\n");
        return;
    }
    
    printf("Your Time Travel Log:\n");
    for (int i = 0; i < event_count; i++) {
        printf("Year: %d - Event: %s\n", timeline[i].year, timeline[i].description);
    }
}

// Function to generate a random year between 1 and 9999
int generate_random_year() {
    return rand() % (MAX_YEARS - 1) + 1; // Ensure we don't hit year 0
}

// Function to interact with the user
void user_interface() {
    int choice;

    while (1) {
        printf("\n--- Time Travel Simulator ---\n");
        printf("1. Travel to a random year\n");
        printf("2. Travel to a specific year\n");
        printf("3. Display time travel log\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                time_travel(generate_random_year());
                break;
            case 2: {
                int specific_year;
                printf("Enter the year you want to travel to (1-9999): ");
                scanf("%d", &specific_year);
                if (specific_year < 1 || specific_year > 9999) {
                    printf("Invalid year! Please select a year between 1 and 9999.\n");
                } else {
                    time_travel(specific_year);
                }
                break;
            }
            case 3:
                display_events();
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. See you in the future!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    printf("Welcome to the Time Travel Simulator!\n");
    user_interface();
    
    return 0;
}