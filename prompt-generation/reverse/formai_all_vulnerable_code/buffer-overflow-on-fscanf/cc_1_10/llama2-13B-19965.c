//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

// Structure to store data point
typedef struct {
    double x;
    double y;
} data_point;

// Function to read data from file
data_point* read_data(char* file_name) {
    int i = 0;
    data_point* data = NULL;
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }
    while (fscanf(file, "%lf%lf", &data[i].x, &data[i].y) == 2) {
        i++;
    }
    fclose(file);
    return data;
}

// Function to calculate mean and standard deviation
void calculate_stats(data_point* data, int num_rows) {
    double sum_x = 0, sum_y = 0;
    double sum_squared_x = 0, sum_squared_y = 0;
    int i;
    for (i = 0; i < num_rows; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
        sum_squared_x += data[i].x * data[i].x;
        sum_squared_y += data[i].y * data[i].y;
    }
    double mean_x = sum_x / num_rows;
    double mean_y = sum_y / num_rows;
    double std_dev_x = sqrt(sum_squared_x / (num_rows - 1));
    double std_dev_y = sqrt(sum_squared_y / (num_rows - 1));
    printf("Mean X: %f\n", mean_x);
    printf("Mean Y: %f\n", mean_y);
    printf("Standard Deviation X: %f\n", std_dev_x);
    printf("Standard Deviation Y: %f\n", std_dev_y);
}

int main() {
    char file_name[] = "data.csv";
    data_point* data = read_data(file_name);
    if (data == NULL) {
        return 1;
    }
    int num_rows = sizeof(data) / sizeof(data_point);
    calculate_stats(data, num_rows);
    free(data);
    return 0;
}