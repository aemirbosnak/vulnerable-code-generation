//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESUMES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[5][30]; // Limiting to 5 skills
    int skill_count;
} Resume;

// Function declarations
void parseResume(const char *filename, Resume *resume);
void printResume(const Resume *resume);
void searchSkill(const Resume *resumes, int count, const char *skill);
void displayAllResumes(const Resume *resumes, int count);

int main() {
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;
    char fileName[MAX_LINE_LENGTH];
    char searchTerm[30];

    printf("Welcome to the Future Resume Parsing System!\n");
    printf("Enter the filename containing resumes to parse: ");
    scanf("%s", fileName);

    // Open the file containing resumes
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", fileName);
        return 1;
    }

    // Read resumes from file until EOF
    while (fscanf(file, "%s", resumes[resumeCount].name) != EOF) {
        parseResume(fileName, &resumes[resumeCount]);
        resumeCount++;
        if (resumeCount >= MAX_RESUMES) {
            printf("Maximum resume capacity reached.\n");
            break;
        }
    }
    fclose(file);

    // Display all parsed resumes
    displayAllResumes(resumes, resumeCount);

    printf("Enter a skill to search for: ");
    scanf("%s", searchTerm);
    searchSkill(resumes, resumeCount, searchTerm);
    
    return 0;
}

void parseResume(const char *filename, Resume *resume) {
    char line[MAX_LINE_LENGTH];
    resume->skill_count = 0;

    // Simulating reading different aspects of a resume
    // Here we would read lines meant for specific fields
    while (fgets(line, sizeof(line), stdin)) {
        if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line + 6, "%s", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line + 6, "%s", resume->phone);
        } else if (strncmp(line, "Skill:", 6) == 0 && resume->skill_count < 5) {
            sscanf(line + 6, "%s", resume->skills[resume->skill_count]);
            resume->skill_count++;
        } else if (line[0] == '\n') {
            break; // End of the current resume
        }
    }
}

void printResume(const Resume *resume) {
    printf("\n=== Resume ===\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s ", resume->skills[i]);
    }
    printf("\n");
}

void searchSkill(const Resume *resumes, int count, const char *skill) {
    printf("\nSearching for skill: %s\n", skill);
    bool found = false;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < resumes[i].skill_count; j++) {
            if (strcmp(resumes[i].skills[j], skill) == 0) {
                printResume(&resumes[i]);
                found = true;
                break; // Skill found, no need to continue checking other skills for this resume
            }
        }
    }
    if (!found) {
        printf("No resumes found with the skill: %s\n", skill);
    }
}

void displayAllResumes(const Resume *resumes, int count) {
    printf("\nDisplaying all resumes...\n");
    for (int i = 0; i < count; i++) {
        printResume(&resumes[i]);
    }
}