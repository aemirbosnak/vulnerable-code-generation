//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FUTURE 1
#define PAST -1
#define STAY 0

typedef struct {
    int year;
    int month;
    int day;
} Date;

void display_date(Date d) {
    printf("Current Time: %04d-%02d-%02d\n", d.year, d.month, d.day);
}

Date time_travel(Date current, int direction, int years) {
    Date newDate = current;

    if (direction == FUTURE) {
        newDate.year += years;
    } else if (direction == PAST) {
        newDate.year -= years;
    }

    // Simple normalization of the date
    if (newDate.month > 12) {
        newDate.year += newDate.month / 12;
        newDate.month %= 12;
    } else if (newDate.month < 1) {
        newDate.year += (newDate.month - 1) / 12 - 1;
        newDate.month = 12 + (newDate.month % 12);
    }

    return newDate;
}

void travel_menu() {
    printf("\nTime Travel Simulator\n");
    printf("1. Travel to the Future\n");
    printf("2. Travel to the Past\n");
    printf("3. Stay in the Present\n");
    printf("4. Exit\n");
}

int main() {
    Date currentDate;
    currentDate.year = 2023;
    currentDate.month = 10;
    currentDate.day = 22;

    int choice = STAY;
    int years;

    while (choice != 4) {
        display_date(currentDate);
        travel_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of years to travel to the future: ");
            scanf("%d", &years);
            currentDate = time_travel(currentDate, FUTURE, years);
        } else if (choice == 2) {
            printf("Enter number of years to travel to the past: ");
            scanf("%d", &years);
            currentDate = time_travel(currentDate, PAST, years);
        } else if (choice == 3) {
            printf("Staying in the Present.\n");
        } else if (choice == 4) {
            printf("Exiting the simulator, safe travels!\n");
        } else {
            printf("Invalid choice, try again.\n");
        }
        
        sleep(1);
    }
    
    return 0;
}