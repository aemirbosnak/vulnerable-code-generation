#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL_LENGTH 1024

void processSignal(int* signal, int length) {
    if (length > MAX_SIGNAL_LENGTH) {
        fprintf(stderr, "Error: Signal length exceeds maximum allowed.\n");
        exit(EXIT_FAILURE);
    }

    // Example processing: Normalize the signal
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += signal[i];
    }
    double average = sum / length;

    for (int i = 0; i < length; i++) {
        signal[i] = (int)((signal[i] - average) * 100); // Scale down to avoid overflow
    }
}

int main() {
    int signal[MAX_SIGNAL_LENGTH];
    int length;

    printf("Enter the number of elements in the signal: ");
    scanf("%d", &length);

    printf("Enter the elements of the signal:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &signal[i]);
    }

    processSignal(signal, length);

    printf("Processed signal:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", signal[i]);
    }
    printf("\n");

    return 0;
}
