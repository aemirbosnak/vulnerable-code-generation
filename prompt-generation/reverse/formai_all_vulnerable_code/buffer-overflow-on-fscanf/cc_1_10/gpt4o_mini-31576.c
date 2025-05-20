//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 1000

// Function prototypes
double calculate_mean(int *data, int count);
double calculate_median(int *data, int count);
int calculate_mode(int *data, int count);
void sort(int *data, int count);
void read_data(const char *filename, int *data, int *count);

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;

    read_data("data.txt", numbers, &count);

    if (count == 0) {
        printf("No data available for analysis.\n");
        return 1;
    }

    double mean = calculate_mean(numbers, count);
    double median = calculate_median(numbers, count);
    int mode = calculate_mode(numbers, count);

    printf("Data Statistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}

// Function to read data from file and store it in an array
void read_data(const char *filename, int *data, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%d", &data[*count]) == 1) {
        (*count)++;
        if (*count >= MAX_NUMBERS) {
            fprintf(stderr, "Maximum number of entries exceeded.\n");
            break;
        }
    }

    fclose(file);
}

// Function to calculate the mean
double calculate_mean(int *data, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += data[i];
    }
    return sum / count;
}

// Function to calculate the median
double calculate_median(int *data, int count) {
    sort(data, count);
    if (count % 2 == 0) {
        return (data[count/2 - 1] + data[count/2]) / 2.0;
    } else {
        return data[count/2];
    }
}

// Function to calculate the mode
int calculate_mode(int *data, int count) {
    int maxValue = 0, maxCount = 0;

    for (int i = 0; i < count; i++) {
        int count = 0;
        for (int j = 0; j < count; j++) {
            if (data[j] == data[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = data[i];
        }
    }

    // This is a simple case, it returns the first encountered mode
    return maxValue;
}

// Function to sort the array using bubble sort
void sort(int *data, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}