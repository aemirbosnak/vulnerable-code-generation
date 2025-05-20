//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
// Welcome to the C Resume Parsing System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_RESUME_SIZE 5000 // Maximum size of resume
#define MAX_NAME_SIZE 50 // Maximum length of name
#define MAX_SKILLS 10 // Maximum number of skills

// Define structures
typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    char email[MAX_NAME_SIZE];
    char phone[MAX_NAME_SIZE];
    char address[MAX_RESUME_SIZE];
    char skills[MAX_SKILLS][MAX_RESUME_SIZE];
} Resume;

// Define functions
void parseResume(char *fileName, Resume *resume);
void printResume(Resume resume);

int main() {
    // Declare variables
    Resume resume;
    char fileName[MAX_RESUME_SIZE];

    // Ask user for file name
    printf("Welcome to the C Resume Parsing System!\n");
    printf("Please enter the name of the resume file: ");
    scanf("%s", fileName);

    // Parse resume and print information
    parseResume(fileName, &resume);
    printResume(resume);

    return 0;
}

void parseResume(char *fileName, Resume *resume) {
    // Declare variables
    FILE *file;
    char line[MAX_RESUME_SIZE];
    int lineNum = 1;

    // Open file
    file = fopen(fileName, "r");

    if (file == NULL) {
        // Error handling
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_RESUME_SIZE, file)) {
        char *pos;

        // Remove newline character at end of line
        pos = strchr(line, '\n');
        if (pos) {
            *pos = '\0';
        }

        // Parse line based on line number
        switch (lineNum) {
            case 1:
                // Parse name
                strcpy(resume->name, line);
                break;
            case 2:
                // Parse age
                resume->age = atoi(line);
                break;
            case 3:
                // Parse email
                strcpy(resume->email, line);
                break;
            case 4:
                // Parse phone
                strcpy(resume->phone, line);
                break;
            case 5:
                // Parse address
                strcpy(resume->address, line);
                break;
            default:
                // Parse skills
                if (lineNum - 5 <= MAX_SKILLS) {
                    strcpy(resume->skills[lineNum - 6], line);
                }
                break;
        }

        lineNum++;
    }

    // Close file
    fclose(file);
}

void printResume(Resume resume) {
    // Print information
    printf("\nResume Information:\n");
    printf("- Name: %s\n", resume.name);
    printf("- Age: %d\n", resume.age);
    printf("- Email: %s\n", resume.email);
    printf("- Phone: %s\n", resume.phone);
    printf("- Address: %s\n", resume.address);
    printf("- Skills:\n");

    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(resume.skills[i]) > 0) {
            printf("  - %s\n", resume.skills[i]);
        }
    }
}