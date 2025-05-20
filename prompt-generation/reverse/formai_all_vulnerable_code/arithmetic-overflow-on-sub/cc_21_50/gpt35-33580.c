//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Touring
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date is: %d.%d.%d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
    printf("The current time is: %d:%d:%d\n", t->tm_hour, t->tm_min, t->tm_sec);

    printf("\nChoose a year to travel to: ");
    int year;
    scanf("%d", &year);

    printf("\nTravelling to %d...\n", year);

    for (int i = t->tm_year+1900; i <= year; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            printf("%d is a leap year!\n", i);
        }
    }

    printf("\nChoose a month to travel to: ");
    int month;
    scanf("%d", &month);

    printf("\nTravelling to %d.%d...\n", month, year);

    // Adjust year if January or February
    if (month < 3) {
        year--;
    }

    // Calculate day of week using Zeller's Congruence
    int q = 1;
    int m = month;
    int Y = year;
    int h = (q + (13 * (m + 1)) / 5 + Y + Y / 4 - Y / 100 + Y / 400) % 7;

    switch(h) {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }

    printf("\nChoose a day to travel to: ");
    int day;
    scanf("%d", &day);

    printf("\nTravelling to %d.%d.%d...\n", day, month, year);

    // Check if day is valid
    if (day < 1 || day > 31 || (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))) {
        printf("Invalid day!\n");
        return 1;
    }

    // Check for leap year
    int leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    // Check if day is valid for February
    if (month == 2) {
        if (leap && day > 29) {
            printf("Invalid day!\n");
            return 1;
        } else if (!leap && day > 28) {
            printf("Invalid day!\n");
            return 1;
        }
    }

    // Output final date
    printf("\nYou have successfully time travelled to %d.%d.%d!\n", day, month, year);

    return 0;
}