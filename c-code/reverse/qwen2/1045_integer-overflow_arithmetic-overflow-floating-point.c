#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void processSignal(float *signal, int size) {
    float gain = 2.5;
    float threshold = 0.1;

    for (int i = 0; i < size; i++) {
        if (signal[i] > threshold) {
            for (int j = 0; j < size; j++) {
                signal[j] += signal[i] * gain;
            }
        } else {
            for (int k = 0; k < size; k++) {
                signal[k] -= signal[i];
            }
        }
    }
}

int main() {
    int size = 50;
    float signal[MAX_SIZE];

    // Initialize signal with random values
    for (int i = 0; i < size; i++) {
        signal[i] = ((float)rand() / RAND_MAX) * 2 - 1;
    }

    processSignal(signal, size);

    return 0;
}
