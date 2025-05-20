//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Student
{
    char name[20];
    int rollNo;
    int marks[MAX_QUESTIONS];
} Student;

void generateQuestions()
{
    // Generate a list of questions
    FILE *fp = fopen("questions.txt", "w");
    fprintf(fp, "1. What is the meaning of the word 'entrepreneur'?\n");
    fprintf(fp, "2. Who was the first president of the United States?\n");
    fprintf(fp, "3. What is the capital of Australia?\n");
    fclose(fp);
}

int main()
{
    // Create a student
    Student student;
    strcpy(student.name, "John Doe");
    student.rollNo = 123;

    // Generate questions
    generateQuestions();

    // Take student's answers
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &student.marks[i]);
    }

    // Calculate student's marks
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        totalMarks += student.marks[i];
    }

    // Print student's marks
    printf("Total marks: %d\n", totalMarks);

    return 0;
}