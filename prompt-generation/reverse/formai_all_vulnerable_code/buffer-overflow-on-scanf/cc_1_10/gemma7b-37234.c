//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define the exam structure
    struct exam
    {
        char name[20];
        int roll_no;
        float marks[5];
    } student;

    // Create an array of students
    struct exam students[100];

    // Get the number of students
    int num_students = 0;

    // Loop to get student information
    while (1)
    {
        printf("Enter student name: ");
        scanf("%s", students[num_students].name);

        printf("Enter student roll no: ");
        scanf("%d", &students[num_students].roll_no);

        printf("Enter student marks: ");
        for (int i = 0; i < 5; i++)
        {
            scanf("%f", &students[num_students].marks[i]);
        }

        num_students++;

        // Check if the student wants to continue
        char continue_or_not;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_or_not);

        if (continue_or_not == 'N')
        {
            break;
        }
    }

    // Print the student information
    for (int i = 0; i < num_students; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Marks: ");
        for (int j = 0; j < 5; j++)
        {
            printf("%f ", students[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}