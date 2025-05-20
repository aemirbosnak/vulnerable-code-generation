//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define NUM_COLUMNS 5

typedef struct {
    char name[50];
    float value;
} DataPoint;

void read_csv(FILE *input_file, DataPoint *data_points, int *num_data_points) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int column = 0;

    *num_data_points = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        sscanf(line, "%s %f", data_points[*num_data_points].name, &data_points[*num_data_points].value);
        (*num_data_points)++;
    }
}

void write_csv(FILE *output_file, DataPoint data_points[], int num_data_points) {
    int i;

    for (i = 0; i < num_data_points; i++) {
        fprintf(output_file, "%s,%f\n", data_points[i].name, data_points[i].value);
    }
}

int main() {
    FILE *input_file = fopen("input.csv", "r");
    FILE *output_file = fopen("output.csv", "w");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening files.\n");
        return 1;
    }

    DataPoint data_points[NUM_COLUMNS];
    int num_data_points = 0;

    read_csv(input_file, data_points, &num_data_points);

    float sum = 0.0;
    float avg = 0.0;
    float min = data_points[0].value;
    float max = data_points[0].value;

    for (int i = 0; i < num_data_points; i++) {
        sum += data_points[i].value;
        if (data_points[i].value < min) {
            min = data_points[i].value;
        }
        if (data_points[i].value > max) {
            max = data_points[i].value;
        }
    }

    avg = sum / num_data_points;

    write_csv(output_file, data_points, num_data_points);

    printf("Min: %f\n", min);
    printf("Max: %f\n", max);
    printf("Average: %f\n", avg);

    fclose(input_file);
    fclose(output_file);

    return 0;
}