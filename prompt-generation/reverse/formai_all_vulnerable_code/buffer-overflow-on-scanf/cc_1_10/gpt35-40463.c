//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed random number generator using time

    int num1, num2, choice, answer, userAnswer;
    int min = 1, max = 100; //Range of numbers to use

    do
    {
        num1 = rand() % (max - min + 1) + min; //Generate first random number
        num2 = rand() % (max - min + 1) + min; //Generate second random number

        printf("What operation would you like to perform?\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Addition
                answer = num1 + num2;
                printf("What is %d + %d?\n", num1, num2);
                break;

            case 2: //Subtraction
                answer = num1 - num2; 
                printf("What is %d - %d?\n", num1, num2);
                break;

            case 3: //Multiplication
                answer = num1 * num2;
                printf("What is %d * %d?\n", num1, num2);
                break;

            case 4: //Division
                answer = num1 / num2;
                printf("What is %d / %d (rounded down to the nearest integer)?\n", num1, num2);
                break;

            default: //Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                continue; //Skip the rest of the loop and start over from the beginning
        }

        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        if(userAnswer == answer)
        {
            printf("Correct! Good job!\n");
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        printf("Would you like to try another problem? (y/n): ");
        char replay;
        scanf(" %c", &replay);

        if(replay == 'n' || replay == 'N')
        {
            break; //Exit the loop and end the program
        }

    }while(1); //Infinite loop - only way to exit is through the "break" statement above

    return 0;
}