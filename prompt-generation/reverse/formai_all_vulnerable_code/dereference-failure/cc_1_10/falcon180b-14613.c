//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LENGTH 100

// Struct to store resume data
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char address[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
} Resume;

// Function to parse resume data
Resume parseResume(char* data) {
    Resume resume;
    char* token;
    char* field = data;

    // Extract name
    token = strtok(field, ",");
    strcpy(resume.name, token);
    field = NULL;

    // Extract address
    token = strtok(field, ",");
    strcpy(resume.address, token);
    field = NULL;

    // Extract phone
    token = strtok(field, ",");
    strcpy(resume.phone, token);
    field = NULL;

    // Extract email
    token = strtok(field, ",");
    strcpy(resume.email, token);
    field = NULL;

    // Extract education
    token = strtok(field, ",");
    strcpy(resume.education, token);
    field = NULL;

    // Extract experience
    token = strtok(field, ",");
    strcpy(resume.experience, token);
    field = NULL;

    return resume;
}

// Function to print resume data
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Usage: %s <resume_data>\n", argv[0]);
        return 1;
    }

    char* data = argv[1];
    Resume resume = parseResume(data);
    printResume(resume);

    return 0;
}