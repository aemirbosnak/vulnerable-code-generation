//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the module for student information
void student_info()
{
    printf("Enter your name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter your roll number: ");
    int roll_no;
    scanf("%d", &roll_no);

    printf("Enter your class: ");
    char class[20];
    scanf("%s", class);

    printf("Enter your marks: ");
    int marks;
    scanf("%d", &marks);

    printf("Student information:\n");
    printf("Name: %s\n", name);
    printf("Roll Number: %d\n", roll_no);
    printf("Class: %s\n", class);
    printf("Marks: %d\n", marks);
}

// Define the module for calculating marks
void calculate_marks()
{
    int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);

    int total_marks = marks * 4;
    float percentage = (total_marks * 100.0) / 1000.0;

    printf("Total marks: %d\n", total_marks);
    printf("Percentage: %.2f%\n", percentage);
}

// Define the main function
int main()
{
    int choice;

    printf("Enter 1 to view student information or 2 to calculate marks: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            student_info();
            break;
        case 2:
            calculate_marks();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}