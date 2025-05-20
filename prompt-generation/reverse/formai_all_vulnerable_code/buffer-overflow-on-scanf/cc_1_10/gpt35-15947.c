//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int num_students, num_subjects;
    float total_marks = 0, average_marks;

    // Prompt user for number of students
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Prompt user for number of subjects
    printf("Enter the number of subjects: ");
    scanf("%d", &num_subjects);

    // Allocate memory for the marks array
    float** marks = (float**)malloc(num_students * sizeof(float*));

    // Initialize the marks array with zeros
    for (int i = 0; i < num_students; i++)
    {
        marks[i] = (float*)calloc(num_subjects, sizeof(float));
    }

    // Prompt user for students' marks
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter the marks for student %d:\n", i+1);

        for (int j = 0; j < num_subjects; j++)
        {
            printf("Subject %d: ", j+1);
            scanf("%f", &marks[i][j]);

            // Compute the total marks for each student
            total_marks += marks[i][j];
        }
    }

    // Compute the overall average marks
    average_marks = total_marks / (num_students * num_subjects);

    // Compute the standard deviation
    float deviation_sum = 0;

    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < num_subjects; j++)
        {
            deviation_sum += (marks[i][j] - average_marks) * (marks[i][j] - average_marks);
        }
    }

    float standard_deviation = sqrt(deviation_sum / (num_students * num_subjects));

    // Print the results
    printf("\nResult:\n");
    printf("Overall average marks: %.2f\n", average_marks);
    printf("Standard deviation: %.2f\n", standard_deviation);

    // Free memory
    for (int i = 0; i < num_students; i++)
    {
        free(marks[i]);
    }

    free(marks);

    return 0;
}