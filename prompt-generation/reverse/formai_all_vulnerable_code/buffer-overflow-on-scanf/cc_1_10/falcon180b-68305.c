//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    int index;
} Complex;

Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.value = a.value + b.value;
    result.index = a.index;
    return result;
}

Complex multiplyComplex(Complex a, Complex b) {
    Complex result;
    result.value = a.value * b.value - a.index * b.index;
    result.index = a.index + b.index;
    return result;
}

Complex conjugateComplex(Complex a) {
    Complex result;
    result.value = a.value;
    result.index = -a.index;
    return result;
}

Complex absComplex(Complex a) {
    Complex result;
    result.value = sqrt(a.value * a.value + a.index * a.index);
    result.index = 0;
    return result;
}

int main() {
    Complex a, b, c, d;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf %d", &a.value, &a.index);
        b = addComplex(b, a);
    }
    printf("Sum of elements: ");
    for (int i = 0; i < n; i++) {
        printf("%lf %d ", b.value, b.index);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        c = multiplyComplex(a, b);
        printf("Product of elements: ");
        for (int j = 0; j < n; j++) {
            printf("%lf %d ", c.value, c.index);
        }
        printf("\n");
    }
    printf("Conjugate of elements: ");
    for (int i = 0; i < n; i++) {
        c = conjugateComplex(a);
        printf("%lf %d ", c.value, c.index);
    }
    printf("\n");
    printf("Absolute value of elements: ");
    for (int i = 0; i < n; i++) {
        c = absComplex(a);
        printf("%lf ", c.value);
    }
    printf("\n");
    return 0;
}