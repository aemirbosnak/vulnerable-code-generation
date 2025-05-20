//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define PI 3.14159265358979323846

double x[N], y[N];

void init(int seed) {
    srand(seed);
    for (int i = 0; i < N; i++) {
        x[i] = (double) rand() / RAND_MAX * 2 - 1;
        y[i] = (double) rand() / RAND_MAX * 2 - 1;
    }
}

void mandelbrot(double cx, double cy, int max_iter, double threshold, int *iterations, double *escape_time) {
    double zx = 0, zy = 0, temp;
    int iter = 0;
    
    while (iter < max_iter && (zx * zx + zy * zy) < threshold) {
        temp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = temp;
        iter++;
    }
    
    *iterations = iter;
    *escape_time = iter * log(log(threshold)) / log(2);
}

void compute_mandelbrot(int seed, int max_iter, double threshold) {
    int iterations[N];
    double escape_time[N];
    
    init(seed);
    
    for (int i = 0; i < N; i++) {
        mandelbrot(x[i], y[i], max_iter, threshold, &iterations[i], &escape_time[i]);
    }
    
    double min_escape_time = escape_time[0];
    for (int i = 1; i < N; i++) {
        if (escape_time[i] < min_escape_time) {
            min_escape_time = escape_time[i];
        }
    }
    
    printf("Minimum escape time: %f\n", min_escape_time);
}

int main() {
    int seed;
    printf("Enter seed: ");
    scanf("%d", &seed);
    
    int max_iter;
    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);
    
    double threshold;
    printf("Enter threshold: ");
    scanf("%lf", &threshold);
    
    compute_mandelbrot(seed, max_iter, threshold);
    
    return 0;
}