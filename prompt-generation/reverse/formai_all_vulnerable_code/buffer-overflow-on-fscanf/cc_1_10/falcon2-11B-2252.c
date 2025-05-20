//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and extract data
void read_file(const char* filename, int* data) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    fscanf(file, "%d", &(*data));
    fclose(file);
}

// Function to analyze data and find patterns
void analyze_data(int data[], int size) {
    int max = data[0];
    int min = data[0];
    int sum = 0;
    int avg = 0;
    int count = 0;
    
    // Find maximum and minimum values
    for (int i = 0; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
        if (data[i] < min) {
            min = data[i];
        }
    }
    
    // Calculate sum and average
    for (int i = 0; i < size; i++) {
        sum += data[i];
        count++;
    }
    avg = sum / count;
    
    // Print results
    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
    printf("Average value: %f\n", avg);
}

// Function to main program
int main(int argc, char* argv[]) {
    int data[100]; // Array to store data
    int size = 0; // Size of data array
    
    // Read file and extract data
    read_file(argv[1], data);
    size = sizeof(data) / sizeof(data[0]);
    
    // Analyze data and find patterns
    analyze_data(data, size);
    
    return 0;
}