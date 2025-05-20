//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

int n;
int m;
int a[MAX][MAX];
int sum[MAX];
int i, j, k;

void init() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            sum[i] += a[i][j];
        }
    }
}

void print() {
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int low, int high) {
    int i, j, tmp;
    for (i = low; i < high; i++) {
        for (j = i + 1; j <= high; j++) {
            if (sum[i] > sum[j]) {
                swap(&sum[i], &sum[j]);
                for (k = 0; k < m; k++) {
                    swap(&a[i][k], &a[j][k]);
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    sort(0, n - 1);
    print();
    return 0;
}