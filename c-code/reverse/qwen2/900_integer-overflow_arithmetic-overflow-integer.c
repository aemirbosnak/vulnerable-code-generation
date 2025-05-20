#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

void add_time(struct tm *tm, long seconds) {
    time_t t = mktime(tm);
    t += seconds;
    *tm = *localtime(&t);
}

int main() {
    struct tm current_time;
    long duration;
    int timezone;

    printf("Enter current date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &current_time.tm_year + 1900, &current_time.tm_mon, &current_time.tm_mday,
          &current_time.tm_hour, &current_time.tm_min, &current_time.tm_sec);

    printf("Enter time travel duration in seconds: ");
    scanf("%ld", &duration);

    printf("Enter time zone offset from UTC in minutes: ");
    scanf("%d", &timezone);
    duration -= timezone * 60;

    add_time(&current_time, duration);

    printf("Resulting date and time: %s", asctime(&current_time));

    return 0;
}
