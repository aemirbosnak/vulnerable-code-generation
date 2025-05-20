//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
//Welcome to the magical world of mathematics!
//We are going to create a program that performs a special arithmetic calculation.
//Let's immerse ourselves in imagination and create magic with code!

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;

    //Let's greet the user with an enchanting message
    printf("Welcome to the world of magic numbers!\n");
    printf("Enter two integer numbers and I will perform a special arithmetic calculation for you.\n");

    //Now, we will ask the user to enter the two numbers that we need
    printf("Enter the first integer number: ");
    scanf("%d", &num1);
    printf("Enter the second integer number: ");
    scanf("%d", &num2);

    //Get ready to cast the magic spell!
    result = (num1 + num2) * (num1 - num2);    //this is our special arithmetic calculation

    //We will now reveal the mysterious result to the user
    printf("My dear user, your magic number is: %d\n", result);

    //But wait, we can do more magic! Let's offer to perform another calculation
    printf("Do you want to perform another calculation? Type Y for YES or N for NO.\n");

    char choice;    //this variable will store the user's choice

    //The next lines will loop until the user enters either Y or N
    while(1)
    {
        scanf(" %c", &choice);    //we use a space before %c to clear the input buffer

        if(choice == 'Y' || choice == 'y')
        {
            printf("Let's do some more magic!\n");
            printf("Enter the first integer number: ");
            scanf("%d", &num1);
            printf("Enter the second integer number: ");
            scanf("%d", &num2);
            result = (num1 * num2) + (num1 / num2);   //another special calculation
            printf("Your new magic number is: %d\n", result);
            printf("Do you want to perform another calculation? Type Y for YES or N for NO.\n");
        }
        else if(choice == 'N' || choice == 'n')
        {
            printf("Thank you for visiting the world of magic numbers!\n");
            break;    //exit the loop
        }
        else    //if the user enters something else than Y or N
        {
            printf("Sorry my dear user, I did not understand. Please type only Y or N.\n");
            continue;    //repeat the loop
        }
    }

    return 0;   //end of program
}