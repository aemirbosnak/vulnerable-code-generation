//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define N 20

// Function to perform convolution operation
void convolve(int x[], int y[], int n) {
    int i, j, k;
    int result[N];

    for(i = 0; i < n+n-1; i++) {
        result[i] = 0;

        for(j = 0; j <= i; j++) {
            k = i - j;

            if(j < n && k < n) {
                result[i] += x[j] * y[k];
            }
        }
    }

    // Print the result of convolution
    printf("Result of convolution:\n");

    for(i = 0; i < n+n-1; i++) {
        printf("%d\t", result[i]);
    }

    printf("\n");
}

int main() {
    int i, n;
    int x[N], y[N];

    // Get input from user
    printf("Enter value for n (signal length): ");
    scanf("%d", &n);

    printf("Enter values for x[n]:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter values for y[n]:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    // Call the convolve function
    convolve(x, y, n);

    return 0;
}