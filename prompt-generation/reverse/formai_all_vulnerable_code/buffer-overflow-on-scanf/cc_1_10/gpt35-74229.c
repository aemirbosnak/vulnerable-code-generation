//FormAI DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>

int main() {
    // Declare variables
    int a = 10, b = 20, c = 30;
    float x = 3.14159, y = 2.71828;
    char ch = 'A';
    char str1[20] = "Hello";
    char str2[20] = "world!";

    // Print variables
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("x = %f\n", x);
    printf("y = %f\n", y);
    printf("ch = %c\n", ch);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    // Arithmetic operations
    int sum = a + b;
    int diff = b - c;
    float product = x * y;
    float quotient = x / y;
    int modulus = c % b;

    // Print arithmetic results
    printf("sum = %d\n", sum);
    printf("diff = %d\n", diff);
    printf("product = %f\n", product);
    printf("quotient = %f\n", quotient);
    printf("modulus = %d\n", modulus);

    // String concatenation
    strcat(str1, str2);
    printf("str1 + str2 = %s\n", str1);

    // Conditional statements
    if (a > b) {
        printf("a is greater than b\n");
    } else {
        printf("a is less than or equal to b\n");
    }

    if (ch >= 'A' && ch <= 'Z') {
        printf("ch is an uppercase letter\n");
    } else if (ch >= 'a' && ch <= 'z') {
        printf("ch is a lowercase letter\n");
    } else {
        printf("ch is not a letter\n");
    }

    // Looping statements
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    int j = 0;
    while (j < 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    do {
        printf("Enter a positive integer: ");
        scanf("%d", &a);
    } while (a <= 0);

    printf("You entered %d\n", a);

    return 0;
}