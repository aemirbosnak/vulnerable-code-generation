//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct {
    double value;
    int index;
} Element;

Element Circuit[MAX];
int n, m;

void input();
void simulation();
void output();

int main() {
    input();
    simulation();
    output();
    return 0;
}

void input() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the number of variables: ");
    scanf("%d", &m);

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d:\n", i+1);
        printf("Enter the value: ");
        scanf("%lf", &Circuit[i].value);
        printf("Enter the index: ");
        scanf("%d", &Circuit[i].index);
    }
}

void simulation() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double sum = 0;
            for (int k = 0; k < n; k++) {
                if (Circuit[k].index == j) {
                    sum += Circuit[k].value * Circuit[i].value;
                }
            }
            Circuit[i].value += sum;
        }
    }
}

void output() {
    for (int i = 0; i < n; i++) {
        printf("Element %d: %lf\n", i+1, Circuit[i].value);
    }
}