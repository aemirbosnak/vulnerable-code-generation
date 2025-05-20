//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

// Structure to hold the data
typedef struct {
    int age;
    float height;
    char gender[5];
} customer_t;

// Function to read data from a file
customer_t *read_data(const char *file_name) {
    // Open the file in read mode
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    // Create an array to store the data
    customer_t *data = (customer_t *)malloc(MAX_ROWS * sizeof(customer_t));
    int row_ctr = 0;

    // Read the data from the file
    while (fscanf(file, "%d%f%5s", &data[row_ctr].age, &data[row_ctr].height, data[row_ctr].gender) == 3) {
        row_ctr++;
    }

    // Check if the data was read successfully
    if (feof(file) == 0) {
        printf("Error: Unexpected end of file\n");
    }

    // Close the file
    fclose(file);

    return data;
}

// Function to print the data
void print_data(customer_t *data, int num_rows) {
    int row_ctr = 0;

    printf("Data:\n");
    while (row_ctr < num_rows) {
        printf("%d %f %s\n", data[row_ctr].age, data[row_ctr].height, data[row_ctr].gender);
        row_ctr++;
    }
}

// Function to calculate the average height
float calculate_average_height(customer_t *data, int num_rows) {
    int row_ctr = 0;
    float sum_height = 0;

    while (row_ctr < num_rows) {
        sum_height += data[row_ctr].height;
        row_ctr++;
    }

    return sum_height / num_rows;
}

// Function to main function
int main() {
    // Read the data from a file
    customer_t *data = read_data("customers.dat");
    if (data == NULL) {
        return 1;
    }

    // Print the data
    print_data(data, MAX_ROWS);

    // Calculate the average height
    float average_height = calculate_average_height(data, MAX_ROWS);
    printf("Average height: %f\n", average_height);

    // Free the memory
    free(data);

    return 0;
}