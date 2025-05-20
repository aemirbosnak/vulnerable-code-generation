//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 10000

int main() {
    FILE *fp;
    char filename[100];
    int n, i;
    double x, y, sum = 0.0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        fscanf(fp, "%lf", &data[i]);
        sum += data[i];
    }

    fclose(fp);

    printf("Mean: %.2lf\n", sum / n);

    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fprintf(fp, "Mean: %.2lf\n", sum / n);

    fclose(fp);

    free(data);

    return 0;
}