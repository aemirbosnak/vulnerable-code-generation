//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_YEARS 10000
#define CURRENT_YEAR 2023
#define MAX_EVENTS 100

typedef struct {
    int year;
    char description[256];
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int count;
} EventList;

void initializeEventList(EventList *list) {
    list->count = 0;
}

void addEvent(EventList *list, int year, const char *description) {
    if (list->count < MAX_EVENTS) {
        list->events[list->count].year = year;
        strncpy(list->events[list->count].description, description, sizeof(list->events[list->count].description) - 1);
        list->events[list->count].description[sizeof(list->events[list->count].description) - 1] = '\0';  // Ensure null-termination
        list->count++;
    } else {
        printf("Event list is full. Cannot add more events.\n");
    }
}

void viewEvents(const EventList *list) {
    printf("\n--- Events in the Time Travel Simulator ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("Year: %d - Event: %s\n", list->events[i].year, list->events[i].description);
    }
    printf("-------------------------------------------\n");
}

int travelToYear(int targetYear) {
    int timeTravelDuration = targetYear - CURRENT_YEAR;
    
    if (timeTravelDuration > MAX_YEARS || timeTravelDuration < -MAX_YEARS) {
        printf("Time travel to the year %d is not possible within the limits.\n", targetYear);
        return -1;
    }
    
    printf("Time traveling to the year %d...\n", targetYear);
    sleep(2); // Simulate time travel with a delay
    return targetYear;
}

void showMenu() {
    printf("\n--- Time Travel Simulator Menu ---\n");
    printf("1. Travel to a Year\n");
    printf("2. Add an Event\n");
    printf("3. View Events\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
}

int main() {
    EventList eventList;
    initializeEventList(&eventList);
    
    int choice;
    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                int year;
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                int result = travelToYear(year);
                if (result != -1) {
                    printf("You have arrived in the year %d!\n", result);
                }
                break;
            }
            case 2: {
                int year;
                char description[256];
                printf("Enter the year of the event: ");
                scanf("%d", &year);
                printf("Enter the event description: ");
                getchar(); // Clear newline
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove trailing newline
                addEvent(&eventList, year, description);
                break;
            }
            case 3:
                viewEvents(&eventList);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}