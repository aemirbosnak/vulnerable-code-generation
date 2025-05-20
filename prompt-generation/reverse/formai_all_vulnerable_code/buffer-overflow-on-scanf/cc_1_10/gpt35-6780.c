//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>

int main() {
    int num1, num2, sum;
    printf("Enter two integers: \n");
    scanf("%d %d", &num1, &num2);

    // Check if both numbers are positive
    if(num1 > 0 && num2 > 0) {
        // Addition
        sum = num1 + num2;
        printf("%d + %d = %d\n", num1, num2, sum);

        // Subtraction
        if(num1 > num2) {
            int difference = num1 - num2;
            printf("%d - %d = %d\n", num1, num2, difference);
        } else {
            int difference = num2 - num1;
            printf("%d - %d = %d\n", num2, num1, difference);
        }

        // Multiplication
        int product = num1 * num2;
        printf("%d * %d = %d\n", num1, num2, product);

        // Division
        if(num1 > num2) {
            if(num2 != 0) {
                float quotient = num1 / (float)num2;
                printf("%d / %d = %.2f\n", num1, num2, quotient);
            } else {
                printf("Division by zero not possible\n");
            }
        } else {
            if(num1 != 0) {
                float quotient = num2 / (float)num1;
                printf("%d / %d = %.2f\n", num2, num1, quotient);
            } else {
                printf("Division by zero not possible\n");
            }
        }

        // Modulus
        int modulus = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, modulus);

        // Increment and Decrement
        num1++;
        num2--;
        printf("num1++ = %d\n", num1);
        printf("num2-- = %d\n", num2);

    } else {
        printf("Please enter positive integers only\n");
    }

    return 0;
}