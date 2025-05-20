//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char skills[500];
    char education[200];
    char experience[500];
} Resume;

Resume resumes[MAX_RESUMES];
int resumeCount = 0;

// Function to parse a resume from a given string
void parseResume(const char* resumeData) {
    Resume resume;

    // Parse Name
    sscanf(resumeData, "Name: %[^\n]\n", resume.name);
    
    // Parse Email
    sscanf(resumeData, "Email: %[^\n]\n", resume.email);
    
    // Parse Phone
    sscanf(resumeData, "Phone: %[^\n]\n", resume.phone);
    
    // Parse Skills
    sscanf(resumeData, "Skills: %[^\n]\n", resume.skills);
    
    // Parse Education
    sscanf(resumeData, "Education: %[^\n]\n", resume.education);
    
    // Parse Experience
    sscanf(resumeData, "Experience: %[^\n]\n", resume.experience);

    // Store the parsed resume
    resumes[resumeCount++] = resume;
}

// Function to display a resume
void displayResume(const Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("\n");
}

// Function to read resumes from a file
void readResumesFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];
    char resumeData[MAX_LENGTH * 6]; // Considering multiple resumes
    int isReadingResume = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strcmp(line, "\n") == 0) {
            if (isReadingResume) {
                parseResume(resumeData);
                memset(resumeData, 0, sizeof(resumeData)); // Reset for next resume
                isReadingResume = 0;
            }
        } else {
            strcat(resumeData, line);
            isReadingResume = 1;
        }
    }

    // Parse the last resume if the file doesn't end with a newline
    if (isReadingResume) {
        parseResume(resumeData);
    }

    fclose(file);
}

// Function to search resumes by skill
void searchBySkill(const char* skill) {
    printf("Searching for resumes with skill: %s\n", skill);
    for (int i = 0; i < resumeCount; i++) {
        if (strstr(resumes[i].skills, skill) != NULL) {
            printf("Resume #%d:\n", i + 1);
            displayResume(&resumes[i]);
        }
    }
}

// Function to display all resumes
void displayAllResumes() {
    printf("Displaying all resumes:\n");
    for (int i = 0; i < resumeCount; i++) {
        printf("Resume #%d:\n", i + 1);
        displayResume(&resumes[i]);
    }
}

int main() {
    readResumesFromFile("resumes.txt");

    int choice;
    char skill[100];

    while (1) {
        printf("Resume Parsing System\n");
        printf("1. Display All Resumes\n");
        printf("2. Search Resumes by Skill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        switch (choice) {
            case 1:
                displayAllResumes();
                break;
            case 2:
                printf("Enter skill to search: ");
                fgets(skill, sizeof(skill), stdin);
                skill[strcspn(skill, "\n")] = 0; // Remove trailing newline character
                searchBySkill(skill);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}