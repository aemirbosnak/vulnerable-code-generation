//FormAI DATASET v1.0 Category: Calculator ; Style: creative
#include <stdio.h>

// Function to add two numbers
float add(float a, float b){
    return a + b;
}

// Function to subtract two numbers
float subtract(float a, float b){
    return a - b;
}

// Function to multiply two numbers
float multiply(float a, float b){
    return a * b;
}

// Function to divide two numbers
float divide(float a, float b){
    if(b == 0){
        printf("Cannot divide by zero.\n");
        return 0;
    }
    else{
        return a / b;
    }
}

// Function to calculate square root
float squareRoot(float a){
    if(a < 0){
        printf("Cannot find square root of a negative number.\n");
        return 0;
    }
    else{
        return sqrt(a);
    }
}

int main(){
    char operation;
    float num1, num2;
    
    printf("*** C CALCULATOR ***\n");
    printf("+ for Addition\n");
    printf("- for Subtraction\n");
    printf("* for Multiplication\n");
    printf("/ for Division\n");
    printf("s for Square Root\n");
    printf("Enter an operation: ");
    scanf("%c", &operation);
    
    switch(operation){
        case '+':
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
            break;
        case '-':
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
            break;
        case '*':
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
            break;
        case '/':
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
            break;
        case 's':
            printf("Enter a number: ");
            scanf("%f", &num1);
            printf("Square root of %.2f is %.2f\n", num1, squareRoot(num1));
            break;
        default:
            printf("Invalid operation chosen.\n");
    }
    
    return 0;
}