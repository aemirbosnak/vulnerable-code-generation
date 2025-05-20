//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a resume.
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[15];
    char skills[200];
} Resume;

// Function to parse a resume.
Resume parseResume(char* resumeText) {
    Resume resume;
    char* token;

    // Find name.
    token = strtok(resumeText, "\n");
    sscanf(token, "Name: %[^\n]s", resume.name);

    // Find email.
    token = strtok(NULL, "\n");
    sscanf(token, "Email: %[^\n]s", resume.email);

    // Find phone number.
    token = strtok(NULL, "\n");
    sscanf(token, "Phone: %[^\n]s", resume.phone);

    // Find skills.
    token = strtok(NULL, "\n");
    sscanf(token, "Skills: %[^\n]s", resume.skills);

    return resume;
}

int main() {
    char resumeText[1000];

    // Prompt user for resume text.
    printf("Enter resume text:\n");
    fgets(resumeText, 1000, stdin);

    // Parse the resume.
    Resume resume = parseResume(resumeText);

    // Display the parsed information.
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);

    return 0;
}