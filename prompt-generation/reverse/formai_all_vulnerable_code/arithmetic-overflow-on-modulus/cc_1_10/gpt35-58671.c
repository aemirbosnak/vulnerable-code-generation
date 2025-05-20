//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>

int main() {
    int num1, num2, sum, diff, prod, quo, rem;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    rem = num1 % num2;

    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);
    printf("The quotient when %d is divided by %d is %d\n", num1, num2, quo);
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, rem);

    if (num1 > num2) {
        printf("%d is greater than %d\n", num1, num2);
    } else if (num1 < num2) {
        printf("%d is less than %d\n", num1, num2);
    } else {
        printf("Both the numbers are equal\n");
    }

    if (num1 % 2 == 0) {
        printf("%d is even\n", num1);
    } else {
        printf("%d is odd\n", num1);
    }

    if (num2 % 2 == 0) {
        printf("%d is even\n", num2);
    } else {
        printf("%d is odd\n", num2);
    }

    if (num1 > 0) {
        printf("%d is a positive number\n", num1);
    } else if (num1 < 0) {
        printf("%d is a negative number\n", num1);
    } else {
        printf("%d is neither positive nor negative\n", num1);
    }

    if (num2 > 0) {
        printf("%d is a positive number\n", num2);
    } else if (num2 < 0) {
        printf("%d is a negative number\n", num2);
    } else {
        printf("%d is neither positive nor negative\n", num2);
    }

    return 0;
}