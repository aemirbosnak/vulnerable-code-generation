//Code Llama-13B DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    #define NUM_VALUES 1000000
    #define MAX_VALUE 10000000

    int main() {
        int i, j, k;
        int* values = malloc(NUM_VALUES * sizeof(int));
        int* sorted = malloc(NUM_VALUES * sizeof(int));

        srand(time(NULL));

        for (i = 0; i < NUM_VALUES; i++) {
            values[i] = rand() % MAX_VALUE;
        }

        for (i = 0; i < NUM_VALUES; i++) {
            for (j = i + 1; j < NUM_VALUES; j++) {
                if (values[i] > values[j]) {
                    k = values[i];
                    values[i] = values[j];
                    values[j] = k;
                }
            }
        }

        for (i = 0; i < NUM_VALUES; i++) {
            sorted[i] = values[i];
        }

        for (i = 0; i < NUM_VALUES; i++) {
            for (j = i + 1; j < NUM_VALUES; j++) {
                if (sorted[i] > sorted[j]) {
                    k = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = k;
                }
            }
        }

        for (i = 0; i < NUM_VALUES; i++) {
            if (values[i] != sorted[i]) {
                printf("Error at index %d: %d != %d\n", i, values[i], sorted[i]);
            }
        }

        free(values);
        free(sorted);

        return 0;
    }