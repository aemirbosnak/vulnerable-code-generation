//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    time_t t;
    time(&t);
    srand(t);

    // Student Information
    char name[20];
    int rollno;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your roll number: ");
    scanf("%d", &rollno);

    // Exam Information
    char subject[20];
    int marks;
    printf("Enter the subject of the exam: ");
    scanf("%s", subject);
    printf("Enter your marks: ");
    scanf("%d", &marks);

    // Question Paper
    int numQuestions = rand() % 10 + 1;
    char questions[numQuestions][200];
    for (int i = 0; i < numQuestions; i++)
    {
        printf("Question %d: ", i + 1);
        scanf("%s", questions[i]);
    }

    // Answer Sheet
    char answers[numQuestions][20];
    for (int i = 0; i < numQuestions; i++)
    {
        printf("Answer for Question %d: ", i + 1);
        scanf("%s", answers[i]);
    }

    // Result
    int totalMarks = 0;
    for (int i = 0; i < numQuestions; i++)
    {
        int marksForQuestion = rand() % marks + 1;
        totalMarks += marksForQuestion;
    }
    printf("Your total marks are: %d", totalMarks);

    return 0;
}