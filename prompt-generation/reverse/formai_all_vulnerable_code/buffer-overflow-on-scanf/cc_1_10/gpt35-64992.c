//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_NAME 50
#define MAX_ANSWER 50

int main()
{
    char exam_name[MAX_NAME];
    int num_questions, i, j, k, score = 0;
    char correct_answers[MAX_QUESTIONS];
    char student_answers[MAX_ANSWER];

    printf("Enter exam name: ");
    scanf("%s", exam_name);

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++)
    {
        printf("Enter correct answer for question %d: ", i+1);
        scanf(" %c", &correct_answers[i]);
    }

    printf("\nStarting %s exam\n", exam_name);

    for (j = 0; j < num_questions; j++)
    {
        printf("Question %d: ", j+1);
        scanf("%s", student_answers);

        if (strlen(student_answers) != 1)
        {
            printf("Invalid answer. Answer must be a single character.\n");
            break;
        }

        if (student_answers[0] == correct_answers[j])
        {
            score++;
        }
    }

    printf("\n%s exam completed. You scored %d out of %d.\n", exam_name, score, num_questions);

    return 0;
}