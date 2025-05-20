//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NUM 100
#define MIN_NUM (-MAX_NUM)

typedef struct Complex {
    double real;
    double imag;
} Complex;

Complex addComplex(Complex num1, Complex num2) {
    Complex result;

    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;

    return result;
}

Complex subComplex(Complex num1, Complex num2) {
    Complex result;

    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;

    return result;
}

Complex mulComplex(Complex num1, Complex num2) {
    Complex result;

    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);

    return result;
}

void printComplex(Complex num) {
    if (num.imag >= 0) {
        printf("%.2f + %.2fi", num.real, num.imag);
    } else {
        printf("%.2f - %.2fi", num.real, -num.imag);
    }
}

void inputComplex(Complex *num) {
    char str[50];

    printf("Enter complex number in the format: 'real part complex part'\n");
    scanf("%s", str);

    sscanf(str, "%lf%s%lfi", &(num->real), &str, &(num->imag));
}

int main() {
    Complex num1, num2, sum, diff, prod;

    printf("Enter first complex number: ");
    inputComplex(&num1);

    printf("Enter second complex number: ");
    inputComplex(&num2);

    sum = addComplex(num1, num2);
    printf("\nSum: ");
    printComplex(sum);

    diff = subComplex(num1, num2);
    printf("\nDifference: ");
    printComplex(diff);

    prod = mulComplex(num1, num2);
    printf("\nProduct: ");
    printComplex(prod);

    return 0;
}