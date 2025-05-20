//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Define the structure for storing resume information
typedef struct Resume {
    char name[MAX_BUFFER];
    char email[MAX_BUFFER];
    char phone[MAX_BUFFER];
    char address[MAX_BUFFER];
    char education[MAX_BUFFER];
    char experience[MAX_BUFFER];
} Resume;

// Define the function for parsing resumes
Resume parseResume(char* filename) {
    Resume resume;
    char buffer[MAX_BUFFER];

    // Open the file for reading
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Parse each line of the resume file
    while (fgets(buffer, MAX_BUFFER, fp)) {
        if (strstr(buffer, "Name:")) {
            strcpy(resume.name, buffer + strlen("Name:"));
            resume.name[strlen(resume.name) - 1] = '\0'; // remove newline character
        }
        else if (strstr(buffer, "Email:")) {
            strcpy(resume.email, buffer + strlen("Email:"));
            resume.email[strlen(resume.email) - 1] = '\0'; // remove newline character
        }
        else if (strstr(buffer, "Phone:")) {
            strcpy(resume.phone, buffer + strlen("Phone:"));
            resume.phone[strlen(resume.phone) - 1] = '\0'; // remove newline character
        }
        else if (strstr(buffer, "Address:")) {
            strcpy(resume.address, buffer + strlen("Address:"));
            resume.address[strlen(resume.address) - 1] = '\0'; // remove newline character
        }
        else if (strstr(buffer, "Education:")) {
            strcpy(resume.education, buffer + strlen("Education:"));
            resume.education[strlen(resume.education) - 1] = '\0'; // remove newline character
        }
        else if (strstr(buffer, "Experience:")) {
            strcpy(resume.experience, buffer + strlen("Experience:"));
            resume.experience[strlen(resume.experience) - 1] = '\0'; // remove newline character
        }
    }

    // Close the file
    fclose(fp);

    // Return the parsed resume
    return resume;
}

// Define the main function for testing
int main() {
    char filename[MAX_BUFFER];
    printf("Enter the name of the resume file to parse: ");
    fgets(filename, MAX_BUFFER, stdin);
    filename[strlen(filename) - 1] = '\0'; // remove newline character

    // Parse the resume file
    Resume resume = parseResume(filename);

    // Print the parsed resume information
    printf("\nName: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}