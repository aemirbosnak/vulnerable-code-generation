//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TRIPS 100
#define MAX_YEAR 9999
#define MIN_YEAR 0

typedef struct {
    int year;
    int month;
    int day;
    char event[100];
} TimeTravelEvent;

typedef struct {
    TimeTravelEvent trips[MAX_TRIPS];
    int tripCount;
} TimeMachine;

void initializeTimeMachine(TimeMachine* tm) {
    tm->tripCount = 0;
}

int validateDate(int year, int month, int day) {
    if (year < MIN_YEAR || year > MAX_YEAR) return 0;
    if (month < 1 || month > 12) return 0;

    int daysInMonth;
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31;
            break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29; // Leap year
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            return 0;
    }
    return day >= 1 && day <= daysInMonth;
}

void travelToThePast(TimeMachine* tm) {
    if (tm->tripCount >= MAX_TRIPS) {
        printf("Time Machine has reached maximum trip limit!\n");
        return;
    }
    
    int year, month, day;
    char event[100];

    printf("Enter year (YYYY): ");
    scanf("%d", &year);
    printf("Enter month (MM): ");
    scanf("%d", &month);
    printf("Enter day (DD): ");
    scanf("%d", &day);

    if (!validateDate(year, month, day)) {
        printf("Invalid date! Please try again.\n");
        return;
    }

    printf("What event would you like to record for the trip? ");
    getchar(); // to consume newline
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = '\0'; // removes trailing newline

    TimeTravelEvent newEvent = {year, month, day};
    strncpy(newEvent.event, event, sizeof(newEvent.event));
    tm->trips[tm->tripCount++] = newEvent;

    printf("Travelled back to %d-%02d-%02d: %s\n", year, month, day, newEvent.event);
}

void showTrips(TimeMachine* tm) {
    if (tm->tripCount == 0) {
        printf("No trips have been recorded.\n");
        return;
    }

    printf("Recorded Travel Trips:\n");
    for (int i = 0; i < tm->tripCount; ++i) {
        TimeTravelEvent trip = tm->trips[i];
        printf("Trip %d: %d-%02d-%02d -> Event: %s\n", i + 1, trip.year, trip.month, trip.day, trip.event);
    }
}

void travelToTheFuture(TimeMachine* tm) {
    if (tm->tripCount >= MAX_TRIPS) {
        printf("Time Machine has reached maximum trip limit!\n");
        return;
    }
    
    int year, month, day;
    char event[100];

    printf("Enter year (YYYY): ");
    scanf("%d", &year);
    printf("Enter month (MM): ");
    scanf("%d", &month);
    printf("Enter day (DD): ");
    scanf("%d", &day);

    if (!validateDate(year, month, day)) {
        printf("Invalid date! Please try again.\n");
        return;
    }

    printf("What event would you like to record for the trip? ");
    getchar(); // to consume newline
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = '\0'; // removes trailing newline

    TimeTravelEvent newEvent = {year, month, day};
    strncpy(newEvent.event, event, sizeof(newEvent.event));
    tm->trips[tm->tripCount++] = newEvent;

    printf("Travelled forward to %d-%02d-%02d: %s\n", year, month, day, newEvent.event);
}

int main() {
    TimeMachine tm;
    initializeTimeMachine(&tm);
    
    int choice;
    do {
        printf("\n** Time Travel Simulator **\n");
        printf("1. Travel to the Past\n");
        printf("2. Travel to the Future\n");
        printf("3. Show Recorded Trips\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToThePast(&tm);
                break;
            case 2:
                travelToTheFuture(&tm);
                break;
            case 3:
                showTrips(&tm);
                break;
            case 4:
                printf("Exiting the simulator. Happy time traveling!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}