//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 2

typedef struct {
    double x;
    double y;
} DataPoint;

double calculate_correlation_coefficient(DataPoint data[], int num_data_points) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_xx = 0.0;

    for (int i = 0; i < num_data_points; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
        sum_xy += data[i].x * data[i].y;
        sum_xx += pow(data[i].x, 2);
    }

    double numerator = (num_data_points * sum_xy) - (sum_x * sum_y);
    double denominator = sqrt((pow(num_data_points, 2) * sum_xx) - pow(sum_x, 2) - pow(sum_y, 2) + pow(sum_x, 2));

    return numerator / denominator;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    DataPoint data[MAX_ROWS];
    int num_data_points = 0;

    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%lf,%lf", &data[num_data_points].x, &data[num_data_points].y);
        num_data_points++;
    }

    fclose(file);

    double correlation_coefficient = calculate_correlation_coefficient(data, num_data_points);
    printf("Correlation coefficient: %f\n", correlation_coefficient);

    return 0;
}