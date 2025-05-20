//FormAI DATASET v1.0 Category: Digital signal processing ; Style: recursive
#include<stdio.h>

// function to find factorial recursively
int factorial(int num){
    if(num == 0)
        return 1;
    else
        return num*factorial(num-1);
}

// function to find fibonacci series recursively
void fibonacci(int num){
    static int a=0, b=1, c;
    if(num==0)
        return;
    else{
        c = a+b; // add previous two numbers
        a = b; // set previous number as first number
        b = c; // set current number as second number
        printf("%d ",c); // print the fibonacci number
        fibonacci(num-1); // call the function recursively
    }
}

// main function
int main(){
    int choice, num, result;
    printf("Enter your choice:\n1. Find factorial\n2. Print fibonacci series\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter a number to find its factorial: ");
            scanf("%d",&num);
            result = factorial(num);
            printf("Factorial of %d is %d",num,result);
            break;

        case 2:
            printf("Enter the number of terms in fibonacci series: ");
            scanf("%d",&num);
            printf("Fibonacci series is: ");
            printf("0 1 "); // print first two numbers
            fibonacci(num-2); // call function to print remaining numbers
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}