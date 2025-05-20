//LLAMA2-13B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10
#define M 5
#define K 3

typedef struct {
    int x[N];
    int y[M];
    int z[K];
} point3d_t;

point3d_t points[10];
int num_points = 0;

void read_points(void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("x[%d][%d] = ", i, j);
            scanf("%d", &points[num_points].x[i * M + j]);
        }
        printf("\n");
    }
    for (j = 0; j < K; j++) {
        printf("z[%d] = ", j);
        scanf("%d", &points[num_points].z[j]);
        printf("\n");
    }
    num_points++;
}

void print_points(void) {
    int i, j;
    for (i = 0; i < num_points; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", points[i].x[j]);
        }
        printf("\n");
        for (j = 0; j < K; j++) {
            printf("%d ", points[i].z[j]);
        }
        printf("\n");
    }
}

void calculate_distances(void) {
    int i, j, k;
    for (i = 0; i < num_points; i++) {
        for (j = i + 1; j < num_points; j++) {
            for (k = 0; k < K; k++) {
                points[i].z[k] = points[i].z[k] + points[j].z[k];
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        points[i].x[0] = rand() % 100;
        points[i].y[0] = rand() % 100;
        points[i].z[0] = rand() % 100;
    }
    read_points();
    print_points();
    calculate_distances();
    return 0;
}