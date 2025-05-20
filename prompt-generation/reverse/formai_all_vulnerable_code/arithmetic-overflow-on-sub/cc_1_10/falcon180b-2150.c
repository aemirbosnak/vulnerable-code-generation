//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_date(int year, int month, int day);
int is_leap_year(int year);
void time_travel(int year, int month, int day);

int main() {
    int choice, year, month, day;

    printf("Welcome to the Medieval Time Travel Simulator!\n");
    printf("Please enter the current date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &year, &month, &day);

    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Print current date\n");
        printf("2. Check if a year is a leap year\n");
        printf("3. Time travel\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                print_date(year, month, day);
                break;
            case 2:
                printf("Enter a year: ");
                scanf("%d", &year);
                if(is_leap_year(year)) {
                    printf("%d is a leap year.\n", year);
                } else {
                    printf("%d is not a leap year.\n", year);
                }
                break;
            case 3:
                printf("Enter the year you want to time travel to (YYYY): ");
                scanf("%d", &year);
                printf("Enter the month you want to time travel to (1-12): ");
                scanf("%d", &month);
                printf("Enter the day you want to time travel to (1-31): ");
                scanf("%d", &day);
                time_travel(year, month, day);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void print_date(int year, int month, int day) {
    printf("The current date is %d-%02d-%02d.\n", year, month, day);
}

int is_leap_year(int year) {
    if(year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

void time_travel(int year, int month, int day) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;

    time_t then = mktime(t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", t);

    printf("\nYou have successfully time traveled to %s!\n", buffer);
}