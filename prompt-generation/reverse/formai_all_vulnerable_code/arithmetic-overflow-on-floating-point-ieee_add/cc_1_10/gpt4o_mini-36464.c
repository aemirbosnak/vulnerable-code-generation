//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void displayMenu() {
    printf("\nMath Operations Menu:\n");
    printf("1. Calculate Area of a Circle\n");
    printf("2. Calculate Area of a Rectangle\n");
    printf("3. Calculate Hypotenuse of a Right Triangle\n");
    printf("4. Generate Fibonacci Sequence\n");
    printf("5. Calculate Factorial\n");
    printf("6. Exit\n");
    printf("Choose an option (1-6): ");
}

double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateHypotenuse(double sideA, double sideB) {
    return sqrt((sideA * sideA) + (sideB * sideB));
}

void generateFibonacci(int n) {
    int fib[MAX_SIZE];
    
    // Generate Fibonacci series
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Fibonacci Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int choice;
    double radius, length, width, sideA, sideB;
    int n;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the radius of the circle: ");
                scanf("%lf", &radius);
                printf("Area of the circle: %.2lf\n", calculateCircleArea(radius));
                break;
                
            case 2:
                printf("Enter length and width of the rectangle: ");
                scanf("%lf %lf", &length, &width);
                printf("Area of the rectangle: %.2lf\n", calculateRectangleArea(length, width));
                break;
                
            case 3:
                printf("Enter the lengths of the two sides: ");
                scanf("%lf %lf", &sideA, &sideB);
                printf("Hypotenuse of the triangle: %.2lf\n", calculateHypotenuse(sideA, sideB));
                break;
                
            case 4:
                printf("Enter the number of Fibonacci terms to generate: ");
                scanf("%d", &n);
                if (n <= 0 || n > MAX_SIZE) {
                    printf("Please enter a valid number of terms (1 - %d).\n", MAX_SIZE);
                } else {
                    generateFibonacci(n);
                }
                break;
                
            case 5:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d: %llu\n", n, factorial(n));
                break;
                
            case 6:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}