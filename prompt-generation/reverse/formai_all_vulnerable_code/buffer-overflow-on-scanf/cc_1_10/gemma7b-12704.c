//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");

    // Create a student database
    struct student
    {
        char name[50];
        int roll_no;
        float marks[5];
    } student_data[] = {
        {"John Doe", 1234, {90.5, 85.2, 78.9, 92.1, 83.4}},
        {"Jane Doe", 5678, {82.3, 89.4, 80.1, 88.6, 84.7}},
        {"Peter Pan", 2468, {79.6, 86.3, 82.2, 80.4, 88.5}}
    };

    // Display student information
    printf("Welcome to the Student Information System!\n");
    printf("Please select a student:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d. %s (Roll No: %d)\n", i + 1, student_data[i].name, student_data[i].roll_no);
    }

    // Get student choice
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Display student marks
    if (choice > 0 && choice <= 3)
    {
        printf("Student marks:\n");
        for (int i = 0; i < 5; i++)
        {
            printf("%f ", student_data[choice - 1].marks[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }

    system("pause");
    return 0;
}