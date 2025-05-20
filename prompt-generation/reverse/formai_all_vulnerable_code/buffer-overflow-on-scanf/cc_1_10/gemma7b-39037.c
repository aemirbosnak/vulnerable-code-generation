//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    // Create a mock examination system
    int marks[] = { 0, 0, 0, 0, 0 };
    char student_name[20];
    char subject_name[20];

    // Get the student's name and subject name
    printf("Enter your name: ");
    scanf("%s", student_name);

    printf("Enter the subject name: ");
    scanf("%s", subject_name);

    // Get the student's marks
    printf("Enter your marks: ");
    scanf("%d", &marks[0]);
    scanf("%d", &marks[1]);
    scanf("%d", &marks[2]);
    scanf("%d", &marks[3]);
    scanf("%d", &marks[4]);

    // Calculate the student's total marks and average marks
    int total_marks = marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
    float average_marks = (float)total_marks / 5;

    // Print the student's results
    printf("\nYour name: %s", student_name);
    printf("\nSubject name: %s", subject_name);
    printf("\nTotal marks: %d", total_marks);
    printf("\nAverage marks: %.2f", average_marks);

    // Display a congratulatory message
    if (average_marks >= 90)
    {
        printf("\nCongratulations! You have excelled in this subject.");
    }
    else if (average_marks >= 80)
    {
        printf("\nCongratulations! You have done well in this subject.");
    }
    else if (average_marks >= 70)
    {
        printf("\nCongratulations! You have passed this subject.");
    }
    else
    {
        printf("\nSorry, you have not passed this subject.");
    }

    return 0;
}