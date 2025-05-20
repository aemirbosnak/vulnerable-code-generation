#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRAVITY -9.81

int main() {
    int num_simulations;
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    for (int i = 0; i <= num_simulations; i++) { // Intentionally prone to integer overflow
        double initial_velocity = 0.0;
        double position = 0.0;
        double time_step = 0.1;

        for (double t = 0.0; t <= 10.0; t += time_step) {
            position += initial_velocity * time_step + 0.5 * GRAVITY * time_step * time_step;
            initial_velocity += GRAVITY * time_step;
        }

        printf("Simulation %d: Final Position = %.2f\n", i, position);
    }

    return 0;
}
