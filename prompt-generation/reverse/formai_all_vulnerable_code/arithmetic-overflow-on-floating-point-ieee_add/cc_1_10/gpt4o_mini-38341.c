//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <math.h>

// Function to calculate the Fibonacci sequence up to N terms
void fibonacci(int n) {
    int t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

// Function to calculate the factorial of a number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to find the GCD (Greatest Common Divisor) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate the power of a number using recursion
double power(double base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp > 0) {
        return base * power(base, exp - 1);
    }
    return 1 / power(base, -exp);
}

// Function to calculate the area of a circle
double circleArea(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a triangle using Heron's formula
double triangleArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Function to display a menu and get user choice
int displayMenu() {
    int choice;
    printf("\nMath Operations Menu:\n");
    printf("1. Fibonacci Sequence\n");
    printf("2. Factorial\n");
    printf("3. GCD\n");
    printf("4. Power\n");
    printf("5. Area of Circle\n");
    printf("6. Area of Triangle\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Main function
int main() {
    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: {
                int n;
                printf("Enter the number of terms: ");
                scanf("%d", &n);
                fibonacci(n);
                break;
            }
            case 2: {
                int n;
                printf("Enter a positive integer: ");
                scanf("%d", &n);
                if (n < 0)
                    printf("Factorial is not defined for negative numbers.\n");
                else
                    printf("Factorial of %d = %lld\n", n, factorial(n));
                break;
            }
            case 3: {
                int a, b;
                printf("Enter two integers: ");
                scanf("%d %d", &a, &b);
                printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
                break;
            }
            case 4: {
                double base;
                int exp;
                printf("Enter base and exponent: ");
                scanf("%lf %d", &base, &exp);
                printf("%.2lf raised to the power of %d = %.2lf\n", base, exp, power(base, exp));
                break;
            }
            case 5: {
                double radius;
                printf("Enter radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of the circle = %.2lf\n", circleArea(radius));
                break;
            }
            case 6: {
                double a, b, c;
                printf("Enter lengths of the three sides of the triangle: ");
                scanf("%lf %lf %lf", &a, &b, &c);
                if (a + b > c && a + c > b && b + c > a) {
                    printf("Area of the triangle = %.2lf\n", triangleArea(a, b, c));
                } else {
                    printf("The lengths provided do not form a triangle.\n");
                }
                break;
            }
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}