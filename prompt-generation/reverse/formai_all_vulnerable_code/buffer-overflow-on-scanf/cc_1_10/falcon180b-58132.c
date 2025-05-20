//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include<stdio.h>

//Recursive function to add two numbers
int add(int a, int b)
{
    if(b==0) //Base case
        return a;
    else
        return a+add(a,b-1); //Recursive case
}

//Recursive function to subtract two numbers
int subtract(int a, int b)
{
    if(b==0) //Base case
        return a;
    else
        return a-subtract(a,b-1); //Recursive case
}

//Recursive function to multiply two numbers
int multiply(int a, int b)
{
    if(b==0) //Base case
        return 0;
    else if(b==1) //Base case
        return a;
    else
        return a*multiply(a,b-1); //Recursive case
}

//Recursive function to divide two numbers
int divide(int a, int b)
{
    if(b==0) //Base case
        return 0;
    else
        return a/b + divide(a,b-1); //Recursive case
}

//Main function
int main()
{
    int num1, num2, choice;
    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);
    printf("Enter your choice:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Result of addition is: %d\n", add(num1,num2));
            break;
        case 2:
            printf("Result of subtraction is: %d\n", subtract(num1,num2));
            break;
        case 3:
            printf("Result of multiplication is: %d\n", multiply(num1,num2));
            break;
        case 4:
            printf("Result of division is: %d\n", divide(num1,num2));
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}