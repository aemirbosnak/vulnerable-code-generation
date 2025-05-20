//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

int main() {
    int state = RED;
    int duration[3] = {10, 5, 15}; // seconds
    int i = 0;
    time_t start_time, end_time;

    printf("Traffic Light Controller\n");

    while (1) {
        start_time = time(NULL);
        switch (state) {
            case RED:
                printf("Red light\n");
                end_time = start_time + duration[i];
                while (difftime(time(NULL), end_time) > 0) {
                    printf(".");
                    fflush(stdout);
                    usleep(100000); // 100ms
                }
                state = GREEN;
                i++;
                break;
            case YELLOW:
                printf("Yellow light\n");
                end_time = start_time + duration[i];
                while (difftime(time(NULL), end_time) > 0) {
                    printf(".");
                    fflush(stdout);
                    usleep(100000); // 100ms
                }
                state = RED;
                i--;
                break;
            case GREEN:
                printf("Green light\n");
                end_time = start_time + duration[i];
                while (difftime(time(NULL), end_time) > 0) {
                    printf(".");
                    fflush(stdout);
                    usleep(100000); // 100ms
                }
                state = YELLOW;
                i++;
                break;
        }
    }

    return 0;
}