//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate a random number
int rand_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    int num1, num2, operator, result;
    char choice;

    //Seeding the random number generator
    srand(time(NULL));

    //Loop until user decides to quit
    do
    {
        //Displaying the menu
        printf("\n");
        printf("Enter your choice:\n");
        printf("A - Addition\n");
        printf("S - Subtraction\n");
        printf("M - Multiplication\n");
        printf("D - Division\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        //Generating two random numbers
        num1 = rand_num(1, 100);
        num2 = rand_num(1, 100);

        //Performing the selected operation and displaying the result
        switch(choice)
        {
            case 'A':
            case 'a':
                result = num1 + num2;
                printf("\nResult: %d + %d = %d", num1, num2, result);
                break;

            case 'S':
            case's':
                result = num1 - num2;
                printf("\nResult: %d - %d = %d", num1, num2, result);
                break;

            case 'M':
            case'm':
                result = num1 * num2;
                printf("\nResult: %d * %d = %d", num1, num2, result);
                break;

            case 'D':
            case 'd':
                if(num2 == 0)
                {
                    printf("\nError: Division by zero");
                }
                else
                {
                    result = num1 / num2;
                    printf("\nResult: %d / %d = %.2f", num1, num2, (float)result);
                }
                break;

            case 'Q':
            case 'q':
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    }while(choice!= 'Q' && choice!= 'q');

    return 0;
}