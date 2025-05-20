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
    struct tm now;
    time_t t = time(NULL);
    localtime_r(&t, &now);

    printf("Current time: %s", asctime(&now));

    add_time(&now, 3600); // Add 1 hour
    printf("Time after 1 hour: %s", asctime(&now));

    add_time(&now, -86400); // Subtract 1 day
    printf("Time after subtracting 1 day: %s", asctime(&now));

    return 0;
}
