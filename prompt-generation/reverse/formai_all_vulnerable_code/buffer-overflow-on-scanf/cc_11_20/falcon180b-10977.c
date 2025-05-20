//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define PI 3.14159265358979323846

int main() {
    double x[N], y[N], w[N], v[N];
    double sum = 0.0;
    int i, n;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    printf("Enter the sample values:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    printf("Enter the window type:\n");
    printf("1. Rectangle window\n");
    printf("2. Hanning window\n");
    printf("3. Hamming window\n");
    printf("4. Blackman window\n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            for (i = 0; i < n; i++) {
                w[i] = 1.0;
            }
            break;
        case 2:
            for (i = 0; i < n; i++) {
                w[i] = 0.5 - 0.5 * cos(2.0 * PI * i / (n - 1));
            }
            break;
        case 3:
            for (i = 0; i < n; i++) {
                w[i] = 0.54 - 0.46 * cos(2.0 * PI * i / (n - 1));
            }
            break;
        case 4:
            for (i = 0; i < n; i++) {
                w[i] = 0.42 - 0.5 * cos(2.0 * PI * i / (n - 1)) + 0.08 * cos(4.0 * PI * i / (n - 1));
            }
            break;
        default:
            printf("Invalid window type!\n");
            exit(1);
    }

    for (i = 0; i < n; i++) {
        v[i] = x[i] * w[i];
        sum += v[i];
    }

    printf("The sum of the weighted samples is: %lf\n", sum);

    return 0;
}