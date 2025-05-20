//GEMINI-pro DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char name[20];
    int age;
    double height;
    double weight;
};

int main() {
    FILE *fp;
    struct data data_array[100];
    int i, n;

    // Open the file for reading
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the number of data points
    fscanf(fp, "%d", &n);

    // Read the data points
    for (i = 0; i < n; i++) {
        fscanf(fp, "%s %d %lf %lf", data_array[i].name, &data_array[i].age, &data_array[i].height, &data_array[i].weight);
    }

    // Close the file
    fclose(fp);

    // Calculate the mean and standard deviation of each variable
    double mean_age = 0, mean_height = 0, mean_weight = 0;
    double stddev_age = 0, stddev_height = 0, stddev_weight = 0;
    for (i = 0; i < n; i++) {
        mean_age += data_array[i].age;
        mean_height += data_array[i].height;
        mean_weight += data_array[i].weight;
    }
    mean_age /= n;
    mean_height /= n;
    mean_weight /= n;

    for (i = 0; i < n; i++) {
        stddev_age += (data_array[i].age - mean_age) * (data_array[i].age - mean_age);
        stddev_height += (data_array[i].height - mean_height) * (data_array[i].height - mean_height);
        stddev_weight += (data_array[i].weight - mean_weight) * (data_array[i].weight - mean_weight);
    }
    stddev_age = sqrt(stddev_age / n);
    stddev_height = sqrt(stddev_height / n);
    stddev_weight = sqrt(stddev_weight / n);

    // Print the results
    printf("Mean age: %lf\n", mean_age);
    printf("Standard deviation of age: %lf\n", stddev_age);
    printf("Mean height: %lf\n", mean_height);
    printf("Standard deviation of height: %lf\n", stddev_height);
    printf("Mean weight: %lf\n", mean_weight);
    printf("Standard deviation of weight: %lf\n", stddev_weight);

    return EXIT_SUCCESS;
}