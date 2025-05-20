//FormAI DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int i, j, k;
    int no_of_questions = 0, no_of_students = 0;
    int correct_answers = 0, wrong_answers = 0;
    float percentage;
    char correct_option[20] = {'\0'};

    //accepting number of questions
    printf("Enter the number of questions: ");
    scanf("%d", &no_of_questions);

    //creating dynamic array to store correct answers
    char* answers = (char*) malloc(sizeof(char) * no_of_questions);

    //accepting correct answers
    printf("Enter the correct options for each question (A, B, C or D):\n");
    for(i=0; i<no_of_questions; i++)
    {
        printf("Question %d: ", i+1);
        scanf(" %c", &answers[i]);
    }

    //accepting number of students
    printf("\nEnter the number of students: ");
    scanf("%d", &no_of_students);

    //creating dynamic 2D array to store student responses
    char** responses = (char**) malloc(sizeof(char*) * no_of_students);
    for (i=0; i<no_of_students; i++)
        responses[i] = (char*) malloc (sizeof(char) * no_of_questions);

    //accepting responses for each student
    for(i=0; i<no_of_students; i++)
    {
        printf("\nStudent %d:\n", i+1);
        for(j=0; j<no_of_questions; j++)
        {
            printf("Question %d: ", j+1);
            scanf(" %c", &responses[i][j]);
        }
    }

    //printing student-wise results
    printf("\nStudent-wise Results:\n");
    for(i=0; i<no_of_students; i++)
    {
        printf("\nStudent %d:\n", i+1);
        correct_answers = 0;
        wrong_answers = 0;

        for(j=0; j<no_of_questions; j++)
        {
            //checking answers
            if(responses[i][j] == answers[j])
            {
                printf("Question %d: Correct\n", j+1);
                correct_answers++;
            }
            else
            {
                printf("Question %d: Wrong\n", j+1);
                wrong_answers++;
            }
        }

        //calculating percentage
        percentage = ((float)correct_answers / no_of_questions) * 100;
        printf("Score: %.2f%% (%d out of %d)\n", percentage, correct_answers, no_of_questions);

        //displaying performance
        if(percentage >= 60)
            printf("Performance: Pass\n");
        else
            printf("Performance: Fail\n");
    }

    //destroying dynamic arrays
    free(answers);
    for (i=0; i<no_of_students; i++)
        free(responses[i]);
    free(responses);

    return 0;
}