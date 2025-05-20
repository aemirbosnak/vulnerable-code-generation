//Falcon-180B DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA 1000

struct Data {
    double x;
    double y;
};

struct Data data[MAX_DATA];
int num_data = 0;

void read_data() {
    printf("Enter number of data points: ");
    scanf("%d", &num_data);
    if (num_data > MAX_DATA) {
        printf("Error: Maximum number of data points is %d\n", MAX_DATA);
        exit(1);
    }
    for (int i = 0; i < num_data; i++) {
        printf("Enter x and y values for data point %d: ", i+1);
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }
}

void calculate_mean() {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < num_data; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
    }
    double mean_x = sum_x / num_data;
    double mean_y = sum_y / num_data;
    printf("Mean x and y values: %lf %lf\n", mean_x, mean_y);
}

void calculate_correlation() {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_y2 = 0;
    for (int i = 0; i < num_data; i++) {
        sum_x += data[i].x;
        sum_y += data[i].y;
        sum_xy += data[i].x * data[i].y;
        sum_x2 += pow(data[i].x, 2);
        sum_y2 += pow(data[i].y, 2);
    }
    double mean_x = sum_x / num_data;
    double mean_y = sum_y / num_data;
    double slope = (num_data * sum_xy - sum_x * sum_y) / (num_data * sum_x2 - sum_x * sum_x);
    double intercept = mean_y - slope * mean_x;
    double correlation = slope / sqrt(pow(slope, 2) + pow(intercept, 2));
    printf("Correlation coefficient: %lf\n", correlation);
}

void main() {
    read_data();
    calculate_mean();
    calculate_correlation();
}