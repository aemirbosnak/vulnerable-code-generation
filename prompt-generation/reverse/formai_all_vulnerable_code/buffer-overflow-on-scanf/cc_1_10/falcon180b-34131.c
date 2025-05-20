//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000
#define ERROR_MESSAGE "Error: Invalid date range.\n"

void print_menu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Travel to a specific year\n");
    printf("2. Travel to a random year\n");
    printf("3. Exit\n");
}

int main() {
    srand(time(NULL));
    int choice;
    int year;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to (between %d and %d): ", MIN_YEAR, MAX_YEAR);
                scanf("%d", &year);

                if (year < MIN_YEAR || year > MAX_YEAR) {
                    printf(ERROR_MESSAGE);
                } else {
                    printf("You are now in the year %d!\n", year);
                }
                break;

            case 2:
                year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
                printf("You have traveled to the year %d!\n", year);
                break;

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}