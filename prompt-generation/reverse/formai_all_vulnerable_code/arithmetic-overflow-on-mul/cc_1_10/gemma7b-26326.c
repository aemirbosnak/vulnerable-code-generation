//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("cls");

    // Student Information
    char student_name[20];
    int student_id;
    float marks[3];

    // Exam Information
    char exam_name[50];
    int exam_duration;
    int total_marks;

    // Question Bank
    char questions[100][200];
    int question_no = 0;

    // Marks Obtained
    int marks_obtained[100];

    // Initialize the system
    printf("Welcome to the C Online Examination System!\n");
    printf("Please provide your student name: ");
    scanf("%s", student_name);
    printf("Please provide your student ID: ");
    scanf("%d", &student_id);
    printf("Please provide your marks in the three subjects: ");
    scanf("%f %f %f", &marks[0], &marks[1], &marks[2]);

    // Create the exam information
    printf("Please provide the name of the exam: ");
    scanf("%s", exam_name);
    printf("Please provide the duration of the exam in minutes: ");
    scanf("%d", &exam_duration);
    total_marks = 100 * exam_duration / 2;

    // Create the question bank
    printf("Please provide the questions for the exam: ");
    while (question_no < total_marks)
    {
        scanf("%s", questions[question_no]);
        question_no++;
    }

    // Assign marks to each question
    printf("Please provide the marks obtained for each question: ");
    for (int i = 0; i < question_no; i++)
    {
        scanf("%d", &marks_obtained[i]);
    }

    // Calculate the total marks and grade
    float total_marks_obtained = 0;
    for (int i = 0; i < question_no; i++)
    {
        total_marks_obtained += marks_obtained[i];
    }
    int grade = (total_marks_obtained / total_marks) * 100;

    // Print the results
    printf("Your student name: %s\n", student_name);
    printf("Your student ID: %d\n", student_id);
    printf("Your marks in the three subjects: %.2f %.2f %.2f\n", marks[0], marks[1], marks[2]);
    printf("Total marks obtained: %d\n", total_marks_obtained);
    printf("Grade: %d%%\n", grade);

    return 0;
}