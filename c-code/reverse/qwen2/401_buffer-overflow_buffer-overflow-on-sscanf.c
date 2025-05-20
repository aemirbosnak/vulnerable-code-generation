#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

int main() {
    char input[100];
    int day, month, year, hour, minute;
    char am_pm[3], timezone[3];

    printf("Enter date and time (DD/MM/YYYY HH:MM AM/PM Timezone): ");
    scanf("%d/%d/%d %d:%d %2s %2s", &day, &month, &year, &hour, &minute, am_pm, timezone);

    struct tm t = {0};
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    t.tm_hour = hour;
    t.tm_min = minute;

    if (strcmp(am_pm, "PM") == 0 && hour != 12) {
        t.tm_hour += 12;
    } else if (strcmp(am_pm, "AM") == 0 && hour == 12) {
        t.tm_hour = 0;
    }

    mktime(&t);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y at %I:%M %p in %Z", &t);
    printf("Time Travel Confirmation: %s\n", buffer);

    return 0;
}
