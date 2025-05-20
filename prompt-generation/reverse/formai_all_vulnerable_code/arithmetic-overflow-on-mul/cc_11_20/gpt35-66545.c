//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define INVALID 3

void trafficLightController(int queue1[], int queue2[], int queue3[], int queue4[], int time) {
    int timer = clock() * CLOCKS_PER_SEC / 1000 + time * CLOCKS_PER_SEC;
    int state = RED, prevState = GREEN, next1 = INVALID, next2 = INVALID, next3 = INVALID, next4 = INVALID;
    while (clock() * CLOCKS_PER_SEC / 1000 < timer) {
        switch (state) {
            case RED:
                printf("RED\n");
                if (prevState == GREEN) {
                    next1 = rand() % 2;
                    next2 = rand() % 2;
                    next3 = rand() % 2;
                    next4 = rand() % 2;
                    printf("Queue1: %d cars, Queue2: %d cars, Queue3: %d cars, Queue4: %d cars\n", queue1[RED], queue2[RED], queue3[RED], queue4[RED]);
                }
                if (next1 && !queue1[YELLOW] && !queue1[GREEN]) {
                    queue1[YELLOW] = timer;
                } else if (queue1[YELLOW] && clock() * CLOCKS_PER_SEC / 1000 >= queue1[YELLOW] + 2000) {
                    queue1[YELLOW] = 0;
                    queue1[GREEN] = timer;
                }
                if (next2 && !queue2[YELLOW] && !queue2[GREEN]) {
                    queue2[YELLOW] = timer;
                } else if (queue2[YELLOW] && clock() * CLOCKS_PER_SEC / 1000 >= queue2[YELLOW] + 2000) {
                    queue2[YELLOW] = 0;
                    queue2[GREEN] = timer;
                }
                prevState = state;
                state = YELLOW;
                break;
            case YELLOW:
                printf("YELLOW\n");
                if (next1 && prevState == RED) {
                    queue1[GREEN] = timer;
                } else if (next2 && prevState == RED) {
                    queue2[GREEN] = timer;
                }
                if (queue1[GREEN] && clock() * CLOCKS_PER_SEC / 1000 >= queue1[GREEN] + 5000) {
                    queue1[GREEN] = 0;
                    queue1[RED] = 1;
                } else if (queue2[GREEN] && clock() * CLOCKS_PER_SEC / 1000 >= queue2[GREEN] + 5000) {
                    queue2[GREEN] = 0;
                    queue2[RED] = 1;
                }
                prevState = state;
                state = GREEN;
                break;
            case GREEN:
                printf("GREEN\n");
                if (next3 && prevState == YELLOW && !queue3[GREEN]) {
                    queue3[GREEN] = timer;
                } else if (next4 && prevState == YELLOW && !queue4[GREEN]) {
                    queue4[GREEN] = timer;
                }
                if (queue3[GREEN] && clock() * CLOCKS_PER_SEC / 1000 >= queue3[GREEN] + 5000) {
                    queue3[GREEN] = 0;
                    queue3[RED] = 1;
                } else if (queue4[GREEN] && clock() * CLOCKS_PER_SEC / 1000 >= queue4[GREEN] + 5000) {
                    queue4[GREEN] = 0;
                    queue4[RED] = 1;
                }
                prevState = state;
                state = YELLOW;
                break;
        }
    }
}

int main() {
    int queue1[] = {0, 0, 0};
    int queue2[] = {0, 0, 0};
    int queue3[] = {0, 0, 0};
    int queue4[] = {0, 0, 0};
    trafficLightController(queue1, queue2, queue3, queue4, 30);
    return 0;
}