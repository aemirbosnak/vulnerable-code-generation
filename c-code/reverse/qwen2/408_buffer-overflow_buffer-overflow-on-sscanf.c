#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int day, month, year, hour, minute;
    char am_pm[3], timezone[3];

    printf("Enter date and time (DD/MM/YYYY HH:MM AM/PM Timezone): ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d/%d/%d %d:%d %2s %2s", &day, &month, &year, &hour, &minute, am_pm, timezone) != 7) {
        printf("Invalid input format.\n");
        return 1;
    }

    printf("Day: %d\nMonth: %d\nYear: %d\nHour: %d\nMinute: %d\nAM/PM: %s\nTimezone: %s\n", day, month, year, hour, minute, am_pm, timezone);

    return 0;
}
