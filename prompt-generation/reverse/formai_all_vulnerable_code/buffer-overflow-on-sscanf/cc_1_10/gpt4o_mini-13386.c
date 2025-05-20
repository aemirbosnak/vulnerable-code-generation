//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_NAME_LENGTH];
    int skill_count;
} Resume;

void printResume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
}

int parseLine(char *line, Resume *resume) {
    if (strncmp(line, "Name:", 5) == 0) {
        sscanf(line + 5, "%[^\n]", resume->name);
    } else if (strncmp(line, "Email:", 6) == 0) {
        sscanf(line + 6, "%[^\n]", resume->email);
    } else if (strncmp(line, "Phone:", 6) == 0) {
        sscanf(line + 6, "%[^\n]", resume->phone);
    } else if (strncmp(line, "Skill:", 6) == 0) {
        if (resume->skill_count < MAX_SKILLS) {
            sscanf(line + 6, "%[^\n]", resume->skills[resume->skill_count]);
            resume->skill_count++;
        } else {
            printf("Maximum skill limit reached!\n");
        }
    } else {
        return 0;  // Unrecognized line
    }
    return 1;  // Successfully parsed a line
}

void parseResumeFile(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    // Initialize the resume structure
    resume->skill_count = 0;
    memset(resume->name, 0, sizeof(resume->name));
    memset(resume->email, 0, sizeof(resume->email));
    memset(resume->phone, 0, sizeof(resume->phone));
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (!parseLine(line, resume)) {
            printf("Ignoring unrecognized line: %s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume resume;
    parseResumeFile(argv[1], &resume);
    printResume(&resume);

    return EXIT_SUCCESS;
}