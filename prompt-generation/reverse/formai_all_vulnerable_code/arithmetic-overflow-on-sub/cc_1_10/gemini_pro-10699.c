//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 1000000000

typedef struct {
    time_t timestamp;
    int years;
    int months;
    int days;
    int hours;
    int minutes;
    int seconds;
} TimeTravelRecord;

void time_travel(TimeTravelRecord *record, int years, int months, int days, int hours, int minutes, int seconds) {
    record->years += years;
    record->months += months;
    record->days += days;
    record->hours += hours;
    record->minutes += minutes;
    record->seconds += seconds;

    // Ensure time is within valid range
    if (record->seconds >= 60) {
        record->seconds -= 60;
        record->minutes++;
    }
    if (record->minutes >= 60) {
        record->minutes -= 60;
        record->hours++;
    }
    if (record->hours >= 24) {
        record->hours -= 24;
        record->days++;
    }
    if (record->days >= 30) {
        record->days -= 30;
        record->months++;
    }
    if (record->months >= 12) {
        record->months -= 12;
        record->years++;
    }

    // Limit time travel to within acceptable range
    if (record->timestamp + MAX_TIME_TRAVEL < record->timestamp) {
        record->timestamp = record->timestamp + MAX_TIME_TRAVEL;
    } else if (record->timestamp - MAX_TIME_TRAVEL > record->timestamp) {
        record->timestamp = record->timestamp - MAX_TIME_TRAVEL;
    }
}

int main() {
    TimeTravelRecord record;
    int choice;

    // Initialize time travel record
    record.timestamp = time(NULL);
    record.years = 0;
    record.months = 0;
    record.days = 0;
    record.hours = 0;
    record.minutes = 0;
    record.seconds = 0;

    // Time travel menu
    while (1) {
        printf("Time Travel Simulator\n");
        printf("---------------------\n");
        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Display current time\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter years: ");
                scanf("%d", &record.years);
                printf("Enter months: ");
                scanf("%d", &record.months);
                printf("Enter days: ");
                scanf("%d", &record.days);
                printf("Enter hours: ");
                scanf("%d", &record.hours);
                printf("Enter minutes: ");
                scanf("%d", &record.minutes);
                printf("Enter seconds: ");
                scanf("%d", &record.seconds);

                time_travel(&record, record.years, record.months, record.days, record.hours, record.minutes, record.seconds);
                printf("Time traveled to: %s\n", ctime(&record.timestamp));
                break;
            case 2:
                printf("Enter years: ");
                scanf("%d", &record.years);
                printf("Enter months: ");
                scanf("%d", &record.months);
                printf("Enter days: ");
                scanf("%d", &record.days);
                printf("Enter hours: ");
                scanf("%d", &record.hours);
                printf("Enter minutes: ");
                scanf("%d", &record.minutes);
                printf("Enter seconds: ");
                scanf("%d", &record.seconds);

                time_travel(&record, -record.years, -record.months, -record.days, -record.hours, -record.minutes, -record.seconds);
                printf("Time traveled to: %s\n", ctime(&record.timestamp));
                break;
            case 3:
                printf("Current time: %s\n", ctime(&record.timestamp));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}