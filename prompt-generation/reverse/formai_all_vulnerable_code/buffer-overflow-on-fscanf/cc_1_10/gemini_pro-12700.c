//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATA_POINTS 10000
#define NUM_BUCKETS 10

// Function to read data points from a file
int read_data_points(float data_points[], int max_data_points, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int num_data_points = 0;
    while (fscanf(fp, "%f", &data_points[num_data_points]) == 1) {
        num_data_points++;
        if (num_data_points >= max_data_points) {
            break;
        }
    }

    fclose(fp);

    return num_data_points;
}

// Function to create a histogram from the data points
void create_histogram(float data_points[], int num_data_points, int num_buckets, float histogram[]) {
    // Initialize the histogram to zero
    for (int i = 0; i < num_buckets; i++) {
        histogram[i] = 0.0;
    }

    // Calculate the range of the data points
    float min_value = data_points[0];
    float max_value = data_points[0];
    for (int i = 1; i < num_data_points; i++) {
        if (data_points[i] < min_value) {
            min_value = data_points[i];
        } else if (data_points[i] > max_value) {
            max_value = data_points[i];
        }
    }

    // Calculate the width of each bucket
    float bucket_width = (max_value - min_value) / num_buckets;

    // For each data point, find the corresponding bucket and increment its count
    for (int i = 0; i < num_data_points; i++) {
        int bucket_index = (int)((data_points[i] - min_value) / bucket_width);
        if (bucket_index < 0) {
            bucket_index = 0;
        } else if (bucket_index >= num_buckets) {
            bucket_index = num_buckets - 1;
        }
        histogram[bucket_index]++;
    }

    // Normalize the histogram so that the sum of all counts is 1.0
    float sum = 0.0;
    for (int i = 0; i < num_buckets; i++) {
        sum += histogram[i];
    }
    for (int i = 0; i < num_buckets; i++) {
        histogram[i] /= sum;
    }
}

// Function to print the histogram
void print_histogram(float histogram[], int num_buckets) {
    printf("Histogram:\n");
    for (int i = 0; i < num_buckets; i++) {
        printf("Bucket %d: %.2f%%\n", i, histogram[i] * 100.0);
    }
}

int main() {
    // Read the data points from a file
    float data_points[MAX_DATA_POINTS];
    int num_data_points = read_data_points(data_points, MAX_DATA_POINTS, "data.txt");
    if (num_data_points == -1) {
        return -1;
    }

    // Create a histogram from the data points
    float histogram[NUM_BUCKETS];
    create_histogram(data_points, num_data_points, NUM_BUCKETS, histogram);

    // Print the histogram
    print_histogram(histogram, NUM_BUCKETS);

    return 0;
}