#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

void add_time(struct tm *tm, int days, int hours, int minutes, int seconds) {
    time_t t = mktime(tm);
    t += (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;
    *tm = *localtime(&t);
}

int main() {
    struct tm current_time;
    int days, hours, minutes, seconds;

    printf("Enter current date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &current_time.tm_year, &current_time.tm_mon, &current_time.tm_mday,
          &current_time.tm_hour, &current_time.tm_min, &current_time.tm_sec);

    printf("Enter time travel duration (days hours minutes seconds): ");
    scanf("%d %d %d %d", &days, &hours, &minutes, &seconds);

    add_time(&current_time, days, hours, minutes, seconds);

    printf("Resulting date and time: %s", asctime(&current_time));

    return 0;
}
