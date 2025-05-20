//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: protected
#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int num;
    double result;
} FactCalc;

void FactCalc_Init(FactCalc* self, int num);
void FactCalc_Calculate(FactCalc* self);
void FactCalc_PrintResult(FactCalc* self);

void FactCalc_Init(FactCalc* self, int num) {
    self->num = num;
    self->result = 1.0;
}

void FactCalc_Calculate(FactCalc* self) {
    if (self->num < 0) {
        printf("Error: Factorial of negative number is not defined.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= self->num; i++) {
        self->result *= i;
    }
}

void FactCalc_PrintResult(FactCalc* self) {
    printf("Factorial of %d is %.0f\n", self->num, self->result);
}

#endif // FACTORIAL_H

int main() {
    FactCalc calc;
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    FactCalc_Init(&calc, num);
    FactCalc_Calculate(&calc);
    FactCalc_PrintResult(&calc);

    return 0;
}