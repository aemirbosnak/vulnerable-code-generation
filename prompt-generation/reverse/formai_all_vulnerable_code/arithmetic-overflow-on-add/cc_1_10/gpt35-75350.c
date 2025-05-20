//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

void printLight(int state) {
    switch(state) {
        case RED:
            printf("RED\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
    }
}

void delay(int seconds) {
    clock_t start_time = clock();
    while(clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int state = RED;
    int greenTime = 10;
    int yellowTime = 2;
    int redTime = 5;
    
    while(true) {
        switch(state) {
            case RED:
                printLight(state);
                delay(redTime);
                state = GREEN;
                break;
            case YELLOW:
                printLight(state);
                delay(yellowTime);
                state = RED;
                break;
            case GREEN:
                printLight(state);
                delay(greenTime);
                state = YELLOW;
                break;
        }
    }
    
    return 0;
}