//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

// Function to calculate factorial of a number recursively.
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

// Function to calculate fibonacci series recursively.
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return (fibonacci(n-1) + fibonacci(n-2));
    }
}

// Function to calculate power of a number recursively.
int power(int base, int exponent){
    if(exponent==0){
        return 1;
    }
    else{
        return (base*power(base, exponent-1));
    }
}

int main(){
    int choice, number, exponent;
    printf("*********Recursive Functions*********\n");
    printf("Choose an option from below: \n");
    printf("1. Calculate factorial of a number\n");
    printf("2. Generate fibonacci series\n");
    printf("3. Calculate power of a number\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter a number: ");
            scanf("%d", &number);
            printf("Factorial of %d is %d.\n", number, factorial(number));
            break;
        case 2:
            printf("Enter the required length of fibonacci series: ");
            scanf("%d", &number);
            printf("Fibonacci series of length %d is: \n", number);
            for(int i=0; i<number; i++){
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;
        case 3:
            printf("Enter the base number: ");
            scanf("%d", &number);
            printf("Enter the exponent: ");
            scanf("%d", &exponent);
            printf("%d to the power of %d is %d.\n", number, exponent, power(number, exponent));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}