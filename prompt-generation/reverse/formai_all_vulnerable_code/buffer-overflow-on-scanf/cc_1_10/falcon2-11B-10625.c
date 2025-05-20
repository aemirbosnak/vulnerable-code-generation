//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num_questions;
    int score;
    int answer;
    int i;
    char question[100];
    char answer1[100];
    char answer2[100];
    char answer3[100];
    char answer4[100];
    char *answers[4];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions: ");
    for (i = 0; i < num_questions; i++)
    {
        scanf("%s", question);
        printf("%s", question);
        fflush(stdout);
        answers[0] = answer1;
        answers[1] = answer2;
        answers[2] = answer3;
        answers[3] = answer4;
        printf("Enter answer 1: ");
        scanf("%s", answers[0]);
        printf("Enter answer 2: ");
        scanf("%s", answers[1]);
        printf("Enter answer 3: ");
        scanf("%s", answers[2]);
        printf("Enter answer 4: ");
        scanf("%s", answers[3]);
        printf("\n");
    }

    printf("Enter the correct answers: ");
    scanf("%s", answer1);
    printf("Enter answer 2: ");
    scanf("%s", answer2);
    printf("Enter answer 3: ");
    scanf("%s", answer3);
    printf("Enter answer 4: ");
    scanf("%s", answer4);
    printf("\n");

    score = 0;
    for (i = 0; i < num_questions; i++)
    {
        if (strcmp(answers[i], answer1) == 0)
        {
            score++;
            printf("Correct!\n");
        }
        else if (strcmp(answers[i], answer2) == 0)
        {
            score++;
            printf("Correct!\n");
        }
        else if (strcmp(answers[i], answer3) == 0)
        {
            score++;
            printf("Correct!\n");
        }
        else if (strcmp(answers[i], answer4) == 0)
        {
            score++;
            printf("Correct!\n");
        }
    }

    printf("Your score is %d/%d.\n", score, num_questions);

    return 0;
}