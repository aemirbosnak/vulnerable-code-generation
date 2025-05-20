//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double num1, num2, ans;
    char operation;

    printf("Welcome to the Linux Scientific Calculator!\n");
    printf("Please enter your first number: ");
    scanf("%lf", &num1);

    printf("Please enter the operation you want to perform (+, -, *, /, sin, cos, tan): ");
    scanf(" %c", &operation);

    if (operation == 'sin' || operation == 'cos' || operation == 'tan') {
        num1 = num1 * (PI / 180);
    }

    if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
        printf("Please enter your second number: ");
        scanf("%lf", &num2);
    }

    switch(operation) {
        case '+':
            ans = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, ans);
            break;

        case '-':
            ans = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, ans);
            break;

        case '*':
            ans = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, ans);
            break;

        case '/':
            if(num2 == 0) {
                printf("Error! Cannot divide by zero.");
            } else {
                ans = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf", num1, num2, ans);
            }
            break;

        case 'sin':
            ans = sin(num1);
            printf("sin(%lf) = %lf", num1, ans);
            break;

        case 'cos':
            ans = cos(num1);
            printf("cos(%lf) = %lf", num1, ans);
            break;

        case 'tan':
            ans = tan(num1);
            printf("tan(%lf) = %lf", num1, ans);
            break;

        default:
            printf("Invalid operation!");
    }

    return 0;    
}