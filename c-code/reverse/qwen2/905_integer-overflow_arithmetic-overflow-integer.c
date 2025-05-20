#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

void add_time(struct tm *tm, int days, int hours, int minutes) {
    tm->tm_mday += days;
    tm->tm_hour += hours;
    tm->tm_min += minutes;
    mktime(tm);
}

int main() {
    struct tm current_time;
    int days, hours, minutes;

    printf("Enter current date and time (YYYY-MM-DD HH:MM): ");
    scanf("%d-%d-%d %d:%d", &current_time.tm_year + 1900, &current_time.tm_mon + 1, &current_time.tm_mday,
          &current_time.tm_hour, &current_time.tm_min);

    if (scanf("%d %d %d", &days, &hours, &minutes) != 3 || days < 0 || hours < 0 || minutes < 0) {
        printf("Invalid input. Please enter non-negative values for days, hours, and minutes.\n");
        return 1;
    }

    add_time(&current_time, days, hours, minutes);

    printf("Travelled to: %s", asctime(&current_time));

    return 0;
}
