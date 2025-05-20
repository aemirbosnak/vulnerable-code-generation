//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a student
struct Student
{
    char name[50];
    int age;
    int marks;
};

// Function to initialize a student
void initStudent(struct Student *student)
{
    printf("Enter student name: ");
    scanf("%s", student->name);
    
    printf("Enter student age: ");
    scanf("%d", &student->age);
    
    printf("Enter student marks: ");
    scanf("%d", &student->marks);
}

// Function to add a student to the array
void addStudent(struct Student *students, int size)
{
    printf("Enter student name: ");
    scanf("%s", students[size].name);
    
    printf("Enter student age: ");
    scanf("%d", &students[size].age);
    
    printf("Enter student marks: ");
    scanf("%d", &students[size].marks);
}

// Function to print the information of all students in the array
void printStudents(struct Student *students, int size)
{
    printf("Name\tAge\tMarks\n");
    
    for(int i=0; i<size; i++)
    {
        printf("%s\t%d\t%d\n", students[i].name, students[i].age, students[i].marks);
    }
}

// Main function
int main()
{
    int size = 5;
    struct Student *students = (struct Student*)malloc(size * sizeof(struct Student));
    
    for(int i=0; i<size; i++)
    {
        initStudent(&students[i]);
        addStudent(students, size);
    }
    
    printStudents(students, size);
    
    free(students);
    
    return 0;
}