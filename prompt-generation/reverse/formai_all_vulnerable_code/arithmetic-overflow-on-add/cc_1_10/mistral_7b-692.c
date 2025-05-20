//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers with a cheerful message
int happy_sum(int a, int b) {
    int sum = a + b;
    printf("\n%d and %d came together, and POOF! They created a beautiful sum of %d!\n", a, b, sum);
    return sum;
}

// Function to subtract two numbers with a cheerful message
int happy_difference(int a, int b) {
    int diff = a - b;
    printf("\n%d gave %d a big hug and said goodbye, leaving %d behind!\n", a, b, diff);
    return diff;
}

// Function to multiply two numbers with a cheerful message
int happy_product(int a, int b) {
    int product = a * b;
    printf("\n%d and %d held hands and danced around, creating a joyful product of %d!\n", a, b, product);
    return product;
}

// Function to divide two numbers with a cheerful message (handle division by zero error)
int happy_quotient(int a, int b) {
    if (b != 0) {
        int quotient = a / b;
        printf("\n%d generously shared %d portions of happiness with %d, leaving %d portions for themselves!\n", a, a, b, quotient);
        return quotient;
    } else {
        printf("\nOops! %d tried to divide by zero! Let's not do that, it's not a happy thing to do!\n", a);
        exit(1);
    }
}

int main() {
    int a, b, sum, difference, product, quotient;

    printf("\nWelcome to the Happy Arithmetic World!\n");

    printf("\nEnter first number: ");
    scanf("%d", &a);

    printf("\nEnter second number: ");
    scanf("%d", &b);

    sum = happy_sum(a, b);
    printf("\nThe sum of %d and %d is %d!\n", a, b, sum);

    difference = happy_difference(a, b);
    printf("\nThe difference of %d and %d is %d!\n", a, b, difference);

    product = happy_product(a, b);
    printf("\nThe product of %d and %d is %d!\n", a, b, product);

    quotient = happy_quotient(a, b);
    printf("\nThe quotient of %d and %d is %d!\n", a, b, quotient);

    return 0;
}