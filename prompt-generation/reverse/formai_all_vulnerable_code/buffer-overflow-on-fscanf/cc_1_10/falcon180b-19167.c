//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main() {
    int i, j, k;
    double x, y, z;
    double sum = 0.0;
    double avg = 0.0;
    double var = 0.0;
    double std_dev = 0.0;
    double *data = (double *) malloc(SIZE * sizeof(double));
    FILE *fp;
    char filename[50];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < SIZE; i++) {
        fscanf(fp, "%lf", &data[i]);
    }

    fclose(fp);

    printf("Enter your choice:\n");
    printf("1. Calculate mean\n");
    printf("2. Calculate standard deviation\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < SIZE; i++) {
                sum += data[i];
            }
            avg = sum / SIZE;
            printf("Mean: %.2lf\n", avg);
            break;
        case 2:
            for (i = 0; i < SIZE; i++) {
                x = data[i] - avg;
                sum += x * x;
            }
            var = sum / SIZE;
            std_dev = sqrt(var);
            printf("Standard deviation: %.2lf\n", std_dev);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    free(data);

    return 0;
}