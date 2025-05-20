//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void time_travel(int year);
void display_date(struct tm* date);

int main() {
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the year you want to travel back to: ");
                int year;
                scanf("%d", &year);
                time_travel(year);
                break;
            case 2:
                printf("Enter the number of years you want to travel forward: ");
                int num_years;
                scanf("%d", &num_years);
                time_travel(time(NULL) + num_years * 365 * 24 * 60 * 60);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}

void time_travel(int year) {
    time_t target_time = mktime(localtime(&year));
    sleep(target_time - time(NULL));
    printf("Time travel successful! The current date and time is: ");
    display_date(localtime(&target_time));
}

void display_date(struct tm* date) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           (date->tm_year + 1900), (date->tm_mon + 1), date->tm_mday,
           date->tm_hour, date->tm_min, date->tm_sec);
}