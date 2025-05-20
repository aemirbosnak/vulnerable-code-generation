//Gemma-7B DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Student {
    char name[MAX];
    int roll_no;
    float marks;
} Student;

int main()
{
    // Create an array of students
    Student students[MAX] = {
        {"John Doe", 123, 90.5},
        {"Jane Doe", 456, 85.2},
        {"Peter Pan", 789, 95.1},
        {"Mary Poppins", 321, 80.4},
        {"The Wizard of Oz", 543, 92.3}
    };

    // Print the details of each student
    for (int i = 0; i < MAX; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Search for a student by name
    char search_name[MAX];
    printf("Enter the name of the student to search for: ");
    scanf("%s", search_name);

    // Iterate over the students and find the student with the matching name
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(students[i].name, search_name) == 0)
        {
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Marks: %.2f\n", students[i].marks);
            break;
        }
    }

    return 0;
}