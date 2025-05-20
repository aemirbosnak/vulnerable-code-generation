//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, answer, choice, score = 0, counter = 0;
    srand(time(NULL));
    
    printf("Welcome to the Math Quiz Game!\n\n");

    while(1)
    {
        num1 = rand() % 100;
        num2 = rand() % 100;
        
        printf("What operation would you like to perform?\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit Game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 5)
        {
            printf("Thanks for playing! Your final score is: %d/%d\n", score, counter);
            break;
        }
        
        printf("What is %d ", num1);
        
        switch(choice)
        {
            case 1: // Addition
                printf("+ ");
                result = num1 + num2;
                break;
            case 2: // Subtraction
                printf("- ");
                result = num1 - num2;
                break;
            case 3: // Multiplication
                printf("* ");
                result = num1 * num2;
                break;
            case 4: // Division
                printf("/ ");
                result = num1 / num2;
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                continue;
        }
        
        printf("%d = ", num2);
        
        scanf("%d", &answer);
        
        if(answer == result)
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n\n", result);
        }
        
        counter++;
    }
    
    return 0;
}