//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VARIABLES 10
#define MAX_TERMS 100

typedef struct {
    char name[20];
    double coeff;
    int degree;
} term;

typedef struct {
    int num_terms;
    term terms[MAX_TERMS];
} equation;

void add_term(equation* eq, char* var_name, double coeff, int degree) {
    term* new_term = (term*) malloc(sizeof(term));
    strcpy(new_term->name, var_name);
    new_term->coeff = coeff;
    new_term->degree = degree;
    eq->terms[eq->num_terms++] = *new_term;
}

void print_equation(equation* eq) {
    printf("Equation: ");
    for (int i = 0; i < eq->num_terms; i++) {
        printf("%s ", eq->terms[i].name);
        if (eq->terms[i].coeff!= 1) {
            printf("%+.2f", eq->terms[i].coeff);
        }
        if (eq->terms[i].degree!= 1) {
            printf("^%d", eq->terms[i].degree);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    equation eq;
    int num_vars;
    char* var_names[MAX_VARIABLES];
    double var_values[MAX_VARIABLES];

    printf("Enter number of variables: ");
    scanf("%d", &num_vars);

    for (int i = 0; i < num_vars; i++) {
        printf("Enter variable name %d: ", i+1);
        scanf("%s", var_names[i]);
    }

    printf("Enter variable values:\n");
    for (int i = 0; i < num_vars; i++) {
        scanf("%lf", &var_values[i]);
    }

    printf("Enter equation terms:\n");
    char var_name[20];
    double coeff;
    int degree;
    while (scanf("%s %lf %d", var_name, &coeff, &degree) == 3) {
        add_term(&eq, var_name, coeff, degree);
    }

    double x;
    printf("Enter value of x: ");
    scanf("%lf", &x);

    double y = 0;
    for (int i = 0; i < eq.num_terms; i++) {
        double var_value = var_values[i];
        for (int j = 0; j < eq.terms[i].degree; j++) {
            y += eq.terms[i].coeff * pow(var_value, j) * pow(x, j);
        }
    }

    printf("y = %.2f\n", y);

    return 0;
}