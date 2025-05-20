//FormAI DATASET v1.0 Category: Math exercise ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to calculate power of a number
int power(int a, int b)
{
    if(b==0)
        return 1;
    else
        return a*power(a, b-1);
}

int main()
{
    int rand_num1, rand_num2, ans;
    char op;
    srand(time(0));

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("In this program, you will be given a random math exercise to solve.\n");
    printf("If you calculate the answer correctly, you get a point!\n");
    printf("Let's get started!\n\n");

    while(1)
    {
        // generate random numbers and operator
        rand_num1 = rand() % 100;
        rand_num2 = rand() % 10;
        op = rand() % 3 == 0 ? '+' : rand() % 3 == 1 ? '-' : '*';
        
        // print exercise for user to solve
        printf("%d %c %d = ", rand_num1, op, rand_num2);

        // read user's answer
        scanf("%d", &ans);

        // check user's answer
        if(op == '+')
        {
            if(ans == rand_num1+rand_num2)
            {
                printf("Correct! You get a point!\n");
            }   
            else
            {
                printf("Wrong answer! The correct answer is %d. Better luck next time!\n", rand_num1+rand_num2);
            }   
        }
        else if(op == '-')
        {
            if(ans == rand_num1-rand_num2)
            {
                printf("Correct! You get a point!\n");
            }   
            else
            {
                printf("Wrong answer! The correct answer is %d. Better luck next time!\n", rand_num1-rand_num2);
            }   
        }
        else
        {
            if(ans == rand_num1*rand_num2)
            {
                printf("Correct! You get a point!\n");
            }   
            else
            {
                printf("Wrong answer! The correct answer is %d. Better luck next time!\n", rand_num1*rand_num2);
            }   
        }
        
        // display user's score
        printf("Your score: %d\n\n", power(2, ans));

        // check if user wants to continue
        char choice;
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &choice);
        if(choice == 'n')
            break;
    }

    printf("Thank you for playing the Math Exercise Program!\n\n");
    printf("Created by a chatbot who doesn't understand why 6 is afraid of 7. Because 7, 8, 9? That doesn't make sense!\n\n");

    return 0;
}