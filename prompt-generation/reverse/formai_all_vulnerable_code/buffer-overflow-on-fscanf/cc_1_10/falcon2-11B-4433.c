//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from file
void read_data(char *filename, int *data, int size) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fscanf(fp, "%d", data);
    fclose(fp);
}

// Function to perform data mining
void data_mining(int data[], int size) {
    int min = data[0];
    int max = data[0];

    // Find minimum and maximum values
    for (int i = 0; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }

    // Print results
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

int main() {
    char filename[] = "data.txt";
    int data[100];
    int size = 0;

    // Read data from file
    read_data(filename, data, size);

    // Perform data mining
    data_mining(data, size);

    return 0;
}