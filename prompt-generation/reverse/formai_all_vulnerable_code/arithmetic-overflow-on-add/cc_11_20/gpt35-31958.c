//FormAI DATASET v1.0 Category: Math exercise ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void) {
    int a, b, c, ans, guess;
    srand(time(NULL));
    
    printf("Welcome to the Math Exercise program!\n");
    printf("Please enter the range between which you would like to generate numbers.\n");
    printf("Enter the minimum value: ");
    scanf("%d", &a);
    printf("Enter the maximum value: ");
    scanf("%d", &b);
    
    printf("Please select the type of operation.\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    
    switch(c) //Determine the choice of operation
    {
        case 1: 
            printf("You have selected Addition.\n");
            printf("You will be asked five random questions. Good luck!\n");
            for(int i=0; i<5; i++) //Ask five random questions for addition
            {
                int num1 = rand()%(b-a+1)+a;
                int num2 = rand()%(b-a+1)+a;
                ans = num1 + num2;
                printf("What is %d + %d? ", num1, num2);
                scanf("%d", &guess);
                if(guess == ans) //Determine if the answer is correct
                {
                    printf("Great job! You got it right!\n");
                }
                else
                {
                    printf("Sorry, the correct answer was %d.\n", ans);
                }
            }
            break;
            
        case 2: 
            printf("You have selected Subtraction.\n");
            printf("You will be asked five random questions. Good luck!\n");
            for(int i=0; i<5; i++) //Ask five random questions for subtraction
            {
                int num1 = rand()%(b-a+1)+a;
                int num2 = rand()%(b-a+1)+a;
                ans = num1 - num2;
                printf("What is %d - %d? ", num1, num2);
                scanf("%d", &guess);
                if(guess == ans) //Determine if the answer is correct
                {
                    printf("Great job! You got it right!\n");
                }
                else
                {
                    printf("Sorry, the correct answer was %d.\n", ans);
                }
            }
            break;
            
        case 3: 
            printf("You have selected Multiplication.\n");
            printf("You will be asked five random questions. Good luck!\n");
            for(int i=0; i<5; i++) //Ask five random questions for multiplication
            {
                int num1 = rand()%(b-a+1)+a;
                int num2 = rand()%(b-a+1)+a;
                ans = num1 * num2;
                printf("What is %d * %d? ", num1, num2);
                scanf("%d", &guess);
                if(guess == ans) //Determine if the answer is correct
                {
                    printf("Great job! You got it right!\n");
                }
                else
                {
                    printf("Sorry, the correct answer was %d.\n", ans);
                }
            }
            break;
            
        case 4:
            printf("You have selected Division.\n");
            printf("You will be asked five random questions. Good luck!\n");
            for(int i=0; i<5; i++) //Ask five random questions for division
            {
                int num1 = rand()%(b-a+1)+a;
                int num2 = rand()%(b-a+1)+a;
                if(num2 == 0) //Check if the denominator is zero
                {
                    printf("Oops, the second number cannot be zero. Skipping this question...\n");
                    continue;
                }
                ans = num1 / num2;
                printf("What is %d / %d? ", num1, num2);
                scanf("%d", &guess);
                if(guess == ans) //Determine if the answer is correct
                {
                    printf("Great job! You got it right!\n");
                }
                else
                {
                    printf("Sorry, the correct answer was %d.\n", ans);
                }
            }
            break;
            
        default:
            printf("Invalid choice.\n");
            return 0;
    }
    printf("Thank you for using the Math Exercise program! Goodbye!\n");
    return 0;
}