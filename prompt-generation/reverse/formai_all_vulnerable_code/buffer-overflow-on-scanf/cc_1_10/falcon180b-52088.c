//Falcon-180B DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the mean of an array of numbers
double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double) sum / n;
}

// Function to calculate the standard deviation of an array of numbers
double std_dev(int arr[], int n) {
    double mean_val = mean(arr, n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((arr[i] - mean_val), 2);
    }
    return sqrt(sum / n);
}

// Function to read data from a file and store it in an array
int read_data(char filename[], int arr[], int n) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &arr[i])!= 1) {
            printf("Error reading data\n");
            exit(0);
        }
    }
    fclose(fp);
    return 0;
}

// Function to write the results to a file
int write_results(char filename[], double mean_val, double std_dev_val) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }
    fprintf(fp, "Mean = %.2f\n", mean_val);
    fprintf(fp, "Standard Deviation = %.2f\n", std_dev_val);
    fclose(fp);
    return 0;
}

int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    char filename[50];
    printf("Enter the name of the file to store the results: ");
    scanf("%s", filename);
    read_data(filename, arr, n);
    double mean_val = mean(arr, n);
    double std_dev_val = std_dev(arr, n);
    write_results(filename, mean_val, std_dev_val);
    printf("Results written to file %s\n", filename);
    return 0;
}