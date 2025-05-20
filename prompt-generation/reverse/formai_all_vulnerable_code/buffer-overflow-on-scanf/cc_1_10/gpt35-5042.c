//FormAI DATASET v1.0 Category: Educational ; Style: excited
#include<stdio.h>

int main(){
    printf("Welcome to the world of C programming!!!\n");
    printf("This program will help you understand the basic concepts of C programming.\n");
    printf("So, let's get started...\n\n");

    //Variable declaration and initialization
    int x = 10, y = 5, sum = 0;

    //Addition operation
    sum = x + y;

    //Output display
    printf("The sum of %d and %d is %d.\n", x, y, sum);

    //Logical operation - if-else statement
    if(x > y){
        printf("X is greater than Y.\n");
    }
    else{
        printf("X is less than Y.\n");
    }

    //Looping operation - for loop
    int i;
    printf("Printing numbers from 1 to 10:\n");
    for(i=1; i<=10; i++){
        printf("%d ", i);
    }
    printf("\n");

    //Switch operation
    int choice;
    printf("Enter your choice (1 for Addition, 2 for Subtraction, 3 for Multiplication and 4 for Division):\n");
    scanf("%d", &choice);

    int num1, num2, result;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    switch(choice){
        case 1:
            result = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, result);
            break;

        case 2:
            result = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, result);
            break;

        case 3:
            result = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, result);
            break;

        case 4:
            result = num1 / num2;
            printf("The quotient of %d and %d is %d.\n", num1, num2, result);
            break;

        default:
            printf("Invalid choice!!!\n");
    }

    printf("Thank you for learning with us!!!\n");

    return 0;
}