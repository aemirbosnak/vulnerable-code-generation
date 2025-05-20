//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 1000

// Function prototypes
void travel_through_time(int *current_year);
void display_current_year(int current_year);

int main() {
    int current_year = 0;
    int choice;

    do {
        printf("\nWelcome to the Medieval Time Travel Simulator!\n");
        printf("You are currently in the year %d.\n", current_year);
        printf("What would you like to do?\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. Display current year\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                travel_through_time(&current_year);
                break;
            case 2:
                travel_through_time(&current_year);
                break;
            case 3:
                display_current_year(current_year);
                break;
            case 4:
                printf("Farewell, time traveler!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}

void travel_through_time(int *current_year) {
    int direction;
    int years_traveled;

    printf("How many years do you wish to travel? ");
    scanf("%d", &years_traveled);

    printf("In which direction do you wish to travel?\n1. Forward\n2. Backward\n");
    scanf("%d", &direction);

    *current_year += direction * years_traveled;

    if(*current_year < 0) {
        printf("You cannot travel back before the year 0!\n");
        *current_year = 0;
    } else if(*current_year > MAX_YEARS) {
        printf("You cannot travel forward beyond the year %d!\n", MAX_YEARS);
        *current_year = MAX_YEARS;
    }
}

void display_current_year(int current_year) {
    printf("The current year is %d.\n", current_year);
}