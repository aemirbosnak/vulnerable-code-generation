//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LINE_LENGTH 256
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100
#define PHONE_LENGTH 20
#define SKILLS_LENGTH 200

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char phone[PHONE_LENGTH];
    char skills[SKILLS_LENGTH];
} Resume;

void parse_resume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->phone);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            sscanf(line + 7, "%[^\n]", resume->skills);
        }
    }

    fclose(file);
}

void print_resume(const Resume *resume) {
    printf("Resume Details:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
}

void sort_resumes_by_name(Resume resumes[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (strcmp(resumes[j].name, resumes[j + 1].name) > 0) {
                Resume temp = resumes[j];
                resumes[j] = resumes[j + 1];
                resumes[j + 1] = temp;
            }
        }
    }
}

void save_resume_to_file(Resume *resume, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fprintf(file, "Name: %s\n", resume->name);
    fprintf(file, "Email: %s\n", resume->email);
    fprintf(file, "Phone: %s\n", resume->phone);
    fprintf(file, "Skills: %s\n", resume->skills);

    fclose(file);
}

int main() {
    Resume resumes[MAX_RESUMES];
    int count = 0;

    // Loading resumes from files
    for (int i = 1; i <= MAX_RESUMES; ++i) {
        char filename[20];
        snprintf(filename, sizeof(filename), "resume_%d.txt", i);
        parse_resume(filename, &resumes[count]);
        count++;
    }

    // Display all resumes
    for (int i = 0; i < count; ++i) {
        print_resume(&resumes[i]);
    }

    // Sort resumes by name
    sort_resumes_by_name(resumes, count);

    printf("\nSorted Resumes by Name:\n");
    for (int i = 0; i < count; ++i) {
        print_resume(&resumes[i]);
    }

    // Save the first resume to a new file
    save_resume_to_file(&resumes[0], "selected_resume.txt");

    return 0;
}