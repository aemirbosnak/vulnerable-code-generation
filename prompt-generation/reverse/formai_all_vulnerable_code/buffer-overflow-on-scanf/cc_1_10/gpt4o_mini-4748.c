//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAVELS 5
#define TIME_PERIOD 1000

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date travel_date;
    char destination[50];
} Travel;

void getCurrentDate(Date *current_date) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    current_date->year = tm_now->tm_year + 1900; // Convert to full year
    current_date->month = tm_now->tm_mon + 1;   // Months are 0-11 in tm
    current_date->day = tm_now->tm_mday; 
}

void displayTravel(Travel travel) {
    printf("Travel to %s on %02d/%02d/%d\n", travel.destination, travel.travel_date.day, travel.travel_date.month, travel.travel_date.year);
}

void travelBackInTime(Travel* travels, int* travel_count, Date target_date, char* destination) {
    if (*travel_count < MAX_TRAVELS) {
        travels[*travel_count].travel_date = target_date;
        strncpy(travels[*travel_count].destination, destination, sizeof(travels[*travel_count].destination) - 1);
        (*travel_count)++;
        printf("Time Travel Successful!\n");
    } else {
        printf("Travel record is full. Can't store more travels.\n");
    }
}

int main() {
    Travel travels[MAX_TRAVELS];
    int travel_count = 0;

    Date current_date;
    getCurrentDate(&current_date);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Your current date is %02d/%02d/%d\n", current_date.day, current_date.month, current_date.year);

    while (1) {
        printf("\nMenu:\n1. Travel Back in Time\n2. List Travels\n3. Exit\nChoose an option: ");
        int option;
        scanf("%d", &option);

        if (option == 1) {
            Date target_date;
            char destination[50];
            
            printf("Enter year to travel back to: ");
            scanf("%d", &target_date.year);
            printf("Enter month to travel back to (1-12): ");
            scanf("%d", &target_date.month);
            printf("Enter day to travel back to: ");
            scanf("%d", &target_date.day);
            printf("Enter your destination: ");
            scanf("%s", destination);

            // Basic validation
            if (target_date.year > current_date.year || 
                target_date.month < 1 || target_date.month > 12 || 
                target_date.day < 1 || target_date.day > 31) {
                printf("Invalid date. Please try again.\n");
                continue; 
            }
            // Record travel
            travelBackInTime(travels, &travel_count, target_date, destination);
        } else if (option == 2) {
            printf("You have made the following travels:\n");
            for (int i = 0; i < travel_count; i++) {
                displayTravel(travels[i]);
            }
        } else if (option == 3) {
            printf("Exiting the Time Travel Simulator. Safe travels!\n");
            break;
        } else {
            printf("Invalid option, please choose 1, 2, or 3.\n");
        }
    }

    return 0;
}