//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 3000
#define MIN_YEARS 1000
#define MAX_TRAVELS 5

typedef struct {
    int year;
    char event[100];
} TimeEvent;

void displayMenu();
void travelInTime(int *current_year);
void documentEvent(int year, TimeEvent events[], int *event_count);
void viewEvents(TimeEvent events[], int event_count);

int main() {
    int current_year = 2023;
    TimeEvent events[MAX_TRAVELS];
    int event_count = 0;
    char choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current Year: %d\n", current_year);
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                travelInTime(&current_year);
                break;
            case '2':
                if (event_count < MAX_TRAVELS) {
                    documentEvent(current_year, events, &event_count);
                } else {
                    printf("Event documentation full! Max limit reached.\n");
                }
                break;
            case '3':
                viewEvents(events, event_count);
                break;
            case '4':
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }

    return 0;
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Travel in Time\n");
    printf("2. Document a Time Event\n");
    printf("3. View Time Events\n");
    printf("4. Exit\n");
}

void travelInTime(int *current_year) {
    int destination_year;
    printf("Enter the year you want to travel to (between %d and %d): ", MIN_YEARS, MAX_YEARS);
    scanf("%d", &destination_year);

    if (destination_year < MIN_YEARS || destination_year > MAX_YEARS) {
        printf("Invalid year! Please choose a year between %d and %d.\n", MIN_YEARS, MAX_YEARS);
        return;
    }

    printf("Activating time travel to the year %d...\n", destination_year);
    sleep(2); // Simulate time travel delay
    printf("Welcome to the year %d! Prepare for a thrilling adventure!\n", destination_year);
    
    *current_year = destination_year;
}

void documentEvent(int year, TimeEvent events[], int *event_count) {
    char event_description[100];

    printf("Document an event that occurred in %d: ", year);
    getchar();  // Consume newline character
    fgets(event_description, sizeof(event_description), stdin);
    event_description[strcspn(event_description, "\n")] = 0; // Remove newline

    events[*event_count].year = year;
    strcpy(events[*event_count].event, event_description);
    (*event_count)++;

    printf("Event documented successfully!\n");
}

void viewEvents(TimeEvent events[], int event_count) {
    printf("Time Events Documented:\n");
    if (event_count == 0) {
        printf("No events documented yet!\n");
        return;
    }

    for (int i = 0; i < event_count; i++) {
        printf("Year: %d - Event: %s\n", events[i].year, events[i].event);
    }
}