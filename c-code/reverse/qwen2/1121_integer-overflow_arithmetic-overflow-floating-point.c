#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITY -9.81

typedef struct {
    double x;
    double y;
} Position;

void simulateDroneFlight(int simulations) {
    srand(time(NULL));
    for (int i = 0; i < simulations; i++) {
        double initialHeight = rand() % 100 + 50;
        double time = 0;
        Position pos = {0, initialHeight};
        while (pos.y >= 0 && time <= 10) {
            pos.y += GRAVITY * time;
            time += 0.1;
        }
        if (pos.y < 0) {
            printf("Simulation %d: Drone crashed at height %.2f meters after %.2f seconds.\n", i + 1, -pos.y, time);
        } else {
            printf("Simulation %d: Drone landed safely at height %.2f meters after %.2f seconds.\n", i + 1, pos.y, time);
        }
    }
}

int main() {
    int simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &simulations);
    simulateDroneFlight(simulations);
    return 0;
}
