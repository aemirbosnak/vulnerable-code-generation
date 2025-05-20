//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000

// Struct to hold resume data
typedef struct {
    char name[50];
    char address[100];
    char email[50];
    char phone[15];
    int experience;
    int education;
} Resume;

// Function to parse resume data
void parseResume(Resume* resume, char* input) {
    // Clear the resume struct
    memset(resume, 0, sizeof(Resume));

    // Parse name
    char* name = strtok(input, ",");
    strncpy(resume->name, name, sizeof(resume->name));

    // Parse address
    char* address = strtok(NULL, ",");
    strncpy(resume->address, address, sizeof(resume->address));

    // Parse email
    char* email = strtok(NULL, ",");
    strncpy(resume->email, email, sizeof(resume->email));

    // Parse phone number
    char* phone = strtok(NULL, ",");
    strncpy(resume->phone, phone, sizeof(resume->phone));

    // Parse experience
    char* experienceStr = strtok(NULL, ",");
    resume->experience = atoi(experienceStr);

    // Parse education
    char* educationStr = strtok(NULL, ",");
    resume->education = atoi(educationStr);
}

// Function to print resume data
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Address: %s\n", resume->address);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Experience: %d\n", resume->experience);
    printf("Education: %d\n", resume->education);
}

// Main function
int main() {
    char input[MAX_RESUME_SIZE];

    // Prompt user to enter resume data
    printf("Enter resume data in the following format:\n");
    printf("Name,Address,Email,Phone,Experience,Education\n");
    printf("Press enter to submit:\n");

    // Read input from user
    fgets(input, MAX_RESUME_SIZE, stdin);

    // Parse resume data
    Resume resume;
    parseResume(&resume, input);

    // Print resume data
    printResume(&resume);

    return 0;
}