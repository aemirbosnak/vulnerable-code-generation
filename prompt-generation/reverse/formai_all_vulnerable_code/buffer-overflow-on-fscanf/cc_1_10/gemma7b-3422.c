//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Candidate
{
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
    struct Candidate* next;
} Candidate;

Candidate* parse_resume(char* file_path)
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL)
    {
        return NULL;
    }

    Candidate* head = NULL;
    Candidate* current = NULL;

    char name[MAX_NAME_LENGTH];
    int age;
    float salary;

    while (fscanf(file, "%s %d %f", name, &age, &salary) != EOF)
    {
        Candidate* new_candidate = malloc(sizeof(Candidate));

        strcpy(new_candidate->name, name);
        new_candidate->age = age;
        new_candidate->salary = salary;

        if (head == NULL)
        {
            head = new_candidate;
            current = head;
        }
        else
        {
            current->next = new_candidate;
            current = new_candidate;
        }
    }

    fclose(file);
    return head;
}

int main()
{
    char* file_path = "resume.txt";
    Candidate* head = parse_resume(file_path);

    if (head)
    {
        Candidate* current = head;
        while (current)
        {
            printf("Name: %s, Age: %d, Salary: %.2f\n", current->name, current->age, current->salary);
            current = current->next;
        }
    }

    return 0;
}