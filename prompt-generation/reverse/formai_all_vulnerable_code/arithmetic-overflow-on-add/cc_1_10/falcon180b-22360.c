//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
char *month_name(int month);
char *weekday_name(int weekday);
void display_date(int year, int month, int day);

int main() {
    time_t now;
    struct tm *t;

    // Get current time
    time(&now);

    // Convert time to struct tm
    t = localtime(&now);

    // Display current date
    printf("Today is %s, %d %s %d\n", weekday_name(t->tm_wday), t->tm_mday, month_name(t->tm_mon + 1), t->tm_year + 1900);

    // Ask user for input
    char input[100];
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%s", input);

    // Convert input to struct tm
    t = strptime(input, "%m/%d/%Y", NULL);

    // Display input date
    printf("Input date is %s, %d %s %d\n", weekday_name(t->tm_wday), t->tm_mday, month_name(t->tm_mon + 1), t->tm_year + 1900);

    return 0;
}

// Function to get month name
char *month_name(int month) {
    static char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month];
}

// Function to get weekday name
char *weekday_name(int weekday) {
    static char weekdays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekdays[weekday];
}

// Function to display date
void display_date(int year, int month, int day) {
    printf("%d-%02d-%02d\n", year, month, day);
}