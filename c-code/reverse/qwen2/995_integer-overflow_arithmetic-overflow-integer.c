#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMER_MAX 2147483647

int main() {
    srand(time(NULL));
    int timers[4] = {rand() % (TIMER_MAX - 5) + 5, rand() % (TIMER_MAX - 5) + 5, rand() % (TIMER_MAX - 5) + 5, rand() % (TIMER_MAX - 5) + 5};

    while(1) {
        for(int i = 0; i < 4; i++) {
            if(timers[i] > 0) {
                timers[i]--;
            } else {
                printf("Traffic Light %d is green\n", i);
                timers[i] = rand() % (TIMER_MAX - 5) + 5;
            }
        }
        sleep(1);
    }

    return 0;
}
