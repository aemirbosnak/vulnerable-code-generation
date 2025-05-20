//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int red;
    int yellow;
    int green;
    int count;
} Light;

int main() {
    Light lights[3];
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        lights[i].red = rand() % 30 + 1;
        lights[i].yellow = rand() % 10 + 1;
        lights[i].green = rand() % 30 + 1;
        lights[i].count = 0;
    }
    int current = 0;
    int next = 1;
    int direction = 0;
    int cycle = 60;
    int t = 0;
    while (1) {
        if (lights[current].count == lights[current].green) {
            lights[current].count = lights[current].red;
            lights[next].count = lights[next].green;
            next = (next + 1) % 3;
            direction = -1;
        } else if (lights[current].count == lights[current].red) {
            lights[current].count = lights[current].yellow;
            lights[next].count = lights[next].green;
            next = (next + 1) % 3;
            direction = -1;
        } else if (lights[current].count == lights[current].yellow) {
            lights[current].count = lights[current].red;
            lights[next].count = lights[next].yellow;
            next = (next + 1) % 3;
            direction = 1;
        } else {
            lights[current].count = lights[current].green;
            lights[next].count = lights[next].red;
            next = (next + 1) % 3;
            direction = 1;
        }
        t += 1;
        if (t % cycle == 0) {
            printf("Light %d: %d\n", current, lights[current].count);
        }
        if (direction == -1) {
            current = (current + 1) % 3;
        } else {
            current = (current - 1) % 3;
        }
        sleep(1);
    }
    return 0;
}