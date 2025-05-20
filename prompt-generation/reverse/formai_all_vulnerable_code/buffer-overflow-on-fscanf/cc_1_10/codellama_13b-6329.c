//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: protected
// Data mining example program

#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1000

// Structure to hold data
struct data {
    int id;
    float value;
};

// Function to read data from file
void read_data(struct data *data, int *n) {
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%d %f", &data[i].id, &data[i].value) == 2) {
        i++;
    }
    *n = i;
    fclose(fp);
}

// Function to find average value
float find_average(struct data *data, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i].value;
    }
    return sum / n;
}

// Function to find standard deviation
float find_std_dev(struct data *data, int n, float avg) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (data[i].value - avg) * (data[i].value - avg);
    }
    return sqrt(sum / (n - 1));
}

// Function to find range
float find_range(struct data *data, int n) {
    float max = data[0].value;
    float min = data[0].value;
    for (int i = 1; i < n; i++) {
        if (data[i].value > max) {
            max = data[i].value;
        } else if (data[i].value < min) {
            min = data[i].value;
        }
    }
    return max - min;
}

// Main function
int main() {
    // Declare variables
    struct data data[MAX_DATA];
    int n;
    float avg, std_dev, range;

    // Read data from file
    read_data(data, &n);

    // Find average value
    avg = find_average(data, n);

    // Find standard deviation
    std_dev = find_std_dev(data, n, avg);

    // Find range
    range = find_range(data, n);

    // Print results
    printf("Average: %.2f\n", avg);
    printf("Standard Deviation: %.2f\n", std_dev);
    printf("Range: %.2f\n", range);

    return 0;
}