//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_TEMP 1000
#define MIN_TEMP -273.15
#define MAX_ITER 10000
#define EPSILON 0.0001

double rand_double(double min, double max) {
    return rand() / (double) RAND_MAX * (max - min) + min;
}

double rand_gaussian(double mean, double sigma) {
    double u1, u2, r;
    do {
        u1 = rand_double(0.0, 1.0);
        u2 = rand_double(0.0, 1.0);
        r = u1 * sqrt(-2.0 * log(u2)) * cos(2.0 * PI * u1);
    } while (r >= 1.0);
    return mean + sigma * r;
}

int main() {
    int n, i, j;
    double temp[MAX_ITER];
    double mean, std_dev, min_temp, max_temp;
    srand(time(NULL));
    printf("Enter the number of temperatures to generate: ");
    scanf("%d", &n);
    printf("Enter the mean temperature: ");
    scanf("%lf", &mean);
    printf("Enter the standard deviation of the temperature: ");
    scanf("%lf", &std_dev);
    if (std_dev == 0.0) {
        std_dev = 1.0;
    }
    min_temp = mean - 3.0 * std_dev;
    max_temp = mean + 3.0 * std_dev;
    if (min_temp < MIN_TEMP) {
        min_temp = MIN_TEMP;
    }
    if (max_temp > MAX_TEMP) {
        max_temp = MAX_TEMP;
    }
    for (i = 0; i < n; i++) {
        temp[i] = rand_gaussian(mean, std_dev);
        while (temp[i] < min_temp || temp[i] > max_temp) {
            temp[i] = rand_gaussian(mean, std_dev);
        }
    }
    printf("The temperatures generated are:\n");
    for (i = 0; i < n; i++) {
        printf("%f\n", temp[i]);
    }
    return 0;
}