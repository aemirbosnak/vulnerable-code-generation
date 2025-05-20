//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the resume data
typedef struct {
    char name[50];
    char email[100];
    char phone[20];
    char address[200];
    char education[200];
    char experience[500];
} Resume;

// Function to parse the resume data from a text file
Resume parseResume(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    Resume resume;
    char line[200];
    char* token;

    // Read the name
    fgets(line, 200, fp);
    strcpy(resume.name, line);

    // Read the email
    fgets(line, 200, fp);
    strcpy(resume.email, line);

    // Read the phone number
    fgets(line, 200, fp);
    strcpy(resume.phone, line);

    // Read the address
    fgets(line, 200, fp);
    strcpy(resume.address, line);

    // Read the education
    fgets(line, 200, fp);
    strcpy(resume.education, line);

    // Read the experience
    fgets(line, 200, fp);
    strcpy(resume.experience, line);

    fclose(fp);
    return resume;
}

// Function to print the resume data
void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

// Main function
int main() {
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    Resume resume = parseResume(filename);
    printResume(resume);

    return 0;
}