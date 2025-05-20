//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: immersive
/*
 * C Resume Parsing System
 *
 * This program takes a resume in plain text format and extracts
 * relevant information such as name, email, phone number, and
 * experience. It also provides a summary of the resume and
 * highlights the candidate's skills and qualifications.
 */

#include <stdio.h>
#include <string.h>

// Structures for storing resume data
struct Resume {
    char name[100];
    char email[100];
    char phone[100];
    char experience[1000];
    char skills[1000];
};

// Function to extract information from a resume
void parseResume(struct Resume *resume, char *resumeText) {
    // Extract name, email, and phone number
    char *name = strtok(resumeText, "\n");
    char *email = strtok(NULL, "\n");
    char *phone = strtok(NULL, "\n");

    // Extract experience and skills
    char *experience = strtok(NULL, "\n");
    char *skills = strtok(NULL, "\n");

    // Save extracted information in resume structure
    strcpy(resume->name, name);
    strcpy(resume->email, email);
    strcpy(resume->phone, phone);
    strcpy(resume->experience, experience);
    strcpy(resume->skills, skills);
}

// Function to print a summary of the resume
void printSummary(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    // Declare a resume structure
    struct Resume resume;

    // Get resume text from user
    char resumeText[1000];
    printf("Enter resume text: ");
    fgets(resumeText, 1000, stdin);

    // Parse resume text and save information in resume structure
    parseResume(&resume, resumeText);

    // Print summary of resume
    printSummary(&resume);

    return 0;
}