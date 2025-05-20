//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define N 100000
#define M 100

struct bench_data {
    int n;
    int m;
    int op;
    double time;
};

void init_data(struct bench_data *data, int n, int m, int op) {
    for (int i = 0; i < N; i++) {
        data[i].n = n;
        data[i].m = m;
        data[i].op = op;
    }
}

void bench_run(struct bench_data *data) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            switch (data[j].op) {
                case 1:
                    data[j].time = 1.0 * (rand() % 100) / 100;
                    break;
                case 2:
                    data[j].time = 2.0 * (rand() % 100) / 100;
                    break;
                case 3:
                    data[j].time = 3.0 * (rand() % 100) / 100;
                    break;
                default:
                    data[j].time = 0.0;
                    break;
            }
        }
    }
}

void print_result(struct bench_data *data) {
    for (int i = 0; i < N; i++) {
        printf("%d %d %f\n", data[i].n, data[i].m, data[i].time);
    }
}

int main() {
    int n, m, op;
    struct bench_data data[N];

    srand(time(NULL));

    printf("Welcome to the C benchmarking program!\n");

    do {
        printf("Enter the number of loops (1-100): ");
        scanf("%d", &n);
        printf("Enter the number of operations per loop (1-100): ");
        scanf("%d", &m);
        printf("Enter the operation type (1-3): ");
        scanf("%d", &op);

        init_data(data, n, m, op);
        bench_run(data);
        print_result(data);
    } while (1);

    return 0;
}