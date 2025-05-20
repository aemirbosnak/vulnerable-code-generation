//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            printf("Enter the year you want to travel to (between 1900 and 2099): ");
            int year;
            scanf("%d", &year);

            struct tm time;
            time.tm_year = year - 1900;
            time.tm_mon = 0;
            time.tm_mday = 1;
            time.tm_hour = 0;
            time.tm_min = 0;
            time.tm_sec = 0;

            time_t t = mktime(&time);
            printf("Traveling to the past...\n");
            sleep(1);
            printf("You have arrived in the year %d!\n", year);
            break;
        }
        case 2: {
            printf("Enter the year you want to travel to (between 2100 and 9999): ");
            int year;
            scanf("%d", &year);

            struct tm time;
            time.tm_year = year - 1900;
            time.tm_mon = 0;
            time.tm_mday = 1;
            time.tm_hour = 0;
            time.tm_min = 0;
            time.tm_sec = 0;

            time_t t = mktime(&time);
            printf("Traveling to the future...\n");
            sleep(1);
            printf("You have arrived in the year %d!\n", year + 100);
            break;
        }
        case 3: {
            printf("Thank you for using the Time Travel Simulator!\n");
            break;
        }
        default: {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}