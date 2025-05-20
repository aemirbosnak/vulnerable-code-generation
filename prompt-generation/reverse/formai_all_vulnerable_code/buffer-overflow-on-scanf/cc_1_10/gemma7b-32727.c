//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i, j, k, l, m, n, score = 0, attempts = 3, question_number = 1;
    char answer, student_name[20];

    printf("Enter your name: ");
    scanf("%s", student_name);

    for (i = 0; i < attempts; i++)
    {
        printf("Question %d: ", question_number);
        scanf(" %c", &answer);

        switch (answer)
        {
            case 'a':
                score++;
                break;
            case 'b':
                score++;
                break;
            case 'c':
                score++;
                break;
            default:
                printf("Invalid answer.\n");
        }

        question_number++;
    }

    printf("Your score: %d", score);
    printf("\nYour final grade: ");

    if (score >= 80)
    {
        printf("A");
    }
    else if (score >= 60)
    {
        printf("B");
    }
    else if (score >= 40)
    {
        printf("C");
    }
    else
    {
        printf("F");
    }

    printf("\nThank you for taking the exam, %s!", student_name);
}