//Falcon2-11B DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <time.h>

double f1(int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * i;
    }
    return sum;
}

double f2(int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * i * i;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int N = 1000;
    if (argc > 1) {
        N = atoi(argv[1]);
    }

    double f1_avg = 0, f2_avg = 0;
    int f1_count = 0, f2_count = 0;

    for (int i = 0; i < 10; i++) {
        clock_t start, end;
        start = clock();
        for (int j = 0; j < N; j++) {
            f1(N);
        }
        end = clock();
        f1_avg += (double)(end - start) / CLOCKS_PER_SEC;
        f1_count++;

        start = clock();
        for (int j = 0; j < N; j++) {
            f2(N);
        }
        end = clock();
        f2_avg += (double)(end - start) / CLOCKS_PER_SEC;
        f2_count++;
    }

    printf("f1 average: %lf\nf2 average: %lf\n", f1_avg / f1_count, f2_avg / f2_count);

    return 0;
}