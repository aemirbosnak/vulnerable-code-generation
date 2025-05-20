//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

// Function prototypes
void init(void);
void change(int);
void delay(int);

int main(void) {
    int state = RED;
    init();

    while (1) {
        change(state);
        delay(1000);
    }

    return 0;
}

void init(void) {
    printf("Traffic light initialized!\n");
}

void change(int s) {
    switch (s) {
        case RED:
            printf("Traffic light is red.\n");
            break;
        case YELLOW:
            printf("Traffic light is yellow.\n");
            break;
        case GREEN:
            printf("Traffic light is green.\n");
            break;
        default:
            printf("Invalid traffic light state.\n");
            break;
    }
}

void delay(int ms) {
    clock_t start = clock();
    while (clock() - start < ms);
}