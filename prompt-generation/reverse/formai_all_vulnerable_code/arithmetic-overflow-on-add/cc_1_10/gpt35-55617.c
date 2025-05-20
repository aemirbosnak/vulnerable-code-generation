//FormAI DATASET v1.0 Category: Date and time ; Style: excited
#include <stdio.h>
#include <time.h>

int main()
{
    printf("Welcome to my exciting Date and Time Program!\n\n");

    // Get the current time
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Print the current date in various formats
    printf("Today's date is: \n\n");

    // Format 1: Sunday, January 1st, 2023
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", timeinfo);
    printf("%s\n", buffer);

    // Format 2: 01/01/2023 12:00:00 AM
    char buffer2[80];
    strftime(buffer2, sizeof(buffer2), "%m/%d/%Y %I:%M:%S %p", timeinfo);
    printf("%s\n", buffer2);

    // Format 3: 2023-01-01T00:00:00Z
    char buffer3[80];
    strftime(buffer3, sizeof(buffer3), "%Y-%m-%dT%H:%M:%SZ", timeinfo);
    printf("%s\n\n", buffer3);

    // Calculate and display the time until New Year's Day
    struct tm new_years_day = {0};
    new_years_day.tm_year = timeinfo->tm_year + 1;
    new_years_day.tm_mday = 1;
    new_years_day.tm_mon = 0;

    time_t new_years_day_seconds = mktime(&new_years_day);
    double time_until_new_year = difftime(new_years_day_seconds, rawtime);
    int days_until_new_year = (int) (time_until_new_year / (60 * 60 * 24));

    printf("There are only %d days left until New Year's Day!\n", days_until_new_year);

    // Print a festive countdown clock
    for (int i = 10; i >= 0; i--)
    {
        printf("%02d:%02d:%02d\n", i, 0, 0);
        sleep(1);
    }

    printf("\nHAPPY NEW YEAR!!!\n");

    return 0;
}