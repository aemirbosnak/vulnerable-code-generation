//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the sum of the first n natural numbers
int sum_of_natural_numbers(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_of_natural_numbers(n - 1);
    }
}

// Function to calculate the area of a circle
double area_of_circle(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the volume of a sphere
double volume_of_sphere(double radius) {
    return (4 / 3) * M_PI * radius * radius * radius;
}

// Function to calculate the surface area of a sphere
double surface_area_of_sphere(double radius) {
    return 4 * M_PI * radius * radius;
}

int main() {
    // Get the user's input
    int choice;
    printf("Enter your choice:\n");
    printf("1. Calculate the factorial of a number\n");
    printf("2. Calculate the nth Fibonacci number\n");
    printf("3. Calculate the sum of the first n natural numbers\n");
    printf("4. Calculate the area of a circle\n");
    printf("5. Calculate the volume of a sphere\n");
    printf("6. Calculate the surface area of a sphere\n");
    scanf("%d", &choice);

    // Call the appropriate function based on the user's choice
    int n;
    double radius;
    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("The factorial of %d is %d\n", n, factorial(n));
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("The sum of the first %d natural numbers is %d\n", n, sum_of_natural_numbers(n));
            break;
        case 4:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            printf("The area of the circle is %lf\n", area_of_circle(radius));
            break;
        case 5:
            printf("Enter the radius of the sphere: ");
            scanf("%lf", &radius);
            printf("The volume of the sphere is %lf\n", volume_of_sphere(radius));
            break;
        case 6:
            printf("Enter the radius of the sphere: ");
            scanf("%lf", &radius);
            printf("The surface area of the sphere is %lf\n", surface_area_of_sphere(radius));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}