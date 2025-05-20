//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 128
#define MAX_EMAIL_LENGTH 128
#define MAX_PHONE_LENGTH 16

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[10][50];
    int skill_count;
} Resume;

// Function prototypes
void parseResume(const char *filename, Resume *resume);
void displayResume(const Resume *resume);
void freeSkills(Resume *resume);

int main() {
    Resume resumes[MAX_RESUMES];
    char filename[50];
    int count = 0;
    
    printf("Resume Parsing System\n");
    printf("======================\n");
    
    while (count < MAX_RESUMES) {
        printf("Enter the filename of resume %d (or 'exit' to quit): ", count + 1);
        scanf("%s", filename);
        
        if (strcmp(filename, "exit") == 0) {
            break;
        }
        
        parseResume(filename, &resumes[count]);
        count++;
    }
    
    printf("\nParsed Resumes:\n");
    for (int i = 0; i < count; i++) {
        displayResume(&resumes[i]);
        printf("-----------------------\n");
    }
    
    return 0;
}

void parseResume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    resume->skill_count = 0;
    
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line + 6, "%[^\n]", resume->phone);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            char *token = strtok(line + 7, ",");
            while (token && resume->skill_count < 10) {
                sscanf(token, "%[^\n]", resume->skills[resume->skill_count]);
                resume->skill_count++;
                token = strtok(NULL, ",");
            }
        }
    }
    
    fclose(file);
}

void displayResume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s", resume->skills[i]);
        if (i < resume->skill_count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}