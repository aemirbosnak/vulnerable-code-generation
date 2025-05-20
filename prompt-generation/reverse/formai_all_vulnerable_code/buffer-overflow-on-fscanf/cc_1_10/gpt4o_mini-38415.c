//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100

void calculate_statistics(double numbers[], int count, double *mean, double *median, double *mode, double *std_dev) {
    double sum = 0.0;
    double sum_sq = 0.0;
    int frequency[MAX_NUMBERS] = {0};
    int max_freq = 0;
    
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        sum_sq += numbers[i] * numbers[i];
        frequency[(int)numbers[i]]++;
        if (frequency[(int)numbers[i]] > max_freq) {
            max_freq = frequency[(int)numbers[i]];
            *mode = numbers[i];
        }
    }

    *mean = sum / count;
    *std_dev = sqrt((sum_sq / count) - (*mean * *mean));

    // Finding median
    // First, we need to sort the numbers
    double temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    if (count % 2 == 0) {
        *median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        *median = numbers[count / 2];
    }
}

void read_numbers_from_file(const char *filename, double numbers[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%lf", &numbers[*count]) == 1) {
        (*count)++;
    }

    fclose(file);
}

void write_statistics_to_file(const char *filename, double mean, double median, double mode, double std_dev) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Mean: %.2f\n", mean);
    fprintf(file, "Median: %.2f\n", median);
    fprintf(file, "Mode: %.2f\n", mode);
    fprintf(file, "Standard Deviation: %.2f\n", std_dev);

    fclose(file);
}

int main() {
    double numbers[MAX_NUMBERS];
    int count;
    double mean, median, mode = 0.0, std_dev;

    const char *input_file = "data.txt";
    const char *output_file = "statistics.txt";

    // Read numbers from file
    read_numbers_from_file(input_file, numbers, &count);
    
    // Calculate statistics
    calculate_statistics(numbers, count, &mean, &median, &mode, &std_dev);
    
    // Write statistics to file
    write_statistics_to_file(output_file, mean, median, mode, std_dev);

    printf("Statistics calculated and saved to %s\n", output_file);
    
    return 0;
}