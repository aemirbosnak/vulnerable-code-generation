#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
    char input[100];
    int year, month, day, hour, minute;
    struct tm timeinfo;

    printf("Enter date and time (YYYY-MM-DD HH:MM): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d-%d-%d %d:%d", &year, &month, &day, &hour, &minute);

    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = 0;
    timeinfo.tm_isdst = -1;

    if (mktime(&timeinfo) == -1) {
        printf("Invalid date and time.\n");
        return 1;
    }

    printf("Traveling to: %s\n", asctime(&timeinfo));

    return 0;
}
