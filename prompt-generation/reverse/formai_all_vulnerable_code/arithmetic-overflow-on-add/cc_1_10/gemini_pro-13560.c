//GEMINI-pro DATASET v1.0 Category: System administration ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA_POINTS 10000
#define MAX_VARIABLES 100

struct data_point {
    double variables[MAX_VARIABLES];
};

struct data_set {
    struct data_point data_points[MAX_DATA_POINTS];
    int num_data_points;
    int num_variables;
};

void read_data_set(struct data_set *data_set, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int line_number = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        char *token = strtok(line, ",");
        int variable_index = 0;
        while (token != NULL) {
            data_set->data_points[line_number - 1].variables[variable_index++] = atof(token);
            token = strtok(NULL, ",");
        }

        data_set->num_data_points++;
    }

    fclose(file);
}

void print_data_set(struct data_set *data_set) {
    for (int i = 0; i < data_set->num_data_points; i++) {
        for (int j = 0; j < data_set->num_variables; j++) {
            printf("%f,", data_set->data_points[i].variables[j]);
        }
        printf("\n");
    }
}

double mean(struct data_set *data_set, int variable_index) {
    double sum = 0;
    for (int i = 0; i < data_set->num_data_points; i++) {
        sum += data_set->data_points[i].variables[variable_index];
    }
    return sum / data_set->num_data_points;
}

double standard_deviation(struct data_set *data_set, int variable_index) {
    double mean_value = mean(data_set, variable_index);
    double sum_of_squared_differences = 0;
    for (int i = 0; i < data_set->num_data_points; i++) {
        sum_of_squared_differences += pow(data_set->data_points[i].variables[variable_index] - mean_value, 2);
    }
    return sqrt(sum_of_squared_differences / (data_set->num_data_points - 1));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct data_set data_set;
    read_data_set(&data_set, argv[1]);
    
    // Calculate the mean and standard deviation for each variable.
    
    for (int i = 0; i < data_set.num_variables; i++) {
        printf("Variable %d:\n", i + 1);
        printf("Mean: %f\n", mean(&data_set, i));
        printf("Standard deviation: %f\n", standard_deviation(&data_set, i));
        printf("\n");
    }

    return EXIT_SUCCESS;
}