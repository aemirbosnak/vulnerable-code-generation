//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000

int main() {
    int current_year, destination_year;
    char choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current year: ");
    scanf("%d", &current_year);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("A. Travel to the future\n");
        printf("B. Travel to the past\n");
        printf("C. Exit program\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter the destination year (between %d and %d): ", current_year, MAX_YEAR);
                scanf("%d", &destination_year);
                if (destination_year < current_year || destination_year > MAX_YEAR) {
                    printf("Invalid destination year. Please try again.\n");
                } else {
                    printf("Traveling to the year %d...\n", destination_year);
                    printf("Welcome to the year %d!\n", destination_year);
                    current_year = destination_year;
                }
                break;
            case 'B':
                printf("Enter the destination year (between %d and %d): ", current_year, MIN_YEAR);
                scanf("%d", &destination_year);
                if (destination_year < MIN_YEAR || destination_year > current_year) {
                    printf("Invalid destination year. Please try again.\n");
                } else {
                    printf("Traveling back to the year %d...\n", destination_year);
                    printf("Welcome to the year %d!\n", destination_year);
                    current_year = destination_year;
                }
                break;
            case 'C':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}