//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char operation[50];
    double result;
    struct Node* next;
} Node;

Node* head = NULL;

void addCalculation(char* operation, double result) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->operation, operation);
    newNode->result = result;
    newNode->next = head;
    head = newNode;
}

void displayHistory() {
    Node* current = head;
    if (!current) {
        printf("No calculations performed yet.\n");
        return;
    }
    printf("Calculation History:\n");
    while (current != NULL) {
        printf("%s = %.2lf\n", current->operation, current->result);
        current = current->next;
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error! Division by zero.\n");
        return 0;
    }
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void calculator() {
    int choice;
    double num1, num2;
    char operation[50];
    
    while (1) {
        printf("\n--- Simple Calculator ---\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exponentiation\n");
        printf("6. Display Calculation History\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 7) {
            break;
        }

        if (choice >= 1 && choice <= 5) {
            printf("Enter first number: ");
            scanf("%lf", &num1);
            
            if (choice != 5) {
                printf("Enter second number: ");
                scanf("%lf", &num2);
            } else {
                printf("Enter the exponent (integer): ");
                scanf("%d", &num2);  // Using num2 as exponent when choice is 5
            }

            double result = 0;
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    strcpy(operation, "Addition");
                    break;
                case 2:
                    result = subtract(num1, num2);
                    strcpy(operation, "Subtraction");
                    break;
                case 3:
                    result = multiply(num1, num2);
                    strcpy(operation, "Multiplication");
                    break;
                case 4:
                    result = divide(num1, num2);
                    strcpy(operation, "Division");
                    break;
                case 5:
                    result = power(num1, (int)num2);
                    strcpy(operation, "Exponentiation");
                    break;
                default:
                    printf("Invalid choice!\n");
                    continue;
            }
            printf("Result: %.2lf\n", result);
            addCalculation(operation, result);
        } else if (choice == 6) {
            displayHistory();
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}

void cleanup() {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    calculator();
    cleanup();
    return 0;
}