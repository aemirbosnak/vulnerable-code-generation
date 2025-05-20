//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int getDayOfWeek(int year, int month, int day);
int getDaysInMonth(int year, int month);
int isLeapYear(int year);

int main() {
    int year, month, day, dayOfWeek, daysInMonth;
    float weight;
    char choice;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter the current date (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &year, &month, &day);

    dayOfWeek = getDayOfWeek(year, month, day);

    printf("\nToday is ");

    switch(dayOfWeek) {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
    }

    daysInMonth = getDaysInMonth(year, month);

    printf(", %d/%d/%d\n\n", year, month, day);

    printf("Please enter your weight for today (in kilograms): ");
    scanf("%f", &weight);

    printf("\nYour weight for today has been recorded as %.2f kilograms.\n", weight);

    printf("Is there anything else you would like to do? (Y/N): ");
    scanf(" %c", &choice);

    if(choice == 'Y') {
        main();
    }
    else {
        printf("\nThank you for using the Fitness Tracker!\n");
        exit(0);
    }

    return 0;
}

int getDayOfWeek(int year, int month, int day) {
    int monthTable[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    int dayOfWeek = (year + year/4 - year/100 + year/400 + monthTable[month-1] + day) % 7;
    return dayOfWeek;
}

int getDaysInMonth(int year, int month) {
    int daysInMonth;
    switch(month) {
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        case 2:
            if(isLeapYear(year)) {
                daysInMonth = 29;
            }
            else {
                daysInMonth = 28;
            }
            break;
        default:
            daysInMonth = 31;
            break;
    }
    return daysInMonth;
}

int isLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}