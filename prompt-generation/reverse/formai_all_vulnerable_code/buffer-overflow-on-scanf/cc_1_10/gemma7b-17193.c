//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student information
typedef struct Student
{
    char name[50];
    int roll_no;
    float marks[10];
    struct Student* next;
} Student;

// Function to insert a student at the end of the linked list
void insertAtEnd(Student** head)
{
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student roll number: ");
    scanf("%d", &newStudent->roll_no);
    printf("Enter student marks: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &newStudent->marks[i]);
    }

    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        (*head)->next = newStudent;
    }
}

// Function to print the students in the linked list
void printStudents(Student* head)
{
    while (head)
    {
        printf("Name: %s, Roll No: %d, Marks: ", head->name, head->roll_no);
        for (int i = 0; i < 10; i++)
        {
            printf("%f ", head->marks[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Student* head = NULL;

    // Insert students into the linked list
    insertAtEnd(&head);
    insertAtEnd(&head);
    insertAtEnd(&head);

    // Print the students in the linked list
    printStudents(head);

    return 0;
}