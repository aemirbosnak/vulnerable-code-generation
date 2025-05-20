#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct {
    uint32_t year;
    uint16_t month, day, hour, minute, second;
} Date;

Date add_time(Date date, int seconds) {
    seconds += date.second + (date.minute * 60) + (date.hour * 3600) + (date.day * 24 * 3600) + (date.month * 30 * 24 * 3600) + (date.year * 365 * 24 * 3600);
    date.second = seconds % 60;
    seconds /= 60;
    date.minute = seconds % 60;
    seconds /= 60;
    date.hour = seconds % 24;
    seconds /= 24;
    date.day = (int)(seconds / 60 / 60);
    seconds %= 60 * 60 * 24;
    date.month = (int)(seconds / 30 / 24 / 60 / 60);
    seconds %= 30 * 24 * 60 * 60;
    date.year = (int)(seconds / 365 / 24 / 60 / 60);
    return date;
}

int main() {
    Date start = {2022, 1, 1, 0, 0, 0};
    int duration = 1000000; // replace with desired duration in seconds
    Date end = add_time(start, duration);
    printf("New date and time: %d-%02d-%02d %02d:%02d:%02d\n", end.year, end.month, end.day, end.hour, end.minute, end.second);
    return 0;
}
