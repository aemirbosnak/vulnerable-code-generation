//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int num_questions, num_choices, num_students;
    int i, j, k, correct_answers = 0, total_questions = 0;
    int student_answers[100][10];
    char questions[100][100];
    char choices[100][4][50];
    char answers[100][50];

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++)
    {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i]);

        printf("Enter number of choices for question %d: ", i+1);
        scanf("%d", &num_choices);

        for (j = 0; j < num_choices; j++)
        {
            printf("Enter choice %d for question %d: ", j+1, i+1);
            scanf("%s", choices[i][j]);
        }

        strcpy(answers[i], choices[i][0]);
    }

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++)
    {
        for (j = 0; j < num_questions; j++)
        {
            printf("Enter answer for student %d, question %d: ", i+1, j+1);
            scanf("%s", student_answers[i][j]);

            if (strcmp(student_answers[i][j], answers[j]) == 0)
            {
                correct_answers++;
            }

            total_questions++;
        }

        printf("Student %d got %d out of %d questions correct.\n", i+1, correct_answers, total_questions);
        correct_answers = 0;
        total_questions = 0;
    }

    return 0;
}