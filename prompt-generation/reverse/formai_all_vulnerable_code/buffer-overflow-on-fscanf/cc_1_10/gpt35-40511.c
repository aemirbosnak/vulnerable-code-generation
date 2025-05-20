//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read data from file and store in array
void readData(int arr[], char* filename, int size) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot Open File!\n");
        exit(0);
    }
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}

// Function to print data from array
void printData(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform data mining (finding max, min, sum and average of data)
void dataMining(int arr[], int size, int* max, int* min, int* sum, float* avg) {
    *max = arr[0];
    *min = arr[0];
    *sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
        *sum += arr[i];
    }
    *avg = *sum / (float)size;
}

int main() {
    int size = 10;
    int arr[size];
    char* filename = "data.txt";
    int max, min, sum;
    float avg;
    readData(arr, filename, size);
    printf("Data in file: ");
    printData(arr, size);
    dataMining(arr, size, &max, &min, &sum, &avg);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
    return 0;
}