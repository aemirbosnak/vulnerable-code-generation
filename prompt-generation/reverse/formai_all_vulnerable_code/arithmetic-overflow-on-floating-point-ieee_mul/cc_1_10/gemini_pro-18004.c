//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    int precision;
} Number;

Number* createNumber(double value, int precision) {
    Number* number = (Number*) malloc(sizeof(Number));
    number->value = value;
    number->precision = precision;
    return number;
}

void freeNumber(Number* number) {
    free(number);
}

Number* addNumbers(Number* a, Number* b) {
    double result = a->value + b->value;
    int precision = (a->precision > b->precision) ? a->precision : b->precision;
    return createNumber(result, precision);
}

Number* subtractNumbers(Number* a, Number* b) {
    double result = a->value - b->value;
    int precision = (a->precision > b->precision) ? a->precision : b->precision;
    return createNumber(result, precision);
}

Number* multiplyNumbers(Number* a, Number* b) {
    double result = a->value * b->value;
    int precision = a->precision + b->precision;
    return createNumber(result, precision);
}

Number* divideNumbers(Number* a, Number* b) {
    if (b->value == 0) {
        printf("Error: division by zero\n");
        return NULL;
    }
    double result = a->value / b->value;
    int precision = a->precision + b->precision;
    return createNumber(result, precision);
}

Number* powerNumber(Number* a, double exponent) {
    double result = pow(a->value, exponent);
    int precision = (int) (a->precision * exponent);
    return createNumber(result, precision);
}

Number* squareRootNumber(Number* a) {
    double result = sqrt(a->value);
    int precision = a->precision / 2;
    return createNumber(result, precision);
}

void printNumber(Number* number) {
    printf("%.f\n", number->value);
}

int main() {
    // Create some numbers
    Number* a = createNumber(123.456, 3);
    Number* b = createNumber(789.012, 3);

    // Perform some operations
    Number* c = addNumbers(a, b);
    Number* d = subtractNumbers(a, b);
    Number* e = multiplyNumbers(a, b);
    Number* f = divideNumbers(a, b);
    Number* g = powerNumber(a, 2);
    Number* h = squareRootNumber(a);

    // Print the results
    printNumber(c);
    printNumber(d);
    printNumber(e);
    printNumber(f);
    printNumber(g);
    printNumber(h);

    // Free the numbers
    freeNumber(a);
    freeNumber(b);
    freeNumber(c);
    freeNumber(d);
    freeNumber(e);
    freeNumber(f);
    freeNumber(g);
    freeNumber(h);

    return 0;
}