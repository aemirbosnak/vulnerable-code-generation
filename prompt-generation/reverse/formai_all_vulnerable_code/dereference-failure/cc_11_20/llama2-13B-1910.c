//LLAMA2-13B DATASET v1.0 Category: Audio processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main() {
    double *buffer;
    int i, j, k;
    float noise = 0.5;

    srand(time(NULL));

    buffer = calloc(BUFFER_SIZE, sizeof(double));
    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = (double)rand() / RAND_MAX;
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            if (i == j) {
                continue;
            }
            k = (int)((noise * (double)rand() / RAND_MAX) * 2 - 1);
            buffer[i] += k * buffer[j];
        }
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", buffer[i]);
    }
    printf("\n");

    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = (double)rand() / RAND_MAX;
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            if (i == j) {
                continue;
            }
            k = (int)((noise * (double)rand() / RAND_MAX) * 2 - 1);
            buffer[i] += k * buffer[j];
        }
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", buffer[i]);
    }
    printf("\n");

    for (i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = (double)rand() / RAND_MAX;
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        for (j = 0; j < BUFFER_SIZE; j++) {
            if (i == j) {
                continue;
            }
            k = (int)((noise * (double)rand() / RAND_MAX) * 2 - 1);
            buffer[i] += k * buffer[j];
        }
    }

    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%f ", buffer[i]);
    }
    printf("\n");

    free(buffer);
    return 0;
}