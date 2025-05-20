//FormAI DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    /*Declaration of Variables*/
    int num1, num2, ans, user_ans, q_num = 1, score = 0;
    char ch;

    /*Display Introduction*/
    printf("Welcome to C Online Examination System\n\n");
    printf("The test consists of 10 questions.\n");
    printf("You will be given 2 numbers.\n");
    printf("Your task is to add them correctly and choose the right option.\n");
    printf("You will have only one chance to answer each question.\n\n");

    /*Looping through the questions*/
    while(q_num <= 10)
    {
        /*Generating random numbers*/
        srand(time(0));
        num1 = rand()%100;
        num2 = rand()%100;

        /*Displaying the Question*/
        printf("Question %d.\n", q_num);
        printf("What is %d + %d?\n", num1, num2);

        /*Calculating the correct answer*/
        ans = num1 + num2;

        /*Displaying options*/
        printf("Options:\n");
        printf("\tA. %d\n", ans+1);
        printf("\tB. %d\n", ans-1);
        printf("\tC. %d\n", ans);
        printf("\tD. %d\n", ans/2);

        /*Getting user's answer*/
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &ch);

        /*Converting the answer to uppercase*/
        ch = toupper(ch);

        /*Checking the user's answer*/
        switch(ch)
        {
            case 'A':
                user_ans = ans+1;
                break;
            case 'B':
                user_ans = ans-1;
                break;
            case 'C':
                user_ans = ans;
                break;
            case 'D':
                user_ans = ans/2;
                break;
            default:
                printf("Invalid option! Question skipped.\n");
                continue;
        }

        /*Checking if the user's answer is correct*/
        if(user_ans == ans)
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Incorrect!\n\n");
        }

        /*Incrementing the question number*/
        q_num++;
    }

    /*Displaying the final score*/
    printf("\n\nTest complete.\n");
    printf("Your score is %d out of 10.\n", score);

    return 0;
}