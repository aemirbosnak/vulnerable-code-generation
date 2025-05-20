//FormAI DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    int average = sum / 3;

    printf("\nSum of the three numbers is: %d\n", sum);
    printf("Average of the three numbers is: %d\n", average);

    if (num1 > num2 && num1 > num3) {
        printf("\n%d is the largest number.\n", num1);
    }
    else if (num2 > num1 && num2 > num3) {
        printf("\n%d is the largest number.\n", num2);
    }
    else {
        printf("\n%d is the largest number.\n", num3);
    }

    int product = num1 * num2 * num3;

    printf("Product of the three numbers is: %d\n", product);

    int remainder1 = num1 % num2;
    int remainder2 = num2 % num3;
    int remainder3 = num3 % num1;

    printf("Remainder when %d is divided by %d is: %d\n", num1, num2, remainder1);
    printf("Remainder when %d is divided by %d is: %d\n", num2, num3, remainder2);
    printf("Remainder when %d is divided by %d is: %d\n", num3, num1, remainder3);

    int quotient1 = num1 / num2;
    int quotient2 = num2 / num3;
    int quotient3 = num3 / num1;

    printf("Quotient when %d is divided by %d is: %d\n", num1, num2, quotient1);
    printf("Quotient when %d is divided by %d is: %d\n", num2, num3, quotient2);
    printf("Quotient when %d is divided by %d is: %d\n", num3, num1, quotient3);

    int absolute1 = abs(num1);
    int absolute2 = abs(num2);
    int absolute3 = abs(num3);

    printf("Absolute value of %d is: %d\n", num1, absolute1);
    printf("Absolute value of %d is: %d\n", num2, absolute2);
    printf("Absolute value of %d is: %d\n", num3, absolute3);

    int max1 = (num1 > num2) ? num1 : num2;
    int max2 = (num2 > num3) ? num2 : num3;
    int maximum = (max1 > max2) ? max1 : max2;

    printf("The maximum number is: %d\n", maximum);

    int min1 = (num1 < num2) ? num1 : num2;
    int min2 = (num2 < num3) ? num2 : num3;
    int minimum = (min1 < min2) ? min1 : min2;

    printf("The minimum number is: %d\n", minimum);

    int result = ((num1 + num2 + num3) % 2 == 0) ? 1 : 0;

    if (result == 1) {
        printf("The sum of the three numbers is even.\n");
    }
    else {
        printf("The sum of the three numbers is odd.\n");
    }

    return 0;
}