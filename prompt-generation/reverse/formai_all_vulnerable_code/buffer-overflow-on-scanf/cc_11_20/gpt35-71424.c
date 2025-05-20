//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    int num1, num2, num3, choice, correct = 0, attempts = 1;
    float result, answer;
    //Initializing the random seed
    srand(time(NULL));
    
    //Loop to keep the program running until user exits
    while(1)
    {
        //Displaying menu options
        printf("\nWelcome to Math Exercise Program!\n");
        printf("Choose an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        //Exiting program if choice is 5
        if(choice == 5)
        {
            printf("Thank you for using Math Exercise Program!\n");
            break;
        }
        
        //Generating random numbers for the user to solve
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;
        
        //Switch case to perform arithmetic operation based on user choice
        switch(choice)
        {
            case 1:
                printf("\n%d + %d = ", num1, num2);
                result = num1 + num2;
                break;
            case 2:
                printf("\n%d - %d = ", num1, num2);
                result = num1 - num2;
                break;
            case 3:
                printf("\n%d x %d = ", num1, num2);
                result = num1 * num2;
                break;
            case 4:
                //Checking if num2 is not 0 to avoid division by 0 error
                if(num2 == 0)
                {
                    printf("\nCannot perform division by 0, generating new numbers...\n");
                    continue;
                }
                //Ensuring result is a float to get accurate division result
                num3 = rand() % 100 + 1;
                printf("\n%d / %d = ", num2*num3, num2);
                result = (float)(num2*num3) / num2;
                break;
            default:
                printf("\nInvalid choice, please try again...\n");
                continue;
        }
        //Getting user input for the answer
        scanf("%f", &answer);
        
        //Checking if answer is correct and displaying appropriate message
        if(fabs(answer - result) < 0.0001)
        {
            printf("Congratulations! Your answer is correct.\n");
            correct++;
        }
        else
        {
            printf("Sorry, your answer is incorrect. Please try again.\n");
            //Loop to keep track of attempts made by user
            while(1)
            {
                printf("Attempt #%d: ", attempts);
                scanf("%f", &answer);
                if(fabs(answer - result) < 0.0001)
                {
                    printf("Congratulations, your answer is correct!\n");
                    correct++;
                    break;
                }
                else if(attempts == 3)
                {
                    printf("Sorry, you have used all your attempts. The correct answer is %.2f\n", result);
                    break;
                }
                else
                {
                    printf("Sorry, your answer is incorrect. Please try again.\n");
                    attempts++;
                }
            }
        }
    }
    return 0;
}