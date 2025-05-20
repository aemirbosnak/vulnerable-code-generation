//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
/**
 * This is a scientific calculator implementation program in C Programming Language.
 * It can perform the 4 basic arithmetic operations (addition, subtraction, multiplication and division)
 * on two numbers, as well as various scientific operations like sine, cosine, logarithm, exponent, etc.
 */

#include<stdio.h>
#include<math.h>

//Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double sine(double);
double cosine(double);
double tangent(double);
double exponent(double);
double logarithm(double);

//Main function
int main(){
    //Variable declarations
    char operator;
    double num1, num2, answer;

    //Prompt user to enter operator
    printf("Enter operator (+, -, *, /, s, c, t, e, l): ");
    scanf("%c", &operator);

    //Check operator, and call respective function
    switch(operator){
        case '+':
            printf("Enter two numbers to add: ");
            scanf("%lf %lf", &num1, &num2);
            answer = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf", num1, num2, answer);
            break;
        case '-':
            printf("Enter two numbers to subtract: ");
            scanf("%lf %lf", &num1, &num2);
            answer = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf", num1, num2, answer);
            break;
        case '*':
            printf("Enter two numbers to multiply: ");
            scanf("%lf %lf", &num1, &num2);
            answer = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf", num1, num2, answer);
            break;
        case '/':
            printf("Enter two numbers to divide: ");
            scanf("%lf %lf", &num1, &num2);
            answer = divide(num1, num2);
            printf("%.2lf / %.2lf = %.2lf", num1, num2, answer);
            break;
        case 's':
            printf("Enter a number to find its sine: ");
            scanf("%lf", &num1);
            answer = sine(num1);
            printf("sin(%.2lf) = %.2lf", num1, answer);
            break;
        case 'c':
            printf("Enter a number to find its cosine: ");
            scanf("%lf", &num1);
            answer = cosine(num1);
            printf("cos(%.2lf) = %.2lf", num1, answer);
            break;
        case 't':
            printf("Enter a number to find its tangent: ");
            scanf("%lf", &num1);
            answer = tangent(num1);
            printf("tan(%.2lf) = %.2lf", num1, answer);
            break;
        case 'e':
            printf("Enter a number to find its exponent: ");
            scanf("%lf", &num1);
            answer = exponent(num1);
            printf("exp(%.2lf) = %.2lf", num1, answer);
            break;
        case 'l':
            printf("Enter a number to find its logarithm (base 10): ");
            scanf("%lf", &num1);
            answer = logarithm(num1);
            printf("log10(%.2lf) = %.2lf", num1, answer);
            break;
        default:
            printf("Invalid operator!");
    }
    return 0;
}

//Function definitions

//Addition function
double add(double num1, double num2){
    return num1 + num2;
}

//Subtraction function
double subtract(double num1, double num2){
    return num1 - num2;
}

//Multiplication function
double multiply(double num1, double num2){
    return num1 * num2;
}

//Division function
double divide(double num1, double num2){
    return num1 / num2;
}

//Sine function
double sine(double num){
    return sin(num);
}

//Cosine function
double cosine(double num){
    return cos(num);
}

//Tangent function
double tangent(double num){
    return tan(num);
}

//Exponent function
double exponent(double num){
    return exp(num);
}

//Logarithm function (base 10)
double logarithm(double num){
    return log10(num);
}