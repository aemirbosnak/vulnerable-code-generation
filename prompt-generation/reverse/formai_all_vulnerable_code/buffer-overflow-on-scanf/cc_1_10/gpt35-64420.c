//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    //Initializations
    int num1, num2, answer;
    char operator;
    int correct_count =0;
    int wrong_count =0;
    srand(time(0)); //Random seed

    //Loop to ask and validate answers for 10 math questions
    for(int i = 0; i < 10; i++)
    {
        num1 = rand() % 100; //Generate random number between 0 and 100
        num2 = rand() % 10; //Generate random number between 0 and 10
        operator = rand() % 4; //Generate random operator

        if(operator == 0)
        {
            answer = num1 + num2; //Addition
            printf("%d + %d = ", num1, num2);
        }
        else if(operator == 1)
        {
            answer = num1 - num2; //Subtraction
            printf("%d - %d = ", num1, num2);
        }
        else if(operator == 2)
        {
            answer = num1 * num2; //Multiplication
            printf("%d * %d = ", num1, num2);
        }
        else
        {
            answer = num1 / num2; //Division
            printf("%d / %d = ", num1, num2);
        }

        int user_answer;
        scanf("%d", &user_answer); //Get user answer

        if(user_answer == answer) //Compare user answer with correct answer
        {
            printf("Correct!\n");
            correct_count++;
        }
        else
        {
            printf("Wrong! The correct answer is: %d\n", answer);
            wrong_count++;
        }
    }

    //Calculate and display results
    float percentage = ((float)correct_count / 10) * 100;
    printf("\n\nTotal Correct: %d\nTotal Wrong: %d\nPercentage Correct: %0.2f%%\n", correct_count, wrong_count, percentage);

    return 0;
}