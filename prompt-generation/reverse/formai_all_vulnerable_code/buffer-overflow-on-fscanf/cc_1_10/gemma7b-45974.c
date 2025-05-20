//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: automated
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

Candidate parse_resume(char *filename) {
    Candidate candidate;

    // Open the resume file
    FILE *fp = fopen(filename, "r");

    // Read the candidate's name
    fscanf(fp, "%s", candidate.name);

    // Read the candidate's experience
    fscanf(fp, "%[^\n]", candidate.experience);

    // Read the candidate's age
    fscanf(fp, "%d", &candidate.age);

    // Read the candidate's salary
    fscanf(fp, "%f", &candidate.salary);

    // Close the resume file
    fclose(fp);

    return candidate;
}

int main() {
    char *filename = "candidate.txt";
    Candidate candidate = parse_resume(filename);

    // Print the candidate's information
    printf("Name: %s\n", candidate.name);
    printf("Experience: %s\n", candidate.experience);
    printf("Age: %d\n", candidate.age);
    printf("Salary: %.2f\n", candidate.salary);

    return 0;
}