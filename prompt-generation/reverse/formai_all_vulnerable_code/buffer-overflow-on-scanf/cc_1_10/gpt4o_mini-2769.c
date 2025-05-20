//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
    int degree;
    double *coefficients;
} Polynomial;

Polynomial* create_polynomial(int degree) {
    Polynomial *poly = (Polynomial *)malloc(sizeof(Polynomial));
    poly->degree = degree;
    poly->coefficients = (double *)malloc((degree + 1) * sizeof(double));
    for (int i = 0; i <= degree; i++) {
        poly->coefficients[i] = 0.0; // Initialize coefficients to zero
    }
    return poly;
}

void set_coefficient(Polynomial *poly, int degree, double value) {
    if (degree > poly->degree) {
        printf("Degree exceeds polynomial degree.\n");
        return;
    }
    poly->coefficients[degree] = value;
}

double evaluate_polynomial(Polynomial *poly, double x) {
    double result = 0.0;
    for (int i = 0; i <= poly->degree; i++) {
        result += poly->coefficients[i] * pow(x, i);
    }
    return result;
}

Polynomial* add_polynomials(Polynomial *p1, Polynomial *p2) {
    int maxDegree = p1->degree > p2->degree ? p1->degree : p2->degree;
    Polynomial *result = create_polynomial(maxDegree);
    
    for (int i = 0; i <= maxDegree; i++) {
        double coeff1 = (i <= p1->degree) ? p1->coefficients[i] : 0.0;
        double coeff2 = (i <= p2->degree) ? p2->coefficients[i] : 0.0;
        result->coefficients[i] = coeff1 + coeff2;
    }
    return result;
}

Polynomial* multiply_polynomials(Polynomial *p1, Polynomial *p2) {
    int resultDegree = p1->degree + p2->degree;
    Polynomial *result = create_polynomial(resultDegree);
    
    for (int i = 0; i <= p1->degree; i++) {
        for (int j = 0; j <= p2->degree; j++) {
            result->coefficients[i + j] += p1->coefficients[i] * p2->coefficients[j];
        }
    }
    return result;
}

void print_polynomial(Polynomial *poly) {
    for (int i = poly->degree; i >= 0; i--) {
        if (i < poly->degree) {
            printf(" + ");
        }
        printf("%.2fx^%d", poly->coefficients[i], i);
    }
    printf("\n");
}

void free_polynomial(Polynomial *poly) {
    free(poly->coefficients);
    free(poly);
}

int main() {
    int degree1, degree2;
    
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    Polynomial *poly1 = create_polynomial(degree1);

    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = 0; i <= degree1; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &poly1->coefficients[i]);
    }
    
    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    Polynomial *poly2 = create_polynomial(degree2);

    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = 0; i <= degree2; i++) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &poly2->coefficients[i]);
    }
    
    printf("\nFirst Polynomial: ");
    print_polynomial(poly1);
    
    printf("Second Polynomial: ");
    print_polynomial(poly2);
    
    Polynomial *sum = add_polynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    print_polynomial(sum);
    
    Polynomial *product = multiply_polynomials(poly1, poly2);
    printf("Product of Polynomials: ");
    print_polynomial(product);
    
    double x;
    printf("Enter a value for x to evaluate the first polynomial: ");
    scanf("%lf", &x);
    printf("P1(%.2f) = %.2f\n", x, evaluate_polynomial(poly1, x));

    printf("Enter a value for x to evaluate the second polynomial: ");
    scanf("%lf", &x);
    printf("P2(%.2f) = %.2f\n", x, evaluate_polynomial(poly2, x));
    
    free_polynomial(poly1);
    free_polynomial(poly2);
    free_polynomial(sum);
    free_polynomial(product);
    
    return 0;
}