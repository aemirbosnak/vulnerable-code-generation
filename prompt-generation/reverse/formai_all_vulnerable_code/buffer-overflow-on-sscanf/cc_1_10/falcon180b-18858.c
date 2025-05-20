//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
void read_input(FILE *input_file, double *time_array, double *altitude_array);
void calculate_distance(double *time_array, double *altitude_array, double *distance_array);
void output_results(FILE *output_file, double *time_array, double *altitude_array, double *distance_array);

int main() {
    FILE *input_file, *output_file;
    double time_array[100], altitude_array[100], distance_array[100];
    int num_data_points;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Read input data
    read_input(input_file, time_array, altitude_array);

    // Calculate distance
    calculate_distance(time_array, altitude_array, distance_array);

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Write output data
    num_data_points = fwrite(distance_array, sizeof(double), 100, output_file);
    if (num_data_points!= 100) {
        printf("Error: Could not write all output data.\n");
        exit(1);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Function to read input data from file
void read_input(FILE *input_file, double *time_array, double *altitude_array) {
    char line[100];
    int i = 0;

    // Read each line of input file
    while (fgets(line, 100, input_file)!= NULL) {
        // Convert string to double
        sscanf(line, "%lf %lf", &time_array[i], &altitude_array[i]);
        i++;
    }
}

// Function to calculate distance traveled by drone
void calculate_distance(double *time_array, double *altitude_array, double *distance_array) {
    int i;

    // Calculate distance for each data point
    for (i = 0; i < 100; i++) {
        // Calculate horizontal distance using Pythagorean theorem
        double distance = sqrt(pow(time_array[i] * 100.0, 2.0) + pow(altitude_array[i] * 100.0, 2.0));
        distance_array[i] = distance;
    }
}

// Function to write output data to file
void output_results(FILE *output_file, double *time_array, double *altitude_array, double *distance_array) {
    int i;

    // Write each data point to output file
    for (i = 0; i < 100; i++) {
        fprintf(output_file, "%.2f %.2f %.2f\n", time_array[i], altitude_array[i], distance_array[i]);
    }
}