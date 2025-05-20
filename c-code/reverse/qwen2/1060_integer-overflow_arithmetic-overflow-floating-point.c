#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SHARED_MEMORY_SIZE 4

int main() {
    int *shared_memory = (int *)malloc(SHARED_MEMORY_SIZE * sizeof(int));
    if (shared_memory == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    while (1) {
        int current_temp = rand() % 50 - 25; // Random temperature between -25 and 24 degrees Celsius
        int previous_temp = *(shared_memory + 1);

        if (previous_temp != current_temp) {
            *(shared_memory + 0) = current_temp;

            char temp_shape[20];
            if (current_temp <= -10) {
                strcpy(temp_shape, "Freezing");
            } else if (current_temp > -10 && current_temp <= 0) {
                strcpy(temp_shape, "Cold");
            } else if (current_temp > 0 && current_temp <= 15) {
                strcpy(temp_shape, "Mild");
            } else if (current_temp > 15 && current_temp <= 30) {
                strcpy(temp_shape, "Warm");
            } else {
                strcpy(temp_shape, "Hot");
            }

            printf("Temperature: %d°C, Shape: %s\n", current_temp, temp_shape);
        }

        *(shared_memory + 1) = current_temp;
        sleep(1); // Simulate time passing
    }

    free(shared_memory);
    return EXIT_SUCCESS;
}
