//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for generating random numbers

int main()
{
    int num1, num2, answer, userAnswer, input;
    int correctCount = 0, wrongCount = 0;
    srand(time(0)); //initialize seed for random number generator
    
    printf("\nWelcome to the Math Exercise Program!\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &input);
    
    switch(input)
    {
        case 1:
            printf("Addition Exercise\n");
            for(int i = 0; i < 10; i++)
            {
                num1 = rand() % 100 + 1; //generate random numbers from 1 to 100
                num2 = rand() % 100 + 1;
                answer = num1 + num2; //compute correct answer
                
                printf("\nQuestion %d: What is %d + %d? ", i+1, num1, num2);
                scanf("%d", &userAnswer);
                
                if(userAnswer == answer)
                {
                    printf("Correct!\n");
                    correctCount++;
                }
                else
                {
                    printf("Wrong! The correct answer is %d.\n", answer);
                    wrongCount++;
                }
            }
            break;
            
        case 2:
            printf("Subtraction Exercise\n");
            for(int i = 0; i < 10; i++)
            {
                num1 = rand() % 100 + 1; //generate random numbers from 1 to 100
                num2 = rand() % 100 + 1;
                answer = num1 - num2; //compute correct answer
                
                printf("\nQuestion %d: What is %d - %d? ", i+1, num1, num2);
                scanf("%d", &userAnswer);
                
                if(userAnswer == answer)
                {
                    printf("Correct!\n");
                    correctCount++;
                }
                else
                {
                    printf("Wrong! The correct answer is %d.\n", answer);
                    wrongCount++;
                }
            }
            break;
            
        case 3:
            printf("Multiplication Exercise\n");
            for(int i = 0; i < 10; i++)
            {
                num1 = rand() % 20 + 1; //generate random numbers from 1 to 20
                num2 = rand() % 20 + 1;
                answer = num1 * num2; //compute correct answer
                
                printf("\nQuestion %d: What is %d x %d? ", i+1, num1, num2);
                scanf("%d", &userAnswer);
                
                if(userAnswer == answer)
                {
                    printf("Correct!\n");
                    correctCount++;
                }
                else
                {
                    printf("Wrong! The correct answer is %d.\n", answer);
                    wrongCount++;
                }
            }
            break;
            
        case 4:
            printf("Division Exercise\n");
            for(int i = 0; i < 10; i++)
            {
                num1 = rand() % 100 + 1; //generate random numbers from 1 to 100
                num2 = rand() % 10 + 1; //second number should not be zero
                answer = num1 / num2; //compute correct answer
                
                printf("\nQuestion %d: What is %d / %d? (Round to nearest integer) ", i+1, num1, num2);
                scanf("%d", &userAnswer);
                
                if(userAnswer == answer)
                {
                    printf("Correct!\n");
                    correctCount++;
                }
                else
                {
                    printf("Wrong! The correct answer is %d.\n", answer);
                    wrongCount++;
                }
            }
            break;
            
        default:
            printf("Invalid choice!");
            break;
    }
    
    printf("\nExercise Completed!\n");
    printf("You got %d correct answer(s) and %d wrong answer(s).\n", correctCount, wrongCount);
    
    return 0;
}