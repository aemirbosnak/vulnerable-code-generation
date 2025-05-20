//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int weather;
    int day = 1;
    int month = 1;
    int year = 2022;
    int seed;

    printf("Welcome to the weather simulation program!\n");
    printf("Please enter a seed value: ");
    scanf("%d", &seed);
    srand(seed);

    while (1) {
        printf("\nDay %d, %s, %d\n", day, (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)? "Winter" : (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)? "Summer" : "Spring/Fall", year);

        weather = rand() % 4;
        printf("Today's weather is %s!\n", (weather == 0)? "Sunny" : (weather == 1)? "Rainy" : (weather == 2)? "Cloudy" : "Stormy");

        if (month == 12) {
            year++;
            month = 1;
        } else {
            month++;
        }
        day++;

        if (month == 2 && day > 28) {
            day = 1;
            month++;
        } else if (month == 2 && day == 28) {
            printf("\nHappy Leap Day!\n");
        } else if (month == 4 && day > 30) {
            day = 1;
            month++;
        } else if (month == 6 && day > 30) {
            day = 1;
            month++;
        } else if (month == 9 && day > 30) {
            day = 1;
            month++;
        } else if (month == 11 && day > 30) {
            day = 1;
            month++;
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}