//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SECTION_LENGTH 100
#define MAX_JOB_LENGTH 100
#define MAX_SKILL_LENGTH 100
#define MAX_CERTIFICATION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char contact_info[MAX_SECTION_LENGTH];
    char objective[MAX_SECTION_LENGTH];
    char education[MAX_SECTION_LENGTH];
    char experience[MAX_SECTION_LENGTH];
    char skills[MAX_SECTION_LENGTH];
    char certifications[MAX_SECTION_LENGTH];
} Resume;

void read_resume(Resume *resume) {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: could not open resume file.\n");
        exit(1);
    }

    fscanf(file, "Name: %s\n", resume->name);
    fscanf(file, "Contact Info: %s\n", resume->contact_info);
    fscanf(file, "Objective: %s\n", resume->objective);
    fscanf(file, "Education: %s\n", resume->education);
    fscanf(file, "Experience: %s\n", resume->experience);
    fscanf(file, "Skills: %s\n", resume->skills);
    fscanf(file, "Certifications: %s\n", resume->certifications);

    fclose(file);
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Contact Info: %s\n", resume->contact_info);
    printf("Objective: %s\n", resume->objective);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("Certifications: %s\n", resume->certifications);
}

int main() {
    Resume resume;

    read_resume(&resume);
    print_resume(&resume);

    return 0;
}