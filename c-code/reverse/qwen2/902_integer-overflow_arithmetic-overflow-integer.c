#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <time.h>

void simulateTimeTravel(time_t *current_time, int days, int hours, int minutes, int seconds) {
    struct tm *tm_struct = localtime(current_time);
    tm_struct->tm_mday += days;
    tm_struct->tm_hour += hours;
    tm_struct->tm_min += minutes;
    tm_struct->tm_sec += seconds;
    mktime(tm_struct);
}

int main() {
    time_t current_time = time(NULL);
    struct tm *tm_struct = localtime(&current_time);

    printf("Current Time: %s", asctime(tm_struct));

    int days, hours, minutes, seconds;
    printf("Enter time travel duration (days, hours, minutes, seconds): ");
    scanf("%d %d %d %d", &days, &hours, &minutes, &seconds);

    simulateTimeTravel(&current_time, days, hours, minutes, seconds);

    tm_struct = localtime(&current_time);
    printf("New Time: %s", asctime(tm_struct));

    return 0;
}
