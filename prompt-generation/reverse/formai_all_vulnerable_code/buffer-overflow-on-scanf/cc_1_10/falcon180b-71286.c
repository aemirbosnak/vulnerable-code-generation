//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000
#define PI 3.1415926535897932385
#define EPS 1.0e-9

int n;
double v[MAX],t[MAX],y[MAX];
double *x,*c,*b;

void init_circuit(double* x, double* c, double* b) {
  for (int i = 0; i < n; i++) {
    x[i] = 0.0;
    c[i] = 0.0;
    b[i] = 0.0;
  }
}

void solve_circuit(double* x, double* c, double* b, double* y) {
  for (int i = 0; i < n; i++) {
    y[i] = (c[i] * x[i] + b[i]) / (1.0 + exp((x[i] - v[i]) / t[i]));
  }
}

void main() {
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the voltage values: ");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &v[i]);
  }

  printf("Enter the time constants: ");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &t[i]);
  }

  double *x = (double*) malloc(n * sizeof(double));
  double *c = (double*) malloc(n * sizeof(double));
  double *b = (double*) malloc(n * sizeof(double));

  init_circuit(x, c, b);

  double *y = (double*) malloc(n * sizeof(double));

  solve_circuit(x, c, b, y);

  printf("The solution is: ");
  for (int i = 0; i < n; i++) {
    printf("%lf ", y[i]);
  }
}