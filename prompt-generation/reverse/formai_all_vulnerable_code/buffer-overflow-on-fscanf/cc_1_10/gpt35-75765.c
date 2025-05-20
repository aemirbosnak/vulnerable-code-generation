//FormAI DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define struct for holding data
typedef struct {
    int id;
    float value1;
    float value2;
} Data;

// Define function for loading data from file
int load_data(Data** data_ptr, int* num_entries) {
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return -1;
    }
    
    // Get number of entries in file
    fscanf(fp, "%d", num_entries);
    
    // Allocate memory for data array
    *data_ptr = malloc(sizeof(Data) * (*num_entries));
    
    // Load data from file into array
    for (int i = 0; i < *num_entries; i++) {
        (*data_ptr)[i].id = i;
        fscanf(fp, "%f %f", &((*data_ptr)[i].value1), &((*data_ptr)[i].value2));
    }
    
    fclose(fp);
    return 0;
}

// Define function for processing data
int process_data(Data* data, int num_entries) {
    float total1 = 0, total2 = 0;
    
    // Calculate total values of data
    for (int i = 0; i < num_entries; i++) {
        total1 += data[i].value1;
        total2 += data[i].value2;
    }
    
    // Calculate averages
    float avg1 = total1 / num_entries;
    float avg2 = total2 / num_entries;
    
    // Print results
    printf("Average value 1: %f\n", avg1);
    printf("Average value 2: %f\n", avg2);
    
    return 0;
}

int main() {
    Data* data;
    int num_entries;
    
    // Load data from file
    int load_result = load_data(&data, &num_entries);
    if (load_result == -1) {
        return 1;
    }
    
    // Process data
    int process_result = process_data(data, num_entries);
    if (process_result == -1) {
        return 1;
    }
    
    // Free memory
    free(data);
    
    return 0;
}