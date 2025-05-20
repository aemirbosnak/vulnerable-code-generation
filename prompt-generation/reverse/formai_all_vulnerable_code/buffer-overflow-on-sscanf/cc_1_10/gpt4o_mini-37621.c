//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 500

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char education[100];
    char experience[200];
} Resume;

void parseResume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Oops! Could not open the file: %s\n", filename);
        exit(1);
    }

    // We will read the content line by line
    char line[MAX_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name: ", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->name);
        } else if (strncmp(line, "Email: ", 7) == 0) {
            sscanf(line + 7, "%[^\n]", resume->email);
        } else if (strncmp(line, "Phone: ", 7) == 0) {
            sscanf(line + 7, "%[^\n]", resume->phone);
        } else if (strncmp(line, "Education: ", 12) == 0) {
            sscanf(line + 12, "%[^\n]", resume->education);
        } else if (strncmp(line, "Experience: ", 12) == 0) {
            sscanf(line + 12, "%[^\n]", resume->experience);
        }
    }
    fclose(file);
}

void displayResume(const Resume *resume) {
    printf("****** Resume ******\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("********************\n");
}

int main() {
    printf("Welcome to the Ultimate Resume Parsing System!\n");
    Resume resumes[MAX_RESUMES];
    int count = 0;

    // Assume we're reading multiple resumes from files
    char *resumeFiles[] = {"resume1.txt", "resume2.txt", "resume3.txt"};
    int fileCount = sizeof(resumeFiles) / sizeof(resumeFiles[0]);

    for (int i = 0; i < fileCount; i++) {
        printf("\nParsing resume from: %s\n", resumeFiles[i]);
        parseResume(resumeFiles[i], &resumes[count]);
        count++;
    }

    printf("\nParsed Resumes:\n");
    for (int i = 0; i < count; i++) {
        displayResume(&resumes[i]);
    }

    return 0;
}