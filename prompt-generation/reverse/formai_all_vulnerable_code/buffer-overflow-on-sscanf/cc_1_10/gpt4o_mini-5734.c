//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1024

typedef struct {
    char name[50];
    char email[100];
    char phone[20];
    char skills[200];
    char education[100];
    char experience[300];
} Resume;

// Function to parse a resume
int parseResume(const char *resumeText, Resume *resume) {
    // Scan for name
    sscanf(resumeText, "Name: %[^\n]\n", resume->name);
    // Scan for email
    sscanf(strstr(resumeText, "Email:") + strlen("Email:"), " %s\n", resume->email);
    // Scan for phone
    sscanf(strstr(resumeText, "Phone:") + strlen("Phone:"), " %s\n", resume->phone);
    // Scan for skills
    sscanf(strstr(resumeText, "Skills:") + strlen("Skills:"), " %[^\n]\n", resume->skills);
    // Scan for education
    sscanf(strstr(resumeText, "Education:") + strlen("Education:"), " %[^\n]\n", resume->education);
    // Scan for experience
    sscanf(strstr(resumeText, "Experience:") + strlen("Experience:"), " %[^\n]\n", resume->experience);

    return 1; // return success
}

// Function to print a parsed resume
void printResume(const Resume *resume) {
    printf("Parsed Resume:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Function to read resumes from a file
int readResumes(const char *filename, Resume resumes[], int max_resumes) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char buffer[MAX_LENGTH];
    int resume_count = 0;

    while (fgets(buffer, MAX_LENGTH, file) && resume_count < max_resumes) {
        Resume resume;
        if (parseResume(buffer, &resume)) {
            resumes[resume_count++] = resume;
        }
    }

    fclose(file);
    return resume_count;
}

// Main function
int main(void) {
    Resume resumes[MAX_RESUMES];
    
    // Display a whimsical welcome message
    printf("Welcome to the Curiously Clever Resume Parser!\n\n");
    
    // Assume the resumes are stored in 'resumes.txt'
    const char *filename = "resumes.txt";

    int totalResumes = readResumes(filename, resumes, MAX_RESUMES);
    if (totalResumes < 0) {
        return 1;
    }

    // Display total resumes parsed
    printf("Total resumes parsed: %d\n\n", totalResumes);

    // Print each parsed resume
    for (int i = 0; i < totalResumes; i++) {
        printResume(&resumes[i]);
        printf("\n---------------------------------------------------\n");
    }

    // Curious farewell message
    printf("Thank you for using the Curious Resume Parser! Happy hiring!\n");

    return 0;
}