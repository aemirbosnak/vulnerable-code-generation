//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student information
struct student
{
    char name[50];
    int roll_no;
    float marks;
};

// Function to compare two students
int compare(struct student *a, struct student *b)
{
    return a->marks - b->marks;
}

int main()
{
    // Create an array of students
    struct student students[100];

    // Get student information
    printf("Enter the number of students:");
    int num_students;
    scanf("%d", &num_students);

    // Populate the array
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter the name of the student:");
        scanf("%s", students[i].name);

        printf("Enter the roll number of the student:");
        scanf("%d", &students[i].roll_no);

        printf("Enter the marks of the student:");
        scanf("%f", &students[i].marks);
    }

    // Sort the students by marks
    qsort(students, num_students, sizeof(struct student), compare);

    // Print the sorted students
    printf("The sorted students are:");
    for (int i = 0; i < num_students; i++)
    {
        printf("\nName: %s", students[i].name);
        printf("\nRoll No: %d", students[i].roll_no);
        printf("\nMarks: %.2f", students[i].marks);
    }

    return 0;
}