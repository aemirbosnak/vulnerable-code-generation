//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Candidate {
    char name[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    int age;
    float salary;
} Candidate;

Candidate parse_resume(FILE *fp) {
    Candidate candidate;

    // Get the candidate's name
    fscanf(fp, "%[^\n]%*c", candidate.name);

    // Get the candidate's experience
    fscanf(fp, "%[^\n]%*c", candidate.experience);

    // Get the candidate's age
    fscanf(fp, "Age: %d", &candidate.age);

    // Get the candidate's salary
    fscanf(fp, "Salary: %.2f", &candidate.salary);

    return candidate;
}

int main() {
    FILE *fp;
    Candidate candidate;

    // Open the resume file
    fp = fopen("resume.txt", "r");

    // Parse the resume
    candidate = parse_resume(fp);

    // Print the candidate's information
    printf("Name: %s\n", candidate.name);
    printf("Experience: %s\n", candidate.experience);
    printf("Age: %d\n", candidate.age);
    printf("Salary: %.2f\n", candidate.salary);

    // Close the resume file
    fclose(fp);

    return 0;
}