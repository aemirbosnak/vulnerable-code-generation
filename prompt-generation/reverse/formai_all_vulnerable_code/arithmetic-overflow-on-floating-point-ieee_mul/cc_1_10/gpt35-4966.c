//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include<stdio.h>
#include<math.h>

double scientific_calculator(char op, double x, double y);

int main(){
    char operator;
    double num1, num2, result;
    printf("Enter the operator (+, -, *, /, sqrt): ");
    scanf("%c", &operator);
    if(operator == 'sqrt'){
        printf("Enter a number: ");
        scanf("%lf", &num1);
        result = scientific_calculator(operator, num1, 0);
    }
    else{
        printf("Enter the first number: ");
        scanf("%lf", &num1);
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        result = scientific_calculator(operator, num1, num2);
    }
    printf("The result is %lf", result);
    return 0;
}

double scientific_calculator(char op, double x, double y){
    double result;
    if(op == 'sqrt'){
        result = sqrt(x);
    }
    else if(op == '+'){
        result = x + y;
    }
    else if(op == '-'){
        result = x - y;
    }
    else if(op == '*'){
        result = x * y;
    }
    else if(op == '/'){
        if(y != 0){
            result = x / y;
        }
        else{
            printf("Can't divide by zero!");
            return 0;
        }
    }
    else{
        printf("Invalid operator!");
        return 0;
    }

    return result;
}