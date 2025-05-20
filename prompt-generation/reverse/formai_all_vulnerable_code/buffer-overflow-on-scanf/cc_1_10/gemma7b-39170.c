//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");
    printf("Welcome to the C Online Examination System!\n");

    // Student Information
    char student_name[50];
    printf("Enter your full name: ");
    scanf("%s", student_name);

    // Subject Information
    char subject_name[50];
    printf("Enter the subject name: ");
    scanf("%s", subject_name);

    // Question Paper
    char question_paper[1000];
    printf("Enter the question paper: ");
    scanf("%s", question_paper);

    // Answer Sheet
    char answer_sheet[1000];
    printf("Enter your answer sheet: ");
    scanf("%s", answer_sheet);

    // Marking
    int marks = 0;
    char answer_key[1000];
    printf("Enter the answer key: ");
    scanf("%s", answer_key);

    // Calculate Marks
    for (int i = 0; i < strlen(answer_sheet); i++)
    {
        if (answer_sheet[i] == answer_key[i])
        {
            marks++;
        }
    }

    // Display Results
    printf("Your marks: %d", marks);
    printf("\nCongratulations, %s! You have successfully completed the C Online Examination System.", student_name);

    return 0;
}