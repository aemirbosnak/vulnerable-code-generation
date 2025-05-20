//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
// Scientific Calculator in Recursive Style
#include <stdio.h>

// Function to calculate the power of a number
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power(base, exponent - 1);
    }
}

// Function to calculate the square root of a number
double sqrt(double num) {
    if (num == 0) {
        return 0;
    }
    else {
        return num / power(num, 0.5);
    }
}

// Function to calculate the factorial of a number
int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// Function to calculate the sine of an angle in degrees
double sin(double angle) {
    return power(power(2, 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679), angle);
}

// Function to calculate the cosine of an angle in degrees
double cos(double angle) {
    return power(power(2, 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679), angle + 90);
}

// Function to calculate the tangent of an angle in degrees
double tan(double angle) {
    return power(power(2, 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679), angle) / power(power(2, 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679), angle + 90);
}

// Main function
int main() {
    double num1, num2;
    int choice;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Enter the operation: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Addition: %lf + %lf = %lf\n", num1, num2, num1 + num2);
        break;
    case 2:
        printf("Subtraction: %lf - %lf = %lf\n", num1, num2, num1 - num2);
        break;
    case 3:
        printf("Multiplication: %lf x %lf = %lf\n", num1, num2, num1 * num2);
        break;
    case 4:
        printf("Division: %lf / %lf = %lf\n", num1, num2, num1 / num2);
        break;
    case 5:
        printf("Power: %lf ^ %lf = %lf\n", num1, num2, power(num1, num2));
        break;
    case 6:
        printf("Square root: sqrt(%lf) = %lf\n", num1, sqrt(num1));
        break;
    case 7:
        printf("Factorial: %d! = %d\n", num1, factorial(num1));
        break;
    case 8:
        printf("Sine: sin(%lf) = %lf\n", num1, sin(num1));
        break;
    case 9:
        printf("Cosine: cos(%lf) = %lf\n", num1, cos(num1));
        break;
    case 10:
        printf("Tangent: tan(%lf) = %lf\n", num1, tan(num1));
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}