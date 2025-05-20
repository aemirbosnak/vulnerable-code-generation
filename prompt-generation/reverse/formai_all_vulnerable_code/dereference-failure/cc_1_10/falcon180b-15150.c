//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store parsed resume data
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char education[100];
    char experience[100];
} Resume;

// Function to parse resume data
void parseResume(Resume *resume, char *data) {
    char *token = strtok(data, "\n");
    while (token!= NULL) {
        if (strcmp(token, "Name:") == 0) {
            strcpy(resume->name, strtok(NULL, "\n"));
        } else if (strcmp(token, "Email:") == 0) {
            strcpy(resume->email, strtok(NULL, "\n"));
        } else if (strcmp(token, "Phone:") == 0) {
            strcpy(resume->phone, strtok(NULL, "\n"));
        } else if (strcmp(token, "Address:") == 0) {
            strcpy(resume->address, strtok(NULL, "\n"));
        } else if (strcmp(token, "Education:") == 0) {
            strcpy(resume->education, strtok(NULL, "\n"));
        } else if (strcmp(token, "Experience:") == 0) {
            strcpy(resume->experience, strtok(NULL, "\n"));
        }
        token = strtok(NULL, "\n");
    }
}

// Function to print parsed resume data
void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function to test resume parsing
int main() {
    char *data = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 555-1234\nAddress: 123 Main St.\nEducation: B.S. in Computer Science\nExperience: 5 years in software development\n";
    Resume resume;
    parseResume(&resume, data);
    printResume(&resume);
    return 0;
}