//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define MAX_FUEL 5000
#define INTERVAL 1000

int currentFuel = MAX_FUEL;
int currentSpeed = 0;
bool gameover = false;

void updateStatus(int time) {
    if (currentFuel <= 0) {
        printf("Game over: Out of fuel!\n");
        gameover = true;
    } else if (currentSpeed >= 10000) {
        printf("Game over: Speed too high!\n");
        gameover = true;
    } else if (currentSpeed <= 0) {
        printf("Game over: You have crashed!\n");
        gameover = true;
    } else {
        printf("Time: %d seconds, Speed: %d m/s, Fuel: %dL\n", time, currentSpeed, currentFuel);
    }
}

void adjustFuel(int level) {
    if (currentFuel + level < 0) {
        currentFuel = 0;
    } else if (currentFuel + level > MAX_FUEL) {
        currentFuel = MAX_FUEL;
    } else {
        currentFuel += level;
    }
}

void calculateSpeed(int thrust) {
    int deltaV = thrust / INTERVAL;
    int burnRate = thrust / 10;
    adjustFuel(-burnRate);
    currentSpeed += deltaV;
}

int main() {
    int time = 0;
    printf("Welcome to Procedural Space Adventure Game!\n");

    while (!gameover) {
        int thrust;
        printf("Enter Thrust to continue: ");
        scanf("%d", &thrust);
        calculateSpeed(thrust);
        time++;
        updateStatus(time);
    }

    printf("Game Over!\n");
    return 0;
}