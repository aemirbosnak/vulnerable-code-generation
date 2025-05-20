//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MIN_YEARS -100
#define CURRENT_YEAR 2023

void show_menu() {
    printf("=================================\n");
    printf("      Time Travel Simulator      \n");
    printf("=================================\n");
    printf("1. Travel Forward in Time\n");
    printf("2. Travel Backward in Time\n");
    printf("3. Show Current Year\n");
    printf("4. Exit\n");
    printf("=================================\n");
}

int travel_time(int years) {
    int new_year = CURRENT_YEAR + years;
    if (new_year > CURRENT_YEAR + MAX_YEARS || new_year < CURRENT_YEAR + MIN_YEARS) {
        printf("Time travel exceeds limits!\n");
        return CURRENT_YEAR;
    }
    return new_year;
}

void display_current_year(int year) {
    printf("You are currently in the year: %d\n", year);
}

int main() {
    int choice;
    int current_year = CURRENT_YEAR;
    int travel_by;

    printf("Welcome to the Time Travel Simulator!\n");
    
    while (1) {
        show_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of years to travel forward (max %d, min %d): ",
                       MAX_YEARS, MIN_YEARS);
                scanf("%d", &travel_by);
                current_year = travel_time(travel_by);
                display_current_year(current_year);
                break;

            case 2:
                printf("Enter the number of years to travel backward (max %d, min %d): ",
                       MAX_YEARS, MIN_YEARS);
                scanf("%d", &travel_by);
                current_year = travel_time(-travel_by);
                display_current_year(current_year);
                break;

            case 3:
                display_current_year(current_year);
                break;

            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);

            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}