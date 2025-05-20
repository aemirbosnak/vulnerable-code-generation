//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Resume* next;
} Resume;

int main()
{
    Resume* head = NULL;
    char input[MAX_NAME_LENGTH] = "";

    printf("Welcome to the Resume Parsing System!\n");

    // Loop to get the number of resumes
    int numResumes = 0;
    printf("How many resumes do you want to parse? ");
    scanf("%d", &numResumes);

    // Allocate memory for each resume
    for (int i = 0; i < numResumes; i++)
    {
        head = (Resume*)malloc(sizeof(Resume));
        head->next = NULL;

        // Get the resume name
        printf("Enter the name of the resume: ");
        scanf("%s", head->name);

        // Get the resume age
        printf("Enter the age of the resume: ");
        scanf("%d", &head->age);

        // Get the resume salary
        printf("Enter the salary of the resume: ");
        scanf("%f", &head->salary);

        // Add the resume to the head of the linked list
        if (head != NULL)
        {
            head = head->next;
        }
    }

    // Print the list of resumes
    printf("Here is a list of resumes:\n");
    for (Resume* current = head; current; current = current->next)
    {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2f\n", current->salary);
        printf("\n");
    }

    // Free the memory allocated for each resume
    for (Resume* current = head; current; current = current->next)
    {
        free(current);
    }

    return 0;
}