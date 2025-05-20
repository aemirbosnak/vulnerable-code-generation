//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_DESCRIPTION_LENGTH 256

typedef struct {
    int year;
    int month;
    int day;
    char description[MAX_DESCRIPTION_LENGTH];
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int eventCount;
} TimeTravelSimulator;

void initializeSimulator(TimeTravelSimulator *simulator) {
    simulator->eventCount = 0;
}

void addEvent(TimeTravelSimulator *simulator, int year, int month, int day, const char *description) {
    if (simulator->eventCount < MAX_EVENTS) {
        simulator->events[simulator->eventCount].year = year;
        simulator->events[simulator->eventCount].month = month;
        simulator->events[simulator->eventCount].day = day;
        strncpy(simulator->events[simulator->eventCount].description, description, MAX_DESCRIPTION_LENGTH - 1);
        simulator->events[simulator->eventCount].description[MAX_DESCRIPTION_LENGTH - 1] = '\0'; // ensuring null-termination
        simulator->eventCount++;
        printf("Event added: %s on %02d/%02d/%d\n", description, day, month, year);
    } else {
        printf("Event limit reached! Cannot add more events.\n");
    }
}

void listEvents(const TimeTravelSimulator *simulator) {
    printf("\nUpcoming Events:\n");
    for (int i = 0; i < simulator->eventCount; i++) {
        printf("%02d/%02d/%d - %s\n", simulator->events[i].day, simulator->events[i].month, simulator->events[i].year, simulator->events[i].description);
    }
}

void simulateTimeTravel(const TimeTravelSimulator *simulator, int travelYear) {
    printf("\nTraveling to the year %d...\n", travelYear);
    for (int i = 0; i < simulator->eventCount; i++) {
        if (simulator->events[i].year == travelYear) {
            printf("In %d: %s\n", travelYear, simulator->events[i].description);
        }
    }
    printf("Time travel complete!\n");
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void displayDate(int year, int month, int day) {
    char *months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    printf("%s %d, %d\n", months[month - 1], day, year);
}

int main() {
    TimeTravelSimulator simulator;
    initializeSimulator(&simulator);

    int choice;
    do {
        printf("\nTime Travel Simulator Menu:\n");
        printf("1. Add Event\n");
        printf("2. List Events\n");
        printf("3. Travel to Year\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            // Invalid input handling
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Discard invalid input
            choice = 0; // Reset choice to keep the loop going
        }

        switch (choice) {
            case 1: {
                int year, month, day;
                char description[MAX_DESCRIPTION_LENGTH];
                printf("Enter event year (YYYY): ");
                scanf("%d", &year);
                printf("Enter event month (1-12): ");
                scanf("%d", &month);
                printf("Enter event day (1-31): ");
                scanf("%d", &day);
                printf("Enter event description: ");
                getchar(); // to clear newline from buffer
                fgets(description, MAX_DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = 0; // remove trailing newline
                addEvent(&simulator, year, month, day, description);
                break;
            }
            case 2:
                listEvents(&simulator);
                break;
            case 3: {
                int travelYear;
                printf("Enter year to travel to: ");
                scanf("%d", &travelYear);
                simulateTimeTravel(&simulator, travelYear);
                break;
            }
            case 4:
                printf("Exiting Time Travel Simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}