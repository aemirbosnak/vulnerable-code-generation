//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_YEARS 5000

typedef struct {
    int year;
    int month;
    int day;
} Date;

void display_date(Date date) {
    printf("Traveling to: %04d-%02d-%02d\n", date.year, date.month, date.day);
}

Date time_travel(int years) {
    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    
    Date new_date;
    new_date.year = current_time->tm_year + 1900 + years;
    new_date.month = current_time->tm_mon + 1;
    new_date.day = current_time->tm_mday;

    return new_date;
}

void show_menu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to the future\n");
    printf("2. Travel to the past\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int get_year_input(const char *prompt) {
    int years;
    printf("%s", prompt);
    while (1) {
        if (scanf("%d", &years) == 1 && years >= -NUM_YEARS && years <= NUM_YEARS) {
            break;
        } else {
            printf("Invalid input. Please enter a number between %d and %d: ", -NUM_YEARS, NUM_YEARS);
            while (getchar() != '\n'); // Clear input buffer
        }
    }
    return years;
}

int main() {
    int option;

    while (1) {
        show_menu();
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int years = get_year_input("Enter number of years to travel forward: ");
                Date future_date = time_travel(years);
                display_date(future_date);
                break;
            }
            case 2: {
                int years = get_year_input("Enter number of years to travel backward: ");
                Date past_date = time_travel(-years);
                display_date(past_date);
                break;
            }
            case 3:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}