//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

void parseResume(const char *fileName, Resume *resume) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "Name:", 5) == 0) {
            sscanf(buffer + 5, "%[^\n]", resume->name);
        } else if (strncmp(buffer, "Email:", 6) == 0) {
            sscanf(buffer + 6, "%[^\n]", resume->email);
        } else if (strncmp(buffer, "Phone:", 6) == 0) {
            sscanf(buffer + 6, "%[^\n]", resume->phone);
        } else if (strncmp(buffer, "Skills:", 7) == 0) {
            sscanf(buffer + 7, "%[^\n]", resume->skills);
        }
    }

    fclose(file);
}

void printResume(const Resume *resume) {
    printf("Resume Details:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
}

void saveResume(const Resume *resume, const char *outputFileName) {
    FILE *file = fopen(outputFileName, "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", outputFileName);
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Name: %s\n", resume->name);
    fprintf(file, "Email: %s\n", resume->email);
    fprintf(file, "Phone: %s\n", resume->phone);
    fprintf(file, "Skills: %s\n", resume->skills);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_resume_file> <output_resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume resume;
    memset(&resume, 0, sizeof(Resume));

    parseResume(argv[1], &resume);
    printResume(&resume);
    saveResume(&resume, argv[2]);

    return EXIT_SUCCESS;
}