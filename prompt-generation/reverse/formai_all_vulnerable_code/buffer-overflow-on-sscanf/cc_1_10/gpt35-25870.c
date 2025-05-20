//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);

    printf("Enter a date in Natural Language: \n");
    char date[50];
    fgets(date, 50, stdin);

    // Convert Natural Language date to numbered date
    int day = 0, month = 0, year = 0;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        printf("Invalid input: %s\n", date);
        return 1;
    }

    // Convert Natural Language month to numbered month
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strstr(date, months[i])) {
            month = i + 1;
        }
    }

    // Determine whether date is valid
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        printf("Invalid date: %d/%d/%d\n", day, month, year);
        return 1;
    }

    // Determine weekday name
    char* weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int weekday = mktime(timeinfo);
    timeinfo->tm_mday = day;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_year = year - 1900;
    mktime(timeinfo);
    int diff = mktime(timeinfo) - weekday;
    int weekday_num = (diff / (60 * 60 * 24)) % 7;
    char* weekday_name = weekdays[weekday_num];

    // Print results
    printf("%d/%d/%d is a %s\n", day, month, year, weekday_name);

    return 0;
}