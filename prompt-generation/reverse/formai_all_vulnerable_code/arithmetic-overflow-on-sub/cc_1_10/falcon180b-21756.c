//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define MAXN 100
#define Max(a,b) ((a)>(b)?(a):(b))

typedef struct {
    int value;
    int weight;
}item;

typedef struct {
    item a[MAXN];
    int n;
} knapsack;

void create_instance(knapsack *k, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        k->a[i].value = rand() % 101;
        k->a[i].weight = rand() % 101;
    }
    k->n = n;
}

int knapSack(knapsack k, int w, int n) {
    int i, j;
    if (n == 0 || w == 0) {
        return 0;
    }
    if (k.a[n-1].weight <= w) {
        return Max(k.a[n-1].value, knapSack(k, w - k.a[n-1].weight, n-1));
    } else {
        return knapSack(k, w, n-1);
    }
}

int main() {
    knapsack k;
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    create_instance(&k, n);
    printf("Enter the weight limit: ");
    scanf("%d", &k.n);
    k.a[k.n].value = 0;
    for (i = k.n; i >= 1; i--) {
        k.a[i-1].value = knapSack(k, k.n, i);
    }
    printf("The maximum value is: %d\n", k.a[0].value);
    return 0;
}