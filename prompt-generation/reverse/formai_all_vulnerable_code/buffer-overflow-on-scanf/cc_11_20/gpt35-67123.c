//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seeding the random number generator

    //randomly generating two numbers between 1 and 100 inclusive
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;

    printf("Welcome to the Math Exercise Program!\n");
    printf("In this program, you will have to solve 10 math problems.\n");
    printf("Each problem will have two randomly generated numbers between 1 and 100.\n");
    printf("Are you ready to get started? (y/n)\n");

    char choice;
    scanf("%c", &choice);

    if(choice == 'y' || choice == 'Y')
    {
        int count = 0; //count variable to keep track of number of correct answers

        for(int i=1; i<=10; i++)
        {
            int operation = rand() % 3; //randomly selecting an operation (0 - Addition, 1 - Subtraction, 2 - Multiplication)

            printf("Problem %d:\n", i);

            switch(operation)
            {
                case 0: //Addition
                {
                    printf("%d + %d = ?", num1, num2);

                    int answer;
                    scanf("%d", &answer);

                    if(answer == num1 + num2)
                    {
                        printf("Correct!\n");
                        count++;
                    }
                    else
                    {
                        printf("Incorrect! The correct answer is %d.\n", num1 + num2);
                    }

                    break;
                }
                case 1: //Subtraction
                {
                    printf("%d - %d = ?", num1, num2);

                    int answer;
                    scanf("%d", &answer);

                    if(answer == num1 - num2)
                    {
                        printf("Correct!\n");
                        count++;
                    }
                    else
                    {
                        printf("Incorrect! The correct answer is %d.\n", num1 - num2);
                    }

                    break;
                }
                case 2: //Multiplication
                {
                    printf("%d * %d = ?", num1, num2);

                    int answer;
                    scanf("%d", &answer);

                    if(answer == num1 * num2)
                    {
                        printf("Correct!\n");
                        count++;
                    }
                    else
                    {
                        printf("Incorrect! The correct answer is %d.\n", num1 * num2);
                    }

                    break;
                }
            }

            num1 = rand() % 100 + 1; //generating new random numbers for the next problem
            num2 = rand() % 100 + 1;
        }

        printf("Congratulations! You have completed all the problems.\n");
        if(count >= 7) //determining the user's score and giving feedback
        {
            printf("Your score is %d out of 10. Well done! You are a math rockstar!\n", count);
        }
        else if(count >= 4 && count < 7)
        {
            printf("Your score is %d out of 10. Not bad, but you could use some more practice.\n", count);
        }
        else
        {
            printf("Your score is %d out of 10. Oh no! You need some serious math practice!\n", count);
        }
    }
    else
    {
        printf("Okay, maybe next time then. Goodbye!\n");
    }
    
    return 0;
}