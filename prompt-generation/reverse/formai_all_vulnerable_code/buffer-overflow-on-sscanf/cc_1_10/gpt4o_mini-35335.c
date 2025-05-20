//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_CONTACT_LENGTH 100
#define MAX_SKILLS_LENGTH 500
#define MAX_EDUCATION_LENGTH 500
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
} Resume;

void parseResume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int section = 0; // 0: name, 1: contact, 2: skills, 3: education

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            section = 0;
            sscanf(line + 5, "%[^\n]", resume->name);
        } else if (strncmp(line, "Contact:", 8) == 0) {
            section = 1;
            sscanf(line + 8, "%[^\n]", resume->contact);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            section = 2;
            fgets(line, sizeof(line), file); // Read the next line for skills
            sscanf(line, "%[^\n]", resume->skills);
        } else if (strncmp(line, "Education:", 10) == 0) {
            section = 3;
            fgets(line, sizeof(line), file); // Read the next line for education
            sscanf(line, "%[^\n]", resume->education);
        }
    }

    fclose(file);
}

void displayResume(const Resume *resume) {
    printf("----- Resume -----\n");
    printf("Name: %s\n", resume->name);
    printf("Contact: %s\n", resume->contact);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("------------------\n");
}

int main() {
    Resume resume;
    memset(&resume, 0, sizeof(Resume)); // Initialize resume

    const char *filename = "sample_resume.txt";
    parseResume(filename, &resume);
    displayResume(&resume);

    return 0;
}