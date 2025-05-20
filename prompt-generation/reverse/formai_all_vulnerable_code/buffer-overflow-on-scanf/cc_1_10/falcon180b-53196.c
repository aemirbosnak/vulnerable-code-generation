//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM_DATA 1000000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double a;
    double b;
    double c;
} LinearEquation;

void read_data(Point* data, int num_data) {
    for (int i = 0; i < num_data; i++) {
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }
}

void calculate_linear_equation(LinearEquation* equation, Point* data, int num_data) {
    double sum_x = 0;
    double sum_y = 0;
    double sum_xy = 0;

    for (int i = 0; i < num_data; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
        sum_xy += data[i].x * data[i].y;
    }

    equation->a = (num_data * sum_xy - sum_x * sum_y) / (num_data * sum_x - sum_x * sum_x);
    equation->b = (sum_y - equation->a * sum_x) / num_data;
}

void print_linear_equation(LinearEquation* equation) {
    printf("y = %.2lfx + %.2lf\n", equation->a, equation->b);
}

void main() {
    Point data[MAX_NUM_DATA];
    LinearEquation equation;

    int num_data;
    printf("Enter the number of data points: ");
    scanf("%d", &num_data);

    if (num_data > MAX_NUM_DATA) {
        printf("Error: Number of data points exceeds maximum limit.\n");
        exit(1);
    }

    read_data(data, num_data);
    calculate_linear_equation(&equation, data, num_data);
    print_linear_equation(&equation);
}