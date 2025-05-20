//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    double num1, num2, res;
    int choice;
    double stack[10];
    int top = -1;

    do {
        printf("Enter the number of operands and operators, or type 'q' to quit: ");
        scanf("%s", input);
        if (tolower(input[0]) == 'q') {
            break;
        }
        if (isdigit(input[0])) {
            num1 = atof(input);
            printf("Enter the operator: ");
            scanf("%s", input);
            switch (tolower(input[0])) {
                case '+':
                    printf("Enter the second operand: ");
                    scanf("%s", input);
                    num2 = atof(input);
                    res = num1 + num2;
                    printf("Result: %.2f\n", res);
                    break;
                case '-':
                    printf("Enter the second operand: ");
                    scanf("%s", input);
                    num2 = atof(input);
                    res = num1 - num2;
                    printf("Result: %.2f\n", res);
                    break;
                case '*':
                    printf("Enter the second operand: ");
                    scanf("%s", input);
                    num2 = atof(input);
                    res = num1 * num2;
                    printf("Result: %.2f\n", res);
                    break;
                case '/':
                    printf("Enter the second operand: ");
                    scanf("%s", input);
                    num2 = atof(input);
                    if (num2 == 0) {
                        printf("Error: Division by zero\n");
                    } else {
                        res = num1 / num2;
                        printf("Result: %.2f\n", res);
                    }
                    break;
                default:
                    printf("Invalid operator\n");
            }
        } else {
            choice = tolower(input[0]);
            switch (choice) {
                case's':
                    if (top == -1) {
                        printf("Stack is empty\n");
                    } else {
                        printf("Top of stack: %.2f\n", stack[top]);
                    }
                    break;
                case 'p':
                    if (top == -1) {
                        printf("Stack is empty\n");
                    } else {
                        printf("Pop: %.2f\n", stack[top]);
                        top--;
                    }
                    break;
                case 'c':
                    top = -1;
                    printf("Stack cleared\n");
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
    } while (1);

    return 0;
}