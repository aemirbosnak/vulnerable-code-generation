//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");

    // Student Information
    char name[20];
    int roll_no;
    float marks;

    // Exam Information
    char subject[20];
    int marks_obtained;

    // Question Bank
    char questions[1000];
    int question_number = 0;

    // Exam Start
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your roll number: ");
    scanf("%d", &roll_no);

    printf("Enter the subject you are taking: ");
    scanf("%s", subject);

    printf("Enter the marks you obtained: ");
    scanf("%f", &marks_obtained);

    // Generate Questions
    questions[question_number++] = "What is the capital of France?";
    questions[question_number++] = "Who wrote the novel Harry Potter?";
    questions[question_number++] = "What is the meaning of the word polymorphism?";

    // Answer the Questions
    for (int i = 0; i < question_number; i++)
    {
        printf("%s: ", questions[i]);
        scanf("%s", questions[i]);
    }

    // Calculate Final Marks
    float final_marks = marks_obtained + marks;

    // Display Results
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("Name: %s\n", name);
    printf("Roll Number: %d\n", roll_no);
    printf("Subject: %s\n", subject);
    printf("Marks Obtained: %f\n", marks_obtained);
    printf("Final Marks: %f\n", final_marks);
    printf("----------------------------------------------------\n");

    return 0;
}