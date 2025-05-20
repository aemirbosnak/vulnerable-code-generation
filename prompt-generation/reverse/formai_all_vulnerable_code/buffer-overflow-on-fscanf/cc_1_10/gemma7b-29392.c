//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question
{
    char question[256];
    char answer[MAX_ANSWERS];
    int marks;
} Question;

Question questions[MAX_QUESTIONS];

void readQuestions()
{
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL)
    {
        printf("Error reading questions file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%[^\n]%*c", questions[i].question) != EOF)
    {
        fscanf(fp, "%s", questions[i].answer);
        fscanf(fp, "%d", &questions[i].marks);
        i++;
    }

    fclose(fp);
}

void takeExam()
{
    printf("Enter your name: ");
    char name[256];
    scanf("%s", name);

    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s. %s (marks: %d)\n", i + 1, questions[i].question, questions[i].marks);

        char answer[MAX_ANSWERS];
        printf("Enter your answer: ");
        scanf("%s", answer);

        int marks = 0;
        for (int j = 0; j < MAX_ANSWERS; j++)
        {
            if (strcmp(answer, questions[i].answer[j]) == 0)
            {
                marks = questions[i].marks;
            }
        }

        score += marks;
    }

    printf("Your total score is: %d\n", score);
}

int main()
{
    readQuestions();
    takeExam();

    return 0;
}