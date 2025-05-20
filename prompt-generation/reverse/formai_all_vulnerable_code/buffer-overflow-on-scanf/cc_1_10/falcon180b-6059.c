//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31

typedef struct {
    int day;
    int month;
    int year;
} Date;

void print_date(Date* date) {
    printf("%d-%d-%d\n", date->month, date->day, date->year);
}

int is_valid_date(Date* date) {
    if (date->month < 1 || date->month > MAX_MONTH) {
        return 0;
    }
    if (date->day < 1 || date->day > MAX_DAY) {
        return 0;
    }
    if (date->year < 1 || date->year > MAX_YEAR) {
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int destination_year = rand() % MAX_YEAR + 1;
    int destination_month = rand() % MAX_MONTH + 1;
    int destination_day = rand() % MAX_DAY + 1;

    Date destination = {destination_day, destination_month, destination_year};
    printf("You have traveled to the year %d!\n", destination_year);
    print_date(&destination);

    int choice;
    char input[10];
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Travel to a specific year\n");
        printf("2. Travel back to the present\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the year you want to travel to: ");
            scanf("%s", input);
            int year = atoi(input);
            if (year < 1 || year > MAX_YEAR) {
                printf("Invalid year!\n");
            } else {
                Date new_destination = {destination.day, destination.month, year};
                printf("You have traveled to the year %d!\n", year);
                print_date(&new_destination);
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}