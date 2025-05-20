//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 256

// Function prototypes
void write_to_file(const char *filename, const char *data);
void read_from_file(const char *filename);
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);
void square(double a);
void square_root(double a);

int main() {
    char filename[MAX_LINE_LENGTH];
    double num1, num2;
    int operation, flag = 1;

    printf("Enter filename to save calculations: ");
    scanf("%s", filename);
    
    while (flag) {
        printf("\nSelect an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square\n");
        printf("6. Square Root\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &operation);

        if (operation == 0) {
            flag = 0;
            printf("Exiting...\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);

        if (operation >= 1 && operation <= 4) {
            printf("Enter second number: ");
            scanf("%lf", &num2);
        }

        switch (operation) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            case 5:
                square(num1);
                break;
            case 6:
                square_root(num1);
                break;
            default:
                printf("Invalid operation selected.\n");
                break;
        }
    }

    read_from_file(filename);
    return 0;
}

void write_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s", data);
    fclose(file);
}

void read_from_file(const char *filename) {
    char buffer[MAX_LINE_LENGTH];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\nCalculations saved in %s:\n", filename);
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(file);
}

void add(double a, double b) {
    double result = a + b;
    printf("Result of Addition: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Addition: %.2lf + %.2lf = %.2lf\n", a, b, result);
    write_to_file("calculations.txt", output);
}

void subtract(double a, double b) {
    double result = a - b;
    printf("Result of Subtraction: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Subtraction: %.2lf - %.2lf = %.2lf\n", a, b, result);
    write_to_file("calculations.txt", output);
}

void multiply(double a, double b) {
    double result = a * b;
    printf("Result of Multiplication: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Multiplication: %.2lf * %.2lf = %.2lf\n", a, b, result);
    write_to_file("calculations.txt", output);
}

void divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not defined.\n");
        return;
    }
    double result = a / b;
    printf("Result of Division: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Division: %.2lf / %.2lf = %.2lf\n", a, b, result);
    write_to_file("calculations.txt", output);
}

void square(double a) {
    double result = a * a;
    printf("Result of Square: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Square: %.2lf^2 = %.2lf\n", a, result);
    write_to_file("calculations.txt", output);
}

void square_root(double a) {
    if (a < 0) {
        printf("Error: Square root of negative number is not defined.\n");
        return;
    }
    double result = sqrt(a);
    printf("Result of Square Root: %.2lf\n", result);
    char output[MAX_LINE_LENGTH];
    sprintf(output, "Square Root: sqrt(%.2lf) = %.2lf\n", a, result);
    write_to_file("calculations.txt", output);
}