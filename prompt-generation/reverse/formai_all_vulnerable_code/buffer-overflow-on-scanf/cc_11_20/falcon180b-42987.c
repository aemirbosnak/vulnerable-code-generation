//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define MAX_DELAY 100

int main() {
    int i, j, k, n, m, index, max_index;
    float x[SIZE], y[MAX_DELAY + SIZE - 1], temp[SIZE];
    float max_value, sum;

    printf("Enter the size of the signal: ");
    scanf("%d", &n);

    printf("Enter the signal values:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the maximum delay value: ");
    scanf("%d", &m);

    for (i = 0; i <= m; i++) {
        y[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= m; j++) {
            if (j == 0) {
                y[j] += x[i];
            } else if (j > 0 && j <= m) {
                temp[j - 1] = x[i];
                for (k = 0; k < j; k++) {
                    x[k] = x[k + 1];
                }
                x[j - 1] = temp[j - 1];
            }
        }

        max_value = y[0];
        max_index = 0;

        for (j = 1; j <= m; j++) {
            if (y[j] > max_value) {
                max_value = y[j];
                max_index = j;
            }
        }

        printf("The autocorrelation value at lag %d is: %f\n", max_index, max_value);
    }

    return 0;
}