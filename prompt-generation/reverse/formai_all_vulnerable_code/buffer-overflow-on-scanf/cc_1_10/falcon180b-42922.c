//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_TERMS 1000

int main() {
    int num_terms;
    int num;
    double sum = 0.0;
    double term;
    double pi_estimate = 0.0;
    int i;
    int j;
    double step = 2.0 / MAX_NUM;
    double x;
    double y;
    double dx;
    double dy;
    double integ;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Enter number of terms: ");
    scanf("%d", &num_terms);

    for (i = 0; i < num_terms; i++) {
        sum += 1.0 / (2.0 * i + 1.0);
    }

    pi_estimate = 2.0 * sum;

    printf("pi_estimate = %lf\n", pi_estimate);

    start_time = clock();

    for (i = 0; i < MAX_NUM; i++) {
        dx = step * i;
        x = -1.0 - dx;
        integ = 0.0;
        for (j = 0; j < MAX_TERMS; j++) {
            term = 1.0 / (2.0 * j + 1.0);
            integ += term * pow(1.0 + x, 2.0 * j + 1.0);
        }
        pi_estimate += 4.0 * integ;
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("pi_estimate = %lf\n", pi_estimate);
    printf("CPU time used = %lf seconds\n", cpu_time_used);

    return 0;
}