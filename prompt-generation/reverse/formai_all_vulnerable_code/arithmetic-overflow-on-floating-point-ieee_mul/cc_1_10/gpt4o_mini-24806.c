//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Function declarations
Complex add(Complex, Complex);
Complex subtract(Complex, Complex);
Complex multiply(Complex, Complex);
Complex divide(Complex, Complex);
void displayComplex(Complex);
int menu();

int main() {
    Complex num1, num2, result;
    int choice;
    char again;

    do {
        printf("Enter the real and imaginary parts of the first complex number:\n");
        printf("Real: ");
        scanf("%f", &num1.real);
        printf("Imaginary: ");
        scanf("%f", &num1.imag);

        printf("Enter the real and imaginary parts of the second complex number:\n");
        printf("Real: ");
        scanf("%f", &num2.real);
        printf("Imaginary: ");
        scanf("%f", &num2.imag);

        do {
            choice = menu();

            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    printf("The result of addition is: ");
                    displayComplex(result);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    printf("The result of subtraction is: ");
                    displayComplex(result);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    printf("The result of multiplication is: ");
                    displayComplex(result);
                    break;
                case 4:
                    if (num2.real == 0 && num2.imag == 0) {
                        printf("Error: Division by zero is not allowed!\n");
                    } else {
                        result = divide(num1, num2);
                        printf("The result of division is: ");
                        displayComplex(result);
                    }
                    break;
                case 5:
                    printf("Exiting the program.\n");
                    return 0;
                default:
                    printf("Invalid choice! Please try again.\n");
            }

            printf("Would you like to perform another operation? (y/n): ");
            scanf(" %c", &again);
        } while (again == 'y' || again == 'Y');

        printf("Would you like to input new numbers? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}

// Function to add two complex numbers
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

// Function to divide two complex numbers
Complex divide(Complex a, Complex b) {
    Complex result;
    float denominator = (b.real * b.real) + (b.imag * b.imag);
    result.real = ((a.real * b.real) + (a.imag * b.imag)) / denominator;
    result.imag = ((a.imag * b.real) - (a.real * b.imag)) / denominator;
    return result;
}

// Function to display a complex number
void displayComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

// Function to display the menu and get choice
int menu() {
    int choice;
    printf("\nSelect an operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}