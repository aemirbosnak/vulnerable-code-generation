//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to calculate the mean of an array
float calc_mean(float arr[], int size){

    float sum = 0.0;
    int i;

    for(i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum/size;
}

// Function to calculate the standard deviation of an array
float calc_std_deviation(float arr[], int size){

    float mean = calc_mean(arr, size);
    float sum = 0.0;
    int i;

    for(i = 0; i < size; i++){
        sum += pow(arr[i] - mean, 2);
    }

    return sqrt(sum/size);
}

int main(){

    // Declare a 2D array to store the data
    float data[MAX_SIZE][3];

    // Declare a variable to keep track of the number of rows in the data
    int rows = 0;

    // Open the data file
    FILE *file = fopen("data.txt", "r");

    // Check if the file opened successfully
    if(file == NULL){
        printf("Error opening file\n");
        return 1;
    }

    // Read the data from the file
    while(fscanf(file, "%f %f %f", &data[rows][0], &data[rows][1], &data[rows][2]) == 3){
        rows++;
    }

    // Close the file
    fclose(file);

    // Calculate the mean and standard deviation of column 1
    float col1_mean = calc_mean(data[0], rows);
    float col1_std_deviation = calc_std_deviation(data[0], rows);

    // Print the results
    printf("Column 1 Mean: %f\n", col1_mean);
    printf("Column 1 Standard Deviation: %f\n", col1_std_deviation);

    return 0;
}