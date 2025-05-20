//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the data we want to manage
typedef struct {
    int id;
    char name[50];
    float value;
} Data;

// Function to allocate memory for a new Data structure
Data* allocate_data() {
    Data* new_data = (Data*) malloc(sizeof(Data));
    if (new_data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    return new_data;
}

// Function to initialize a Data structure
void initialize_data(Data* data) {
    data->id = 0;
    strcpy(data->name, "");
    data->value = 0.0;
}

// Function to free memory allocated for a Data structure
void free_data(Data* data) {
    free(data);
}

// Function to print a Data structure
void print_data(Data* data) {
    printf("ID: %d\n", data->id);
    printf("Name: %s\n", data->name);
    printf("Value: %.2f\n", data->value);
}

// Main function to demonstrate memory management
int main() {
    Data* data1 = allocate_data(); // Allocate memory for a new Data structure
    initialize_data(data1); // Initialize the Data structure
    print_data(data1); // Print the Data structure

    Data* data2 = allocate_data(); // Allocate memory for another new Data structure
    initialize_data(data2); // Initialize the Data structure
    print_data(data2); // Print the Data structure

    free_data(data1); // Free memory allocated for the first Data structure
    free_data(data2); // Free memory allocated for the second Data structure

    return 0;
}