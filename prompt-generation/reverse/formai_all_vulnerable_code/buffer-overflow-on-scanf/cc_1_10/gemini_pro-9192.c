//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 1024

struct data_point {
    double x;
    double y;
};

struct regression_line {
    double slope;
    double intercept;
    double r_squared;
};

struct regression_line fit_regression_line(struct data_point *data, int num_data_points) {
    double sum_x = 0, sum_y = 0, sum_x_squared = 0, sum_y_squared = 0, sum_xy = 0;

    for (int i = 0; i < num_data_points; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
        sum_x_squared += data[i].x * data[i].x;
        sum_y_squared += data[i].y * data[i].y;
        sum_xy += data[i].x * data[i].y;
    }

    double slope = (num_data_points * sum_xy - sum_x * sum_y) / (num_data_points * sum_x_squared - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / num_data_points;
    double r_squared = (num_data_points * sum_xy - sum_x * sum_y) * (num_data_points * sum_xy - sum_x * sum_y) / ((num_data_points * sum_x_squared - sum_x * sum_x) * (num_data_points * sum_y_squared - sum_y * sum_y));

    struct regression_line regression_line = {slope, intercept, r_squared};
    return regression_line;
}

int main() {
    int num_data_points;
    printf("Enter the number of data points: ");
    scanf("%d", &num_data_points);

    struct data_point *data = malloc(num_data_points * sizeof(struct data_point));

    for (int i = 0; i < num_data_points; i++) {
        printf("Enter the x-coordinate for data point %d: ", i + 1);
        scanf("%lf", &data[i].x);
        printf("Enter the y-coordinate for data point %d: ", i + 1);
        scanf("%lf", &data[i].y);
    }

    struct regression_line regression_line = fit_regression_line(data, num_data_points);

    printf("The equation of the regression line is y = %.3lfx + %.3lf\n", regression_line.slope, regression_line.intercept);
    printf("The coefficient of determination (R^2) is %.3lf\n", regression_line.r_squared);

    free(data);
    return 0;
}