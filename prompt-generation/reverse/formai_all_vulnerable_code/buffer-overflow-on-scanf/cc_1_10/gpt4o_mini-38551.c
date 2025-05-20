//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

void displayDate(Date date) {
    printf("You are in the year %d, month %d, day %d\n", date.year, date.month, date.day);
}

Date travelTo(int year, int month, int day) {
    Date newDate;
    newDate.year = year;
    newDate.month = month;
    newDate.day = day;
    return newDate;
}

void showMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to a specific date\n");
    printf("2. Go back to the present\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    Date currentDate = {2023, 10, 5}; // Assuming the current date is October 5, 2023
    Date travelDate;
    int choice, year, month, day;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                printf("Enter the month (1-12): ");
                scanf("%d", &month);
                printf("Enter the day (1-31): ");
                scanf("%d", &day);

                // Validate date (rough validation)
                if (month < 1 || month > 12 || day < 1 || day > 31 ||
                    (month == 2 && day > 29) || 
                    ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
                    printf("Invalid date! Please try again.\n");
                    break;
                }

                travelDate = travelTo(year, month, day);
                displayDate(travelDate);
                break;

            case 2:
                displayDate(currentDate);
                break;

            case 3:
                printf("Thank you for using the Time Travel Simulator! Goodbye.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }

    return 0;
}