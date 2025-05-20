//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

// Function to calculate a combination
unsigned long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate the sine of a given angle in degrees
double sine(double angle) {
    double angle_rad = angle * (M_PI / 180.0);
    double sin_value = 0.0;
    for (int n = 0; n < 10; n++) {
        sin_value += power(-1, n) * power(angle_rad, 2 * n + 1) / factorial(2 * n + 1);
    }
    return sin_value;
}

// Function to calculate the cosine of a given angle in degrees
double cosine(double angle) {
    double angle_rad = angle * (M_PI / 180.0);
    double cos_value = 0.0;
    for (int n = 0; n < 10; n++) {
        cos_value += power(-1, n) * power(angle_rad, 2 * n) / factorial(2 * n);
    }
    return cos_value;
}

// Function to calculate the area of a circle given its radius
double circle_area(double radius) {
    return M_PI * power(radius, 2);
}

// Function to calculate the area of a triangle given its base and height
double triangle_area(double base, double height) {
    return (base * height) / 2;
}

// Function to calculate the area of a rectangle given its length and width
double rectangle_area(double length, double width) {
    return length * width;
}

// Function to calculate the roots of a quadratic equation
void quadratic_roots(double a, double b, double c) {
    double discriminant = power(b, 2) - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different: %.2f, %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Roots are real and the same: %.2f\n", root);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex: %.2f + %.2fi, %.2f - %.2fi\n", realPart, imaginaryPart, 
                realPart, imaginaryPart);
    }
}

// Function to display menu and get user input for calculations
void display_menu() {
    int choice;
    printf("Math Functions Menu:\n");
    printf("1. Factorial\n");
    printf("2. Power\n");
    printf("3. Combination\n");
    printf("4. Sine\n");
    printf("5. Cosine\n");
    printf("6. Area of Circle\n");
    printf("7. Area of Triangle\n");
    printf("8. Area of Rectangle\n");
    printf("9. Quadratic Equation Roots\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int n;
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);
            printf("Factorial of %d is %llu\n", n, factorial(n));
            break;
        }
        case 2: {
            double base;
            int exponent;
            printf("Enter base: ");
            scanf("%lf", &base);
            printf("Enter exponent: ");
            scanf("%d", &exponent);
            printf("%.2f raised to the power of %d is %.2f\n", base, exponent, power(base, exponent));
            break;
        }
        case 3: {
            int n, r;
            printf("Enter n: ");
            scanf("%d", &n);
            printf("Enter r: ");
            scanf("%d", &r);
            printf("Combination C(%d, %d) is %llu\n", n, r, combination(n, r));
            break;
        }
        case 4: {
            double angle;
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            printf("Sine of %.2f degrees is %.2f\n", angle, sine(angle));
            break;
        }
        case 5: {
            double angle;
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            printf("Cosine of %.2f degrees is %.2f\n", angle, cosine(angle));
            break;
        }
        case 6: {
            double radius;
            printf("Enter radius of circle: ");
            scanf("%lf", &radius);
            printf("Area of circle is %.2f\n", circle_area(radius));
            break;
        }
        case 7: {
            double base, height;
            printf("Enter base of triangle: ");
            scanf("%lf", &base);
            printf("Enter height of triangle: ");
            scanf("%lf", &height);
            printf("Area of triangle is %.2f\n", triangle_area(base, height));
            break;
        }
        case 8: {
            double length, width;
            printf("Enter length of rectangle: ");
            scanf("%lf", &length);
            printf("Enter width of rectangle: ");
            scanf("%lf", &width);
            printf("Area of rectangle is %.2f\n", rectangle_area(length, width));
            break;
        }
        case 9: {
            double a, b, c;
            printf("Enter coefficients a, b, c: ");
            scanf("%lf %lf %lf", &a, &b, &c);
            quadratic_roots(a, b, c);
            break;
        }
        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    while (1) {
        display_menu();
    }
    return 0;
}