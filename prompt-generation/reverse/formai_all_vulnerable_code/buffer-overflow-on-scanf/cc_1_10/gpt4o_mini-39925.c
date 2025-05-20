//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char skills[MAX_LENGTH];
    int experience; // in years
} Resume;

void inputResume(Resume *resume) {
    printf("Enter Name: ");
    fgets(resume->name, MAX_LENGTH, stdin);
    resume->name[strcspn(resume->name, "\n")] = '\0'; // Remove newline

    printf("Enter Email: ");
    fgets(resume->email, MAX_LENGTH, stdin);
    resume->email[strcspn(resume->email, "\n")] = '\0'; // Remove newline

    printf("Enter Skills (comma-separated): ");
    fgets(resume->skills, MAX_LENGTH, stdin);
    resume->skills[strcspn(resume->skills, "\n")] = '\0'; // Remove newline

    printf("Enter Experience (in years): ");
    scanf("%d", &resume->experience);
    getchar(); // Consume newline character left by scanf
}

void displayResume(const Resume *resume) {
    printf("\n--- Resume ---\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %d years\n", resume->experience);
}

void parseResumes(Resume resumes[], int *resumeCount) {
    int n;
    printf("How many resumes would you like to enter (max %d)? ", MAX_RESUMES);
    scanf("%d", &n);
    getchar(); // Consume newline

    if (n > MAX_RESUMES) {
        n = MAX_RESUMES;
        printf("Limiting to %d resumes.\n", MAX_RESUMES);
    }

    for (int i = 0; i < n; i++) {
        printf("\n* Inputting Resume %d *\n", i + 1);
        inputResume(&resumes[*resumeCount]);
        (*resumeCount)++;
    }
}

void sortResumesByExperience(Resume resumes[], int resumeCount) {
    for (int i = 0; i < resumeCount - 1; i++) {
        for (int j = 0; j < resumeCount - i - 1; j++) {
            if (resumes[j].experience < resumes[j + 1].experience) {
                Resume temp = resumes[j];
                resumes[j] = resumes[j + 1];
                resumes[j + 1] = temp;
            }
        }
    }
}

void searchBySkill(const Resume resumes[], int resumeCount, const char *skill) {
    printf("\n--- Searching for skill: %s ---\n", skill);
    for (int i = 0; i < resumeCount; i++) {
        if (strstr(resumes[i].skills, skill) != NULL) {
            displayResume(&resumes[i]);
        }
    }
}

int main() {
    Resume resumes[MAX_RESUMES];
    int resumeCount = 0;
    
    parseResumes(resumes, &resumeCount);
    
    printf("\n--- Resumes Entered ---\n");
    for (int i = 0; i < resumeCount; i++) {
        displayResume(&resumes[i]);
    }

    sortResumesByExperience(resumes, resumeCount);
    printf("\n--- Resumes Sorted by Experience ---\n");
    for (int i = 0; i < resumeCount; i++) {
        displayResume(&resumes[i]);
    }

    char skill[MAX_LENGTH];
    printf("\nEnter a skill to search for: ");
    fgets(skill, MAX_LENGTH, stdin);
    skill[strcspn(skill, "\n")] = '\0'; // Remove newline

    searchBySkill(resumes, resumeCount, skill);
    return 0;
}