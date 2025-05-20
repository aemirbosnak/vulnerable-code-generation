//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to read data from a file
int read_data(FILE *fp, int *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (fscanf(fp, "%d", &data[i])!= 1) {
            printf("Error reading data from file.\n");
            exit(1);
        }
    }
    return 0;
}

// Function to write data to a file
int write_data(FILE *fp, int *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (fprintf(fp, "%d ", data[i]) < 0) {
            printf("Error writing data to file.\n");
            exit(1);
        }
    }
    return 0;
}

// Function to sort data in ascending order
void sort_data(int *data, int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Function to calculate the mean of data
double calculate_mean(int *data, int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += data[i];
    }
    return (double) sum / size;
}

// Function to calculate the standard deviation of data
double calculate_std_dev(int *data, int size, double mean) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += pow((data[i] - mean), 2);
    }
    return sqrt(sum / size);
}

// Main function
int main() {
    FILE *fp;
    int data[100], size, i;
    double mean, std_dev;

    // Open the file for reading and writing
    fp = fopen("data.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read data from the file
    read_data(fp, data, 100);
    size = 0;
    while (data[size]!= -1) {
        size++;
    }

    // Sort the data in ascending order
    sort_data(data, size);

    // Calculate the mean of the data
    mean = calculate_mean(data, size);
    printf("Mean: %.2f\n", mean);

    // Calculate the standard deviation of the data
    std_dev = calculate_std_dev(data, size, mean);
    printf("Standard deviation: %.2f\n", std_dev);

    // Write the sorted data to the file
    fseek(fp, 0, SEEK_SET);
    write_data(fp, data, size);

    // Close the file
    fclose(fp);

    return 0;
}