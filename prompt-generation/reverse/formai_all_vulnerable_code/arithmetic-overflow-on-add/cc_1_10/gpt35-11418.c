//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

void delay(int seconds) {
    int milliseconds = seconds * 1000;
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void change_light(int previous, int current) {
    printf("Light changed from ");

    switch (previous) {
        case GREEN:
            printf("green");
            break;
        case YELLOW:
            printf("yellow");
            break;
        case RED:
            printf("red");
            break;
    }

    printf(" to ");

    switch (current) {
        case GREEN:
            printf("green\n");
            break;
        case YELLOW:
            printf("yellow\n");
            break;
        case RED:
            printf("red\n");
            break;
    }
}

int main() {
    int next_light = GREEN;
    int previous_light = 0;
    int delay_time = 0;

    while (1) {
        switch (next_light) {
            case GREEN:
                change_light(previous_light, GREEN);
                previous_light = GREEN;
                delay_time = 5;
                break;
            case YELLOW:
                change_light(previous_light, YELLOW);
                previous_light = YELLOW;
                delay_time = 2;
                break;
            case RED:
                change_light(previous_light, RED);
                previous_light = RED;
                delay_time = 5;
                break;
        }

        delay(delay_time);
        next_light = (next_light % 3) + 1;
    }

    return 0;
}