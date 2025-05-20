//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_YEARS 10
#define HISTORY_SIZE 100

// Structure to store time travel log
typedef struct {
    int year;
    char event_description[100];
} TimeTravelLog;

void display_menu() {
    printf("*********************************\n");
    printf("* Welcome to the Time Travel Simulator! *\n");
    printf("*********************************\n");
    printf("1. Travel to a year\n");
    printf("2. View Time Travel Log\n");
    printf("3. Exit\n");
}

void log_time_travel(TimeTravelLog *log, int *log_count, int year, const char *event) {
    if (*log_count < HISTORY_SIZE) {
        log[*log_count].year = year;
        strncpy(log[*log_count].event_description, event, sizeof(log[*log_count].event_description) - 1);
        log[*log_count].event_description[sizeof(log[*log_count].event_description) - 1] = '\0'; // Null-terminate
        (*log_count)++;
    } else {
        printf("Log is full! Cannot log more events.\n");
    }
}

void view_time_travel_log(TimeTravelLog *log, int log_count) {
    printf("Time Travel Log:\n");
    for (int i = 0; i < log_count; i++) {
        printf("Year: %d, Event: %s\n", log[i].year, log[i].event_description);
    }
}

int main() {
    int choice;
    TimeTravelLog log[HISTORY_SIZE];
    int log_count = 0;

    printf("Initializing Time Machine...\n");
    printf("Time Machine Ready! You can now travel through time!\n");

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year;
                char event_description[100];

                printf("Enter the year you want to travel to (e.g., 2023, 1885, etc.): ");
                scanf("%d", &year);
                
                // Simulate some historical events
                if (year < 0) {
                    printf("Invalid year! Must be a positive integer.\n");
                    break;
                }

                if (year >= 2000 && year < 2023) {
                    sprintf(event_description, "You traveled to the year %d. Enjoy the modern technology!", year);
                } else if (year >= 1980 && year < 2000) {
                    sprintf(event_description, "You traveled to the year %d. Welcome to the Age of the Internet!", year);
                } else if (year >= 1960 && year < 1980) {
                    sprintf(event_description, "You traveled to the year %d. Experience the Hippie Movement!", year);
                } else if (year >= 1950 && year < 1960) {
                    sprintf(event_description, "You traveled to the year %d. The era of Rock and Roll!", year);
                } else if (year < 1950) {
                    sprintf(event_description, "You traveled to the year %d. A world of vintage elegance!", year);
                }

                printf("%s\n", event_description);
                log_time_travel(log, &log_count, year, event_description);
                break;
            }
            case 2:
                view_time_travel_log(log, log_count);
                break;
            case 3:
                printf("Exiting Time Travel Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
        printf("\n");
    } while (choice != 3);

    return 0;
}