//FormAI DATASET v1.0 Category: Data mining ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file;
    char filename[100];
    double *data;
    double sum = 0, mean = 0, median = 0, variance = 0, sd = 0;
    int i, j, count = 0, mode = 0, maxCount = 0;

    printf("Enter the name of the CSV file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found!\n");
        return EXIT_FAILURE;
    }

    // Counting the number of rows in the file
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') count++;
    }

    // Allocating memory for the data
    data = (double*) malloc(sizeof(double) * count);

    rewind(file);

    // Reading the data from the file
    for (i = 0; i < count; i++) {
        fscanf(file, "%lf", &data[i]);
        sum += data[i];
    }

    // Calculating the mean
    mean = sum / (double) count;

    // Sort the data in an ascending order
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (data[j] < data[i]) {
                double temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    // Calculating the median
    if (count % 2 == 0) {
        median = (data[count / 2] + data[count / 2 - 1]) / 2.0;
    } else {
        median = data[count / 2];
    }

    // Calculating the variance
    for (i = 0; i < count; i++) {
        variance += pow(data[i] - mean, 2);
        if (data[i] == data[i + 1]) {
            mode = data[i];
            maxCount++;
            if (maxCount == 1) {
                mode = 0;
            }
        }
    }

    variance /= (double) count;

    // Calculating the standard deviation
    sd = sqrt(variance);

    // Printing the results
    printf("Mean = %lf\n", mean);
    printf("Median = %lf\n", median);
    printf("Variance = %lf\n", variance);
    printf("Standard Deviation = %lf\n", sd);
    printf("Mode = %d\n", mode);

    // Freeing the allocated memory
    free(data);

    // Closing the file
    fclose(file);

    return EXIT_SUCCESS;
}