//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int year, month, day, hour, minute, second;
    char choice;
    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter the current date and time: \n");
    printf("Year (e.g. 2022): ");
    scanf("%d", &year);
    printf("Month (1-12): ");
    scanf("%d", &month);
    printf("Day of the month (1-31): ");
    scanf("%d", &day);
    printf("Hour (0-23): ");
    scanf("%d", &hour);
    printf("Minute (0-59): ");
    scanf("%d", &minute);
    printf("Second (0-59): ");
    scanf("%d%*c", &second);  // consume newline character
    t->tm_year = year - 1900;
    t->tm_mon = month - 1;
    t->tm_mday = day;
    t->tm_hour = hour;
    t->tm_min = minute;
    t->tm_sec = second;
    now = mktime(t);
    printf("\nCurrent time: %s", asctime(localtime(&now)));
    printf("Do you want to travel back or forth in time? (b/f): ");
    scanf("%c%*c", &choice);  // consume newline character
    int years, months, days, hours, minutes, seconds;
    if (choice == 'b') {
        printf("Enter the number of years to travel back: ");
        scanf("%d", &years);
        printf("Enter the number of months to travel back: ");
        scanf("%d", &months);
        printf("Enter the number of days to travel back: ");
        scanf("%d", &days);
        printf("Enter the number of hours to travel back: ");
        scanf("%d", &hours);
        printf("Enter the number of minutes to travel back: ");
        scanf("%d", &minutes);
        printf("Enter the number of seconds to travel back: ");
        scanf("%d%*c", &seconds);  // consume newline character
        now -= seconds + minutes * 60 + hours * 3600 + days * 86400 + months * 2592000 + years * 31536000;
        printf("\nYou have traveled back in time!\n\n");
    } else if (choice == 'f') {
        printf("Enter the number of years to travel forward: ");
        scanf("%d", &years);
        printf("Enter the number of months to travel forward: ");
        scanf("%d", &months);
        printf("Enter the number of days to travel forward: ");
        scanf("%d", &days);
        printf("Enter the number of hours to travel forward: ");
        scanf("%d", &hours);
        printf("Enter the number of minutes to travel forward: ");
        scanf("%d", &minutes);
        printf("Enter the number of seconds to travel forward: ");
        scanf("%d%*c", &seconds);  // consume newline character
        now += seconds + minutes * 60 + hours * 3600 + days * 86400 + months * 2592000 + years * 31536000;
        printf("\nYou have traveled forward in time!\n\n");
    } else {
        printf("\nInvalid choice! The program will exit.\n");
        return 0;
    }
    printf("New time: %s", asctime(localtime(&now)));
    return 0;
}