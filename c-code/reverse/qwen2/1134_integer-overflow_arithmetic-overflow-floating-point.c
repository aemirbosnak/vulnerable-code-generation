#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

typedef struct {
    int real;
    int imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

int main() {
    Complex num1 = {2147483647, 2147483647};
    Complex num2 = {1, 1};

    Complex sum = add(num1, num2);
    Complex product = multiply(num1, num2);

    printf("Sum: %d + %di\n", sum.real, sum.imag);
    printf("Product: %d + %di\n", product.real, product.imag);

    return 0;
}
