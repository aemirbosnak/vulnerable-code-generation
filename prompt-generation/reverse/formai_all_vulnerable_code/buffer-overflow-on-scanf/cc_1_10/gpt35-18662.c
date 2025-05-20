//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int questions[10][6] = { {1, 2, 0, 0, 0, 0},
                             {2, 3, 1, 0, 0, 0},
                             {3, 4, 3, 0, 0, 0},
                             {4, 1, 2, 0, 0, 0},
                             {5, 4, 3, 1, 2, 0},
                             {6, 1, 2, 1, 1, 0},
                             {7, 3, 1, 2, 1, 0},
                             {8, 4, 2, 1, 1, 0},
                             {9, 3, 4, 2, 0, 0},
                             {10, 4, 2, 3, 2, 0} };
    int answers[10][5] = { {1, 2, 3, 2, 1},
                           {2, 3, 1, 2, 1},
                           {3, 4, 3, 1, 2},
                           {4, 1, 2, 3, 1},
                           {5, 4, 3, 2, 1},
                           {6, 1, 1, 3, 1},
                           {7, 2, 3, 2, 1},
                           {8, 3, 2, 1, 1},
                           {9, 4, 2, 3, 1},
                           {10, 2, 1, 2, 1} };
    int userAnswers[10][2] = { {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0},
                               {0, 0} };
    int currentQuestion = 0;
    int totalScore = 0;

    printf("*** Welcome to the C Online Examination System ***\n\n");

    for(int i=0; i<10; i++)
    {
        currentQuestion = questions[i][0];

        printf("Question %d:\n\n", currentQuestion);
        printf("What is your answer?\n\n");

        printf("1) Option %d\n", questions[i][1]);
        printf("2) Option %d\n", questions[i][2]);
        printf("3) Option %d\n", questions[i][3]);
        printf("4) Option %d\n", questions[i][4]);
        printf("5) Skip this question\n");

        scanf("%d", &userAnswers[i][0]);

        if(userAnswers[i][0] != 5)
        {
            printf("\nEnter your reasoning/justification for selecting the above option:\n");
            scanf("%d", &userAnswers[i][1]);
        }
        else
        {
            continue;
        }

        if(userAnswers[i][0] == answers[i][1])
        {
            totalScore += 2;
        }
        else if(userAnswers[i][0] == answers[i][2])
        {
            totalScore += 1;
        }
    }

    printf("\n\nThank you for taking the exam!\n");
    printf("Your total score is: %d out of 20\n", totalScore);

    return 0;
}