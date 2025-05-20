//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int i, n;
    double x[MAX_SIZE], y[MAX_SIZE];
    FILE *fp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Maximum size is %d\n", MAX_SIZE);
        exit(1);
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot create file\n");
        exit(1);
    }

    fprintf(fp, "Original Signal:\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%lf\n", x[i]);
    }

    fclose(fp);

    for (i = 0; i < n; i++) {
        y[i] = x[i] * 2;
    }

    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error: Cannot append to file\n");
        exit(1);
    }

    fprintf(fp, "\nAmplified Signal:\n");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%lf\n", y[i]);
    }

    fclose(fp);

    return 0;
}