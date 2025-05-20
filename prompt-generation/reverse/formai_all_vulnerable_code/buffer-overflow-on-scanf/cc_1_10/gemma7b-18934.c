//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student data
struct student
{
    char name[50];
    int roll_no;
    float marks;
};

// Function to compare two students
int compare(struct student *a, struct student *b)
{
    return strcmp(a->name, b->name);
}

int main()
{
    // Create an array of students
    struct student students[100];

    // Get the number of students
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    // Create and fill the student data
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter the name of the student: ");
        scanf("%s", students[i].name);

        printf("Enter the roll number of the student: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter the marks of the student: ");
        scanf("%f", &students[i].marks);
    }

    // Sort the students in ascending order by name
    qsort(students, num_students, sizeof(struct student), compare);

    // Print the sorted students
    printf("The sorted students are:\n");
    for (int i = 0; i < num_students; i++)
    {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}