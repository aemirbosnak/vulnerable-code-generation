//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    int age;
    float salary;
} Candidate;

void parse_resume(Candidate *candidate)
{
    FILE *fp;
    char line[MAX_NAME_LENGTH];

    fp = fopen("resume.txt", "r");
    if (fp == NULL)
    {
        return;
    }

    // Get candidate's name, email, and phone number
    fscanf(fp, "%s\n", candidate->name);
    fscanf(fp, "%s\n", candidate->email);
    fscanf(fp, "%s\n", candidate->phone);

    // Get candidate's experience
    fgets(candidate->experience, MAX_EXPERIENCE_LENGTH, fp);

    // Get candidate's age and salary
    fscanf(fp, "%d\n", &candidate->age);
    fscanf(fp, "%f\n", &candidate->salary);

    fclose(fp);
}

int main()
{
    Candidate candidate;

    parse_resume(&candidate);

    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Experience: %s\n", candidate.experience);
    printf("Age: %d\n", candidate.age);
    printf("Salary: %.2f\n", candidate.salary);

    return 0;
}