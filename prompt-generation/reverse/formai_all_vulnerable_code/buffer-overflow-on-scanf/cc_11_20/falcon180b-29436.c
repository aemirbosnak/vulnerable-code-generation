//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int weather;
    int day = 1;
    int month = 1;
    int year = 0;
    int season = 1;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 1;
    int current_day = 1;

    printf("Welcome to the Medieval Weather Simulation!\n");
    printf("Please enter the current year: ");
    scanf("%d", &year);

    while (1) {
        if (current_month == 12) {
            current_month = 1;
            year++;
        } else {
            current_month++;
        }
        if (current_day > days_in_month[current_month - 1]) {
            current_day = 1;
        }
        if (current_month == 3 || current_month == 6 || current_month == 9 || current_month == 12) {
            season = rand() % 4;
        }
        if (season == 1) {
            printf("It is the beginning of Spring in the year %d.\n", year);
            printf("The weather is mild and pleasant.\n");
        } else if (season == 2) {
            printf("It is the beginning of Summer in the year %d.\n", year);
            printf("The weather is hot and sunny.\n");
        } else if (season == 3) {
            printf("It is the beginning of Autumn in the year %d.\n", year);
            printf("The weather is cool and crisp.\n");
        } else {
            printf("It is the beginning of Winter in the year %d.\n", year);
            printf("The weather is cold and snowy.\n");
        }
        printf("The current date is %d/%d/%d.\n", current_month, current_day, year);
        printf("Press enter to see the weather for the next day.\n");
        getchar();
        current_day++;
    }
    return 0;
}