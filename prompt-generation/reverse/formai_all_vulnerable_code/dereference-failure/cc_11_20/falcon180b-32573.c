//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    char *filename = "example.txt";
    FILE *file;
    char buffer[MAX_SIZE];
    int i, j, k, n, m;
    float *data;
    int rows, cols;

    // Open file and read data
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fgets(buffer, MAX_SIZE, file); // Skip header
    rows = atoi(strtok(buffer, " "));
    cols = atoi(strtok(NULL, " "));
    data = (float *) malloc(rows * cols * sizeof(float));
    if (data == NULL) {
        printf("Error allocating memory.\n");
        exit(2);
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(file, "%f", &data[i * cols + j]);
        }
    }
    fclose(file);

    // Perform data recovery
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (isnan(data[i * cols + j])) {
                data[i * cols + j] = 0;
            }
        }
    }

    // Save recovered data
    sprintf(filename, "recovered_%d_%d.txt", rows, cols);
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(3);
    }
    fprintf(file, "%d %d\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(file, "%.2f ", data[i * cols + j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    printf("Data recovery completed.\n");
    return 0;
}