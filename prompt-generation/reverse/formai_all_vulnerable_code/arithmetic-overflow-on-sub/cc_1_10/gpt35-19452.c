//FormAI DATASET v1.0 Category: Recursive ; Style: all-encompassing
#include <stdio.h>

int factorial(int n){ //Recursive function to calculate the factorial of a given number
    if(n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

int fibonacci(int n){ //Recursive function to calculate the nth number in the Fibonacci sequence
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int num1, num2, choice;

    printf("Welcome to the Recursive Program!\n");

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Calculate Factorial\n");
        printf("2. Calculate Fibonacci\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter a number to calculate its factorial: ");
                scanf("%d", &num1);
                printf("The factorial of %d is %d\n", num1, factorial(num1));
                break;
            
            case 2:
                printf("\nEnter the nth number you would like to calculate in the Fibonacci sequence: ");
                scanf("%d", &num2);
                printf("The %dth number in the Fibonacci sequence is %d\n", num2, fibonacci(num2));
                break;
            
            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }while(choice != 3);

    return 0;
}