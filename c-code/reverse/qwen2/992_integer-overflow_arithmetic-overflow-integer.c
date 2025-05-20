#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_T 2147483647

int main() {
    time_t currentTime = time(NULL);
    int timeInterval = 5; // seconds

    if (currentTime + timeInterval > MAX_TIME_T) {
        printf("Integer overflow detected!\n");
        return 1;
    }

    time_t nextTime = currentTime + timeInterval;

    printf("Current time: %ld\n", currentTime);
    printf("Next time: %ld\n", nextTime);

    return 0;
}
