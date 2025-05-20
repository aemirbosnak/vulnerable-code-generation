//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEAR_START 1900
#define YEAR_END 2100
#define TIME_TRAVEL_OPTIONS 5

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayCurrentDate(Date date) {
    printf("Current Date: %04d-%02d-%02d\n", date.year, date.month, date.day);
}

void travelToDate(Date *date, int years, int months, int days) {
    date->year += years;
    date->month += months;
    if (date->month > 12) {
        date->year += date->month / 12;
        date->month = date->month % 12;
    }
    date->day += days;
    // Simple day overflow checking
    if (date->day > 30) { // Assuming maximum of 30 days for simplicity
        date->month += date->day / 30;
        date->day = date->day % 30;
        if (date->month > 12) {
            date->year += date->month / 12;
            date->month = date->month % 12;
        }
    }
    if (date->year < YEAR_START || date->year > YEAR_END) {
        printf("You have traveled out of bounds! Resetting to boundary.\n");
        date->year = (date->year < YEAR_START) ? YEAR_START : YEAR_END;
        date->month = 1;
        date->day = 1;
    }
}

void displayTravelOptions() {
    printf("Choose a time travel option:\n");
    printf("1. Go forward in time\n");
    printf("2. Go backward in time\n");
    printf("3. Jump to a specific date\n");
    printf("4. Display a random historical event\n");
    printf("5. Exit\n");
}

void displayRandomEvent() {
    const char *events[] = {
        "1969: Apollo 11 lands on the Moon.",
        "1989: Fall of the Berlin Wall.",
        "2001: Wikipedia is launched.",
        "2020: COVID-19 pandemic begins.",
        "1994: First version of the popular web browser."
    };
    int index = rand() % (sizeof(events) / sizeof(events[0]));
    printf("Random Historical Event: %s\n", events[index]);
}

int main() {
    srand(time(NULL));

    Date currentDate = {2023, 10, 8};
    int choice, years, months, days;

    printf("Welcome to the Time Travel Simulator!\n");

    while (1) {
        displayCurrentDate(currentDate);
        displayTravelOptions();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Go forward in time
                printf("Enter years, months, and days to travel forward: ");
                scanf("%d %d %d", &years, &months, &days);
                travelToDate(&currentDate, years, months, days);
                break;
            case 2: // Go backward in time
                printf("Enter years, months, and days to travel backward: ");
                scanf("%d %d %d", &years, &months, &days);
                travelToDate(&currentDate, -years, -months, -days);
                break;
            case 3: // Jump to a specific date
                printf("Enter year, month, and day to jump to: ");
                scanf("%d %d %d", &currentDate.year, &currentDate.month, &currentDate.day);
                if (currentDate.year < YEAR_START || currentDate.year > YEAR_END) {
                    printf("Invalid date entered! Please stay within the bounds of %d and %d.\n", YEAR_START, YEAR_END);
                }
                break;
            case 4: // Display a random historical event
                displayRandomEvent();
                break;
            case 5: // Exit
                printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}