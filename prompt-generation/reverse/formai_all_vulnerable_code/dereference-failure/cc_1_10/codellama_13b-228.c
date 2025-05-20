//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: protected
/*
 * C Resume Parsing System
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store information about a resume
typedef struct {
    char name[50];
    char email[50];
    char phone[50];
    char experience[100];
    char education[50];
    char skills[50];
} Resume;

// Function to parse a resume and extract information
void parseResume(char* resumeText, Resume* resume) {
    // Initialize variables
    char* name = NULL;
    char* email = NULL;
    char* phone = NULL;
    char* experience = NULL;
    char* education = NULL;
    char* skills = NULL;

    // Split the resume text into lines
    char* line = strtok(resumeText, "\n");
    while (line != NULL) {
        // Check for name
        if (strstr(line, "Name:") != NULL) {
            name = line + 5;
        }
        // Check for email
        if (strstr(line, "Email:") != NULL) {
            email = line + 6;
        }
        // Check for phone
        if (strstr(line, "Phone:") != NULL) {
            phone = line + 6;
        }
        // Check for experience
        if (strstr(line, "Experience:") != NULL) {
            experience = line + 10;
        }
        // Check for education
        if (strstr(line, "Education:") != NULL) {
            education = line + 9;
        }
        // Check for skills
        if (strstr(line, "Skills:") != NULL) {
            skills = line + 6;
        }

        // Move to next line
        line = strtok(NULL, "\n");
    }

    // Set the resume information
    strcpy(resume->name, name);
    strcpy(resume->email, email);
    strcpy(resume->phone, phone);
    strcpy(resume->experience, experience);
    strcpy(resume->education, education);
    strcpy(resume->skills, skills);
}

// Main function
int main() {
    // Read the resume text from a file
    char resumeText[1000];
    FILE* file = fopen("resume.txt", "r");
    fread(resumeText, sizeof(char), 1000, file);
    fclose(file);

    // Initialize the resume structure
    Resume resume;
    parseResume(resumeText, &resume);

    // Print the resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}