//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about the candidate's work history
typedef struct {
    char company[50];
    char job_title[50];
    char start_date[15];
    char end_date[15];
} WorkExperience;

// Structure to hold information about the candidate's education
typedef struct {
    char institution[50];
    char degree[50];
    char field[50];
    char completion_date[15];
} Education;

// Structure to hold information about the candidate
typedef struct {
    char name[50];
    char email[50];
    char phone_number[20];
    char address[100];
    WorkExperience work_experience[10];
    Education education[10];
    int num_work_experiences;
    int num_educations;
} Candidate;

int main() {
    Candidate candidate;
    memset(&candidate, 0, sizeof(Candidate)); // Initialize candidate to all zeros

    // Parse resume fields from text file
    FILE *resume_file = fopen("resume.txt", "r");
    if (resume_file == NULL) {
        printf("Error: Cannot open resume.txt");
        exit(EXIT_FAILURE);
    }

    char line[250];
    while (fgets(line, 250, resume_file) != NULL) {
        char field[50];
        char value[200];
        sscanf(line, "%[^:]: %[^\n]", field, value);

        if (strcmp(field, "Name") == 0) {
            strcpy(candidate.name, value);
        } else if (strcmp(field, "Email") == 0) {
            strcpy(candidate.email, value);
        } else if (strcmp(field, "Phone Number") == 0) {
            strcpy(candidate.phone_number, value);
        } else if (strcmp(field, "Address") == 0) {
            strcpy(candidate.address, value);
        } else if (strcmp(field, "Work Experience") == 0) {
            sscanf(value, "%[^,],%[^,],%[^,],%s", candidate.work_experience[candidate.num_work_experiences].company,
                    candidate.work_experience[candidate.num_work_experiences].job_title,
                    candidate.work_experience[candidate.num_work_experiences].start_date,
                    candidate.work_experience[candidate.num_work_experiences].end_date);
            candidate.num_work_experiences++;
        } else if (strcmp(field, "Education") == 0) {
            sscanf(value, "%[^,],%[^,],%[^,],%s", candidate.education[candidate.num_educations].institution,
                    candidate.education[candidate.num_educations].degree,
                    candidate.education[candidate.num_educations].field,
                    candidate.education[candidate.num_educations].completion_date);
            candidate.num_educations++;
        }
    }

    fclose(resume_file);

    // Print out parsed resume information
    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone Number: %s\n", candidate.phone_number);
    printf("Address: %s\n", candidate.address);

    printf("Work Experience:\n");
    for (int i = 0; i < candidate.num_work_experiences; i++) {
        printf("    Company: %s\n", candidate.work_experience[i].company);
        printf("    Job Title: %s\n", candidate.work_experience[i].job_title);
        printf("    Start Date: %s\n", candidate.work_experience[i].start_date);
        printf("    End Date: %s\n", candidate.work_experience[i].end_date);
    }

    printf("Education:\n");
    for (int i = 0; i < candidate.num_educations; i++) {
        printf("    Institution: %s\n", candidate.education[i].institution);
        printf("    Degree: %s\n", candidate.education[i].degree);
        printf("    Field: %s\n", candidate.education[i].field);
        printf("    Completion Date: %s\n", candidate.education[i].completion_date);
    }

    return 0;
}