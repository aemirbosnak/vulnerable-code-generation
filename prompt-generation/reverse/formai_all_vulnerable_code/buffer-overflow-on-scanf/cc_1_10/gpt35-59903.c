//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h> 

int main() 
{ 
    int num1, num2;
    char operator;
  
    printf("Hello! Welcome to the Scientific Calculator!\n");
    printf("Please enter two numbers: ");

    scanf("%d %d", &num1, &num2);

    printf("What operation do you want to perform?\n");
    printf("Choose from: +, -, *, /, ^: ");

    scanf(" %c", &operator);

    switch(operator) 
    { 
        case '+':
            printf("The sum of %d and %d is %d.\n", num1, num2, num1+num2);
            break;

        case '-':
            printf("The difference between %d and %d is %d.\n", num1, num2, num1-num2);
            break;

        case '*':
            printf("The product of %d and %d is %d.\n", num1, num2, num1*num2);
            break;

        case '/':
            if(num2 == 0) 
            {
                printf("Error: You cannot divide by 0.\n");
            } 
            else 
            {
                printf("The quotient of %d and %d is %0.2f.\n", num1, num2, (float)num1/num2);
            }
            break;

        case '^':
            if(num2 < 0) 
            {
                printf("Error: You cannot raise a number to a negative power.\n");
            } 
            else 
            {
                int result = 1;
                for(int i = 0; i < num2; i++) 
                {
                    result *= num1;
                }
                printf("%d raised to the power of %d is %d.\n", num1, num2, result);
            }
            break;

        default:
            printf("Error: Invalid operator entered.\n");
    }
    printf("\nThank you for using the Scientific Calculator.");
    return 0; 
}