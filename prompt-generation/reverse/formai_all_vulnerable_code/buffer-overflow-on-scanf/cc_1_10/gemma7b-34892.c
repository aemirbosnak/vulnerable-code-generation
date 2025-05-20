//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the Immersive C Online Examination System!\n");
    printf("-------------------------------------------------------\n");

    // Student Information
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    // Exam Questions
    char question[1000];
    printf("Enter the exam question: ");
    scanf("%s", question);

    // Answer Options
    char answer[4][20];
    printf("Enter the answer options:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Option %d: ", i + 1);
        scanf("%s", answer[i]);
    }

    // Marking Logic
    char correctAnswer[20];
    printf("Enter the correct answer: ");
    scanf("%s", correctAnswer);

    // Results
    int marks = 0;
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(answer[i], correctAnswer) == 0)
        {
            marks++;
        }
    }

    // Grade
    char grade = 'F';
    if (marks >= 80)
    {
        grade = 'A';
    } else if (marks >= 60)
    {
        grade = 'B';
    } else if (marks >= 40)
    {
        grade = 'C';
    }

    // Conclusion
    printf("-------------------------------------------------------\n");
    printf("Thank you, %s. Your result is: ", name);
    printf("Marks: %d, Grade: %c\n", marks, grade);

    return 0;
}