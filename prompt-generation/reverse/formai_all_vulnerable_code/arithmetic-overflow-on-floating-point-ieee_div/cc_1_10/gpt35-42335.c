//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
#include<stdio.h>
#include<math.h>

int main()
{
    char operation; //for user entered operation type
    float num1, num2, result; //for user entered numbers and result

    //asking user to enter the operation they want to perform
    printf("Enter the operation you want to perform (+,-,*,/): ");
    scanf("%c",&operation);

    //asking user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%f %f",&num1,&num2);

    //checking the operation entered by the user
    switch(operation)
    {
        case '+':   //addition
            result=num1+num2;
            printf("The sum of %.2f and %.2f is %.2f.",num1,num2,result);
            break;

        case '-':   //subtraction
            result=num1-num2;
            printf("The difference between %.2f and %.2f is %.2f.",num1,num2,result);
            break;

        case '*':   //multiplication
            result=num1*num2;
            printf("The product of %.2f and %.2f is %.2f.",num1,num2,result);
            break;

        case '/':   //division
            if(num2!=0) //to avoid division by zero
            {
                result=num1/num2;
                printf("The quotient when %.2f is divided by %.2f is %.2f.",num1,num2,result);
            }
            else
                printf("Division by zero is undefined, please enter a non-zero denominator.");
            break;

        default:    //for invalid operation type
            printf("Invalid operation, please try again.");
    }

    return 0;
}