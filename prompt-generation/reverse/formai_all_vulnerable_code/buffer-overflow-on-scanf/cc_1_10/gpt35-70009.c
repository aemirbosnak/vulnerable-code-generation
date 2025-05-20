//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int score = 0;
    time_t current_time;
    current_time = time(NULL);
    srand(current_time);
    int questions[10][3];
    int answers[10];
    int response;
    int i,j;
    printf("Welcome to the C Programming Online Exam! You will have 10 questions to answer.\n");
    for(i=0;i<10;i++)
    {
        questions[i][0] = rand()%100+1;
        questions[i][1] = rand()%100+1;
        questions[i][2] = questions[i][0] + questions[i][1];
        printf("Question %d: What is %d + %d?\n",i+1,questions[i][0],questions[i][1]);
        scanf("%d",&response);
        if(response == questions[i][2])
        {
            printf("Correct!\n");
            score++;
            answers[i] = 1;
        }
        else
        {
            printf("Incorrect. The correct answer is %d.\n",questions[i][2]);
            answers[i] = 0;
        }
    }
    printf("Exam complete! You scored %d out of 10.\n",score);
    printf("Question\tCorrect Answer\tYour Answer\n");
    for(i=0;i<10;i++)
    {
        printf("%d\t\t%d\t\t",i+1,questions[i][2]);
        if(answers[i] == 1)
        {
            printf("%d (Correct)\n",questions[i][2]);
        }
        else
        {
            printf("%d (Incorrect)\n",response);
        }
    }
    return 0;
}