//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    double salary;
    struct Resume* next;
} Resume;

Resume* parse_resume(char* resume_text)
{
    char* name_start = strstr(resume_text, "Name:");
    char* name_end = strstr(name_start, "Age:");

    char* age_start = strstr(name_end, "Age:");
    char* age_end = strstr(age_start, "Salary:");

    char* salary_start = strstr(age_end, "Salary:");
    char* salary_end = strstr(salary_start, "Next:");

    int age = atoi(age_start) - 1;
    double salary = atof(salary_start) * 1.1;

    Resume* new_resume = malloc(sizeof(Resume));
    new_resume->name[0] = '\0';
    snprintf(new_resume->name, MAX_NAME_LENGTH, "%s", name_start + 5);
    new_resume->age = age;
    new_resume->salary = salary;
    new_resume->next = NULL;

    return new_resume;
}

int main()
{
    char* resume_text = "Name: John Doe\nAge: 25\nSalary: 50000\nNext:\n";

    Resume* resume = parse_resume(resume_text);

    printf("Name: %s\n", resume->name);
    printf("Age: %d\n", resume->age);
    printf("Salary: %.2lf\n", resume->salary);

    free(resume);

    return 0;
}