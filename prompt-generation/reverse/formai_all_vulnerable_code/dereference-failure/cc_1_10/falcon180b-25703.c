//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a resume
typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char education[200];
    char experience[500];
} Resume;

// Function to parse a resume
Resume parseResume(char* resumeText) {
    Resume result;
    char* token = strtok(resumeText, "\n");
    while (token!= NULL) {
        if (strcmp(token, "Name:") == 0) {
            strcpy(result.name, strtok(NULL, "\n"));
        } else if (strcmp(token, "Email:") == 0) {
            strcpy(result.email, strtok(NULL, "\n"));
        } else if (strcmp(token, "Phone:") == 0) {
            strcpy(result.phone, strtok(NULL, "\n"));
        } else if (strcmp(token, "Education:") == 0) {
            strcpy(result.education, strtok(NULL, "\n"));
        } else if (strcmp(token, "Experience:") == 0) {
            strcpy(result.experience, strtok(NULL, "\n"));
        }
        token = strtok(NULL, "\n");
    }
    return result;
}

// Function to print a resume
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main() {
    char* resumeText = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 555-1234\nEducation: BS in Computer Science from Surreal University\nExperience: 5 years of programming in the dream world\n";
    Resume resume = parseResume(resumeText);
    printResume(resume);
    return 0;
}