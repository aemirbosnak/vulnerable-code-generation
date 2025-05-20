#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char date_time[20];
    int day, month, year, hour, minute;
    char am_pm[3], timezone[3];

    printf("Enter date and time (DD/MM/YYYY HH:MM AM/PM Timezone): ");
    scanf("%d/%d/%d %d:%d %2s %2s", &day, &month, &year, &hour, &minute, am_pm, timezone);

    printf("Day: %d\nMonth: %d\nYear: %d\nHour: %d\nMinute: %d\nAM/PM: %s\nTimezone: %s\n",
           day, month, year, hour, minute, am_pm, timezone);

    return 0;
}
