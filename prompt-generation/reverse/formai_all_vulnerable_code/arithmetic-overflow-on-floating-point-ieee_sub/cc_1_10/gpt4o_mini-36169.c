//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>

// Function prototypes
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);
void executeOperations(double numbers[], int size, char operations[]);

int main() {
    int numCount;
    printf("Enter the number of elements you want to process: ");
    scanf("%d", &numCount);

    double numbers[numCount];
    printf("Enter %d numbers separated by spaces:\n", numCount);
    for(int i = 0; i < numCount; i++) {
        scanf("%lf", &numbers[i]);
    }
    
    char operations[numCount - 1];
    printf("Enter the operations (+, -, *, /) to perform in order (e.g., +-*):\n");
    scanf("%s", operations);

    executeOperations(numbers, numCount, operations);

    return 0;
}

void add(double a, double b) {
    printf("Adding: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void subtract(double a, double b) {
    printf("Subtracting: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void multiply(double a, double b) {
    printf("Multiplying: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void divide(double a, double b) {
    if (b != 0) {
        printf("Dividing: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed!\n");
    }
}

void executeOperations(double numbers[], int size, char operations[]) {
    for (int i = 0; i < size - 1; i++) {
        switch (operations[i]) {
            case '+':
                add(numbers[i], numbers[i + 1]);
                break;
            case '-':
                subtract(numbers[i], numbers[i + 1]);
                break;
            case '*':
                multiply(numbers[i], numbers[i + 1]);
                break;
            case '/':
                divide(numbers[i], numbers[i + 1]);
                break;
            default:
                printf("Invalid operation: %c\n", operations[i]);
                break;
        }
    }
}