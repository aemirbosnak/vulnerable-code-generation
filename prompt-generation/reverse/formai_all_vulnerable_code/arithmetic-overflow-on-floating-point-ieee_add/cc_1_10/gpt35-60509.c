//FormAI DATASET v1.0 Category: Calculator ; Style: thoughtful
#include<stdio.h>

//function to add two numbers
float add(float num1, float num2){
    return num1 + num2;
}

//function to subtract two numbers
float subtract(float num1, float num2){
    return num1 - num2;
}

//function to multiply two numbers
float multiply(float num1, float num2){
    return num1 * num2;
}

//function to divide two numbers
float divide(float num1, float num2){
    //check if denominator is zero
    if(num2==0){
        printf("Denominator cannot be zero\n");
        return 0;
    }
    else{
        return num1/num2;
    }
}

int main(){
    float num1, num2, result;
    int choice;

    printf("***Welcome to the Calculator***\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(choice){
        case 1:
            result = add(num1,num2);
            printf("The sum is: %f", result);
            break;
        case 2:
            result = subtract(num1,num2);
            printf("The difference is: %f", result);
            break;
        case 3:
            result = multiply(num1,num2);
            printf("The product is: %f", result);
            break;
        case 4:
            result = divide(num1,num2);
            printf("The quotient is: %f", result);
            break;
        default:
            printf("Invalid Choice");
    }

    return 0;
}