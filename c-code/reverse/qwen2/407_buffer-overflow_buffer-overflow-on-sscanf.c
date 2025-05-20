#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
    char input[100];
    struct tm date = {0};
    int year, month, day, hour, minute, second;

    printf("Enter a date and time (YYYY-MM-DD HH:MM:SS): ");
    if (scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) != 6) {
        printf("Invalid input format.\n");
        return 1;
    }

    date.tm_year = year - 1900; // Year since 1900
    date.tm_mon = month - 1;   // Month (0-11)
    date.tm_mday = day;         // Day of the month
    date.tm_hour = hour;        // Hour (0-23)
    date.tm_min = minute;       // Minute (0-59)
    date.tm_sec = second;       // Second (0-60)

    if (mktime(&date) == -1) {
        printf("Invalid date/time.\n");
        return 1;
    }

    printf("Parsed Date/Time: %s\n", asctime(&date));

    return 0;
}
