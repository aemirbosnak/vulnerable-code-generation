//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Alan Turing
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM_POINTS 1000
#define MAX_NUM_FUNCTIONS 100
#define MAX_NUM_TERMS 50

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double a;
    double b;
    double c;
} Equation;

typedef struct {
    Equation *equations;
    int num_equations;
} Function;

void read_points(Point *points, int num_points) {
    printf("Enter %d points (x y):\n", num_points);
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
}

void read_function(Function *function, int num_terms) {
    printf("Enter %d terms of the function (a b c):\n", num_terms);
    for (int i = 0; i < num_terms; i++) {
        scanf("%lf %lf %lf", &function->equations[i].a, &function->equations[i].b, &function->equations[i].c);
    }
    function->num_equations = num_terms;
}

double evaluate_function(Function *function, double x) {
    double result = 0;
    for (int i = 0; i < function->num_equations; i++) {
        result += function->equations[i].a * pow(x, 2) + function->equations[i].b * x + function->equations[i].c;
    }
    return result;
}

double calculate_integral(Function *function, double a, double b) {
    double h = 0.0001;
    double sum = 0;

    for (double x = a; x <= b; x += h) {
        sum += evaluate_function(function, x) * h;
    }

    return sum;
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    Point *points = malloc(sizeof(Point) * num_points);
    read_points(points, num_points);

    int num_functions;
    printf("Enter the number of functions: ");
    scanf("%d", &num_functions);

    Function *functions = malloc(sizeof(Function) * num_functions);
    for (int i = 0; i < num_functions; i++) {
        int num_terms;
        printf("Enter the number of terms for function %d: ", i + 1);
        scanf("%d", &num_terms);
        if (num_terms > MAX_NUM_TERMS) {
            printf("Error: maximum number of terms is %d\n", MAX_NUM_TERMS);
            exit(1);
        }
        functions[i].equations = malloc(sizeof(Equation) * num_terms);
        read_function(&functions[i], num_terms);
    }

    double a, b;
    printf("Enter the limits of integration: ");
    scanf("%lf %lf", &a, &b);

    double result = 0;
    for (int i = 0; i < num_functions; i++) {
        result += calculate_integral(&functions[i], a, b);
    }

    printf("The result is: %lf\n", result);

    return 0;
}