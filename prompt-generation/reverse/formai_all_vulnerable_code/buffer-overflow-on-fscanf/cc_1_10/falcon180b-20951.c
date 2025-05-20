//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1024

void fft(double *data, int n) {
    int i, j, k, l;
    double theta, w, wr, wi, temp;
    double *even, *odd;

    even = (double *) malloc(n * sizeof(double));
    odd = (double *) malloc(n * sizeof(double));

    for (i = 0; i < n; i++) {
        even[i] = data[i];
    }

    for (i = 0; i < n / 2; i++) {
        j = i * 2;
        temp = even[i];
        even[i] = even[j];
        even[j] = temp;
        temp = odd[i];
        odd[i] = odd[j];
        odd[j] = temp;
    }

    for (l = 1; l < n; l *= 2) {
        theta = M_PI / l;
        wr = cos(theta);
        wi = sin(theta);

        for (i = 0; i < n / 2; i++) {
            j = i * 2;
            temp = even[i];
            even[i] = even[i] + wr * odd[j];
            even[j] = even[j] - wr * temp;
            temp = even[i] + wi * odd[j];
            odd[j] = odd[j] + wi * temp;
            odd[i] = odd[i] - wi * temp;
        }
    }

    for (i = 0; i < n; i++) {
        data[i] = even[i];
    }

    free(even);
    free(odd);
}

int main() {
    int i;
    double data[SIZE], freq[SIZE / 2];
    FILE *fp;

    fp = fopen("input.txt", "r");

    for (i = 0; i < SIZE; i++) {
        fscanf(fp, "%lf", &data[i]);
    }

    fft(data, SIZE);

    for (i = 0; i < SIZE / 2; i++) {
        freq[i] = data[i] * (double) SIZE / 2;
    }

    printf("Frequency domain:\n");
    for (i = 0; i < SIZE / 2; i++) {
        printf("%d: %lf\n", i, freq[i]);
    }

    fclose(fp);

    return 0;
}