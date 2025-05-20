//FormAI DATASET v1.0 Category: Math exercise ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    srand(time(0)); //Seed for random number generator
    int x, y, op, answer, user_answer, correct=0, incorrect=0;

    printf("\nWelcome to the math quiz!\n");
    printf("You will be presented with 10 math problems to solve. Good luck!\n\n");

    for(int i=1; i<=10; i++)
    {
        x = rand()%100; //Random number from 0 to 99
        y = rand()%100;

        printf("Question %d: ", i);

        op = rand()%4; //Random operator

        switch(op)
        {
            case 0: //Addition
                answer = x + y;
                printf("%d + %d = ", x, y);
                break;

            case 1: //Subtraction
                answer = x - y;
                printf("%d - %d = ", x, y);
                break;

            case 2: //Multiplication
                answer = x * y;
                printf("%d * %d = ", x, y);
                break;

            case 3: //Division
                if(y==0) y = 1; //Avoid division by zero
                answer = x / y;
                printf("%d / %d = ", x, y);
                break;
                        
            default:
                printf("Invalid operator");
                break;
        }

        scanf("%d", &user_answer);

        if(user_answer == answer)
        {
            printf("Correct! You are great at math!\n");
            correct++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d\n", answer);
            incorrect++;
        }

        printf("\n");

        sleep(1); //Wait for 1 second before displaying the next question
    }

    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);
    printf("Thanks for playing!\n");

    return 0;
}