//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int year, month, day;

    printf("Enter a date (yyyy-mm-dd): ");
    scanf("%d-%d-%d", &year, &month, &day);

    // calculate the day of the week
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

    // print the date in natural language
    printf("The date you entered is ");

    switch (month) {
        case 1:
            printf("January ");
            break;
        case 2:
            printf("February ");
            break;
        case 3:
            printf("March ");
            break;
        case 4:
            printf("April ");
            break;
        case 5:
            printf("May ");
            break;
        case 6:
            printf("June ");
            break;
        case 7:
            printf("July ");
            break;
        case 8:
            printf("August ");
            break;
        case 9:
            printf("September ");
            break;
        case 10:
            printf("October ");
            break;
        case 11:
            printf("November ");
            break;
        case 12:
            printf("December ");
            break;
    }

    switch (day) {
        case 1:
        case 21:
        case 31:
            printf("%dst, ", day);
            break;
        case 2:
        case 22:
            printf("%dnd, ", day);
            break;
        case 3:
        case 23:
            printf("%drd, ", day);
            break;
        default:
            printf("%dth, ", day);
            break;
    }

    printf("%d is a ", year);

    switch (d) {
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

    printf("\n");

    return 0;
}