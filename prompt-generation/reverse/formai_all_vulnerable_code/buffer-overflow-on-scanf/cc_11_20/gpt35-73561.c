//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: curious
#include<stdio.h>
#include<math.h>

int main(){
    // Welcome Message
    printf("Welcome to the curious Scientific Calculator Program!\n");

    // User Input - Number 1
    printf("Enter your first number:\n");
    double num1;
    scanf("%lf", &num1);

    // User Input - Number 2
    printf("Enter your second number:\n");
    double num2;
    scanf("%lf", &num2);

    // User Input - Operation
    printf("Enter the operation you want to perform. Here are your options:\n");
    printf("+    - Addition\n");
    printf("-    - Subtraction\n");
    printf("*    - Multiplication\n");
    printf("/    - Division\n");
    printf("sin  - Sine\n");
    printf("cos  - Cosine\n");
    printf("tan  - Tangent\n");
    printf("log  - Logarithm with base 10\n");
    printf("ln   - Natural Logarithm\n");
    printf("pow  - Exponentiation\n");
    printf("sqrt - Square Root\n");
    printf("Enter the operation here:\n");

    char operation[10];
    scanf("%s", operation);

    // Calculation and Result
    if(strcmp(operation, "+") == 0){
        double result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
    } else if(strcmp(operation, "-") == 0){
        double result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
    } else if(strcmp(operation, "*") == 0){
        double result = num1 * num2;
        printf("%.2lf x %.2lf = %.2lf", num1, num2, result);
    } else if(strcmp(operation, "/") == 0){
        if(num2 == 0){
            printf("Undefined");
        } else {
            double result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
        }
    } else if(strcmp(operation, "sin") == 0){
        double result = sin(num1);
        printf("sin(%.2lf) = %.2lf", num1, result);
    } else if(strcmp(operation, "cos") == 0){
        double result = cos(num1);
        printf("cos(%.2lf) = %.2lf", num1, result);
    } else if(strcmp(operation, "tan") == 0){
        double result = tan(num1);
        printf("tan(%.2lf) = %.2lf", num1, result);
    } else if(strcmp(operation, "log") == 0){
        double result = log10(num1);
        printf("log(%.2lf) = %.2lf", num1, result);
    } else if(strcmp(operation, "ln") == 0){
        double result = log(num1);
        printf("ln(%.2lf) = %.2lf", num1, result);
    } else if(strcmp(operation, "pow") == 0){
        double result = pow(num1, num2);
        printf("%.2lf to the power of %.2lf = %.2lf", num1, num2, result);
    } else if(strcmp(operation, "sqrt") == 0){
        if(num1 < 0){
            printf("Undefined");
        } else {
            double result = sqrt(num1);
            printf("Square Root of %.2lf = %.2lf", num1, result);
        }
    } else{
        printf("Invalid Input");
    }

    // Thank You Message
    printf("\nThank you for using the curious Scientific Calculator Program!");

    // Program End
    return 0;
}