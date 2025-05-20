//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NUM 1000
#define PI M_PI

typedef struct {
    double real;
    double imag;
} complex;

void print_complex(complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi", c.real, fabs(c.imag));
    }
}

complex add_complex(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

complex sub_complex(complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

complex mul_complex(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

complex pow_complex(complex base, int exponent) {
    complex result;
    double angle = 2 * PI / (double)exponent;
    complex temp;

    for (int i = 0; i < exponent; i++) {
        temp = mul_complex(base, base);
        result = add_complex(result, temp);
        base = mul_complex(base, add_complex((complex){cos(angle), sin(angle)}, (complex){0.0, 0.0}));
    }

    return result;
}

complex input_complex() {
    complex num;
    char str[MAX_NUM];

    printf("Enter complex number in the format: a+bi or a-bi: ");
    scanf("%s", str);

    sscanf(str, "%lf%c%lf%c", &num.real, &str[0], &num.imag, &str[2]);

    return num;
}

void display_menu() {
    printf("\n\nComplex Calculator Menu:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Power\n");
    printf("5. Input a complex number\n");
    printf("6. Exit\n");
}

int main() {
    complex num1, num2, result;
    int choice, exponent;

    while (true) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                num1 = input_complex();
                num2 = input_complex();
                result = add_complex(num1, num2);
                printf("\nThe sum is: ");
                print_complex(result);
                break;
            case 2:
                num1 = input_complex();
                num2 = input_complex();
                result = sub_complex(num1, num2);
                printf("\nThe difference is: ");
                print_complex(result);
                break;
            case 3:
                num1 = input_complex();
                num2 = input_complex();
                result = mul_complex(num1, num2);
                printf("\nThe product is: ");
                print_complex(result);
                break;
            case 4:
                num1 = input_complex();
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                result = pow_complex(num1, exponent);
                printf("\nThe power is: ");
                print_complex(result);
                break;
            case 5:
                num1 = input_complex();
                printf("\nThe number you entered is: ");
                print_complex(num1);
                break;
            case 6:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }

    return 0;
}