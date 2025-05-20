//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

// Shape shifter function
void shapeShift(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

// Circuit simulation function
void simulateCircuit(int inp[], int logic[][MAX_NODES], int n) {
    int output[MAX_NODES] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (logic[i][j] == 1) {
                shapeShift(&inp[i], &inp[j]);
            }
        }
    }
    // Copying input array to output array
    for (int i = 0; i < n; i++) {
        output[i] = inp[i];
    }
    printf("\nOutput values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
}

int main() {
    int n, input[MAX_NODES], logic[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of nodes in the circuit (maximum %d): ", MAX_NODES);
    scanf("%d", &n);

    printf("\nEnter the input values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    printf("\nEnter the logic matrix (0/1): ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &logic[i][j]);
        }
    }

    printf("\nInput values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", input[i]);
    }

    simulateCircuit(input, logic, n);

    return 0;
}