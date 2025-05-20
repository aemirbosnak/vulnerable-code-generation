//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int line;
    double a, b, c, x, y;
} equation;

void read_equations(FILE *fp, equation *equations, int n) {
    int i;
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d %lf %lf %lf %lf", &equations[i].line, &equations[i].a, &equations[i].b, &equations[i].c, &equations[i].x);
    }
}

void print_equations(equation *equations, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: ax^2 + bx + c = 0\n", equations[i].line);
        printf("x = %.3lf\n\n", equations[i].x);
    }
}

int main() {
    FILE *fp;
    int n, i;
    equation *equations;

    fp = fopen("equations.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);
    equations = (equation *) malloc(n * sizeof(equation));

    read_equations(fp, equations, n);
    fclose(fp);

    print_equations(equations, n);

    for (i = 0; i < n; i++) {
        equations[i].y = -(equations[i].a * sqrt(equations[i].x * equations[i].x + equations[i].b * equations[i].x / equations[i].a + equations[i].c / equations[i].a));
    }

    print_equations(equations, n);

    free(equations);

    return 0;
}