//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
//Program to perform arithmetic operations using modular approach in C

#include<stdio.h>

//Function to perform addition of two numbers
int additon(int n1, int n2){
    return (n1 + n2);
}

//Function to perform subtraction of two numbers
int subtraction(int n1, int n2){
    return (n1 - n2);
}

//Function to perform multiplication of two numbers
int multiplication(int n1, int n2){
    return (n1 * n2);
}

//Function to perform division of two numbers
int division(int n1, int n2){
    if(n2 == 0){
        printf("Division by zero is not possible!");
        return 0;
    }
    else{
        return (n1 / n2);
    }
}

int main(){
    int num1, num2, choice, result;
    
    printf("\n\nWelcome to Arithmetic Calculator\n");
    printf("------------------------------------------");
    
    printf("\nEnter first number: ");
    scanf("%d", &num1);
    
    printf("\nEnter second number: ");
    scanf("%d", &num2);
    
    printf("\nEnter your choice of operation:\n");
    printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1: 
            result = additon(num1, num2);
            printf("\nResult of addition is: %d", result);
            break;
        
        case 2: 
            result = subtraction(num1, num2);
            printf("\nResult of subtraction is: %d", result);
            break;
            
        case 3: 
            result = multiplication(num1, num2);
            printf("\nResult of multiplication is: %d", result);
            break;
            
        case 4: 
            result = division(num1, num2);
            printf("\nResult of division is: %d", result);
            break;
            
        default: 
            printf("\nInvalid choice of operation!");
            break;
    }
    
    return 0;
}