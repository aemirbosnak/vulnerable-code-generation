//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Student
{
    char name[MAX];
    int age;
    float gpa;
};

int main()
{
    struct Student students[MAX];
    int num_students = 0;

    // Check if the database file exists
    FILE *db = fopen("students.db", "r");

    if (db == NULL)
    {
        printf("Error: Database file does not exist.\n");
        return 1;
    }

    while (!feof(db))
    {
        if (fscanf(db, "%s %d %f", students[num_students].name, &students[num_students].age, &students[num_students].gpa) == 3)
        {
            num_students++;
        }
        else
        {
            printf("Error: Invalid format in database file.\n");
            return 1;
        }
    }

    // Check if the database file is closed
    if (fclose(db)!= 0)
    {
        printf("Error: Failed to close the database file.\n");
        return 1;
    }

    printf("Total number of students: %d\n", num_students);

    // Display the student data
    for (int i = 0; i < num_students; i++)
    {
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }

    return 0;
}