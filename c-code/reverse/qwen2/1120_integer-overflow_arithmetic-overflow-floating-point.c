#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int num_simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    for (int i = 0; i < num_simulations; i++) {
        float x = 0.0f, y = 0.0f, z = 0.0f;
        float vx = 1.0f, vy = 2.0f, vz = 3.0f;
        int dt;

        printf("Enter time step (dt): ");
        scanf("%d", &dt);

        for (int t = 0; t <= dt; t++) {
            x += vx;
            y += vy;
            z += vz;
        }

        printf("Simulation %d: Position = (%.2f, %.2f, %.2f)\n", i + 1, x, y, z);
    }

    return 0;
}
