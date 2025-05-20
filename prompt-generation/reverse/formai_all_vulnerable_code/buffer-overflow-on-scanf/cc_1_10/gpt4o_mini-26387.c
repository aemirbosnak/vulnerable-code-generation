//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIPS 5

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    char destination[50];
} Trip;

typedef struct {
    Trip trips[MAX_TRIPS];
    int trip_count;
} TimeMachine;

void initialize_time_machine(TimeMachine* tm) {
    tm->trip_count = 0;
}

void add_trip(TimeMachine* tm, int year, int month, int day, const char* destination) {
    if (tm->trip_count < MAX_TRIPS) {
        tm->trips[tm->trip_count].date.year = year;
        tm->trips[tm->trip_count].date.month = month;
        tm->trips[tm->trip_count].date.day = day;
        strncpy(tm->trips[tm->trip_count].destination, destination, sizeof(tm->trips[tm->trip_count].destination) - 1);
        tm->trip_count++;
    } else {
        printf("Trip limit reached. Cannot add more trips.\n");
    }
}

void display_trips(const TimeMachine* tm) {
    if (tm->trip_count == 0) {
        printf("No trips recorded yet.\n");
        return;
    }
    
    printf("Recorded Time Travel Trips:\n");
    for (int i = 0; i < tm->trip_count; i++) {
        printf("Trip %d: %d-%02d-%02d to %s\n", 
               i + 1, 
               tm->trips[i].date.year, 
               tm->trips[i].date.month, 
               tm->trips[i].date.day, 
               tm->trips[i].destination);
    }
}

void time_travel(const Trip* trip) {
    printf("Preparing for time travel...\n");
    printf("Traveling to %d-%02d-%02d at %s...\n", 
           trip->date.year, 
           trip->date.month, 
           trip->date.day, 
           trip->destination);
    // Simulate time travel with sleep
    for (int i = 0; i < 3; i++) {
        printf("...\n");
        sleep(1); // Pause for a moment
    }
    printf("You have successfully arrived at your destination: %s\n", trip->destination);
}

int main() {
    TimeMachine tm;
    initialize_time_machine(&tm);
    
    int choice;
    do {
        printf("\nTime Travel Simulator\n");
        printf("1. Add a Trip\n");
        printf("2. Display Trips\n");
        printf("3. Time Travel\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int year, month, day;
                char destination[50];
                printf("Enter Year: ");
                scanf("%d", &year);
                printf("Enter Month: ");
                scanf("%d", &month);
                printf("Enter Day: ");
                scanf("%d", &day);
                printf("Enter Destination: ");
                scanf("%s", destination);
                add_trip(&tm, year, month, day, destination);
                break;
            }
            case 2:
                display_trips(&tm);
                break;
            case 3: {
                int trip_num;
                display_trips(&tm);
                printf("Enter trip number to travel to: ");
                scanf("%d", &trip_num);
                if (trip_num > 0 && trip_num <= tm.trip_count) {
                    time_travel(&tm.trips[trip_num - 1]);
                } else {
                    printf("Invalid trip number.\n");
                }
                break;
            }
            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid option. Please choose from 1-4.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}