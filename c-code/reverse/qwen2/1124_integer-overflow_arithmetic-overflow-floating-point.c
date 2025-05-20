#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int simulations = -1;
    float altitude = 0.0;

    for (int i = 0; i < simulations; i++) {
        altitude += 100.0;
        if (altitude > 1e30) {
            printf("Drone altitude: %f\n", altitude);
        }
    }

    return 0;
}
