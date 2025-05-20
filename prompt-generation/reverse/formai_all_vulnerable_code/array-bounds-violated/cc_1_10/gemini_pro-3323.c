//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the months of the year
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    // Define the days of the week
    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Print the current date and time
    printf("Current date and time: %s %d %d %d %d:%d:%d\n", days[tm->tm_wday], tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);

    // Get the user input for the date
    int day, month, year;
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);

    // Check if the date is valid
    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        return 1;
    }
    if (month < 1 || month > 12) {
        printf("Invalid month\n");
        return 1;
    }
    if (year < 1900) {
        printf("Invalid year\n");
        return 1;
    }

    // Convert the date to a time_t
    struct tm tm2;
    tm2.tm_year = year - 1900;
    tm2.tm_mon = month - 1;
    tm2.tm_mday = day;
    tm2.tm_hour = 0;
    tm2.tm_min = 0;
    tm2.tm_sec = 0;
    time_t t2 = mktime(&tm2);

    // Print the converted date and time
    printf("Converted date and time: %s %d %d %d %d:%d:%d\n", days[tm2.tm_wday], tm2.tm_mday, tm2.tm_mon + 1, tm2.tm_year + 1900, tm2.tm_hour, tm2.tm_min, tm2.tm_sec);

    return 0;
}