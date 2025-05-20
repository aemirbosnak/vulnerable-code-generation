//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the resume

// Structure to hold the parsed information
typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    char education[200];
    char experience[200];
} Resume;

// Function to read the resume from a file
Resume readResume(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    Resume resume;
    char line[MAX_SIZE];

    // Read the name
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.name, line);

    // Read the email
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.email, line);

    // Read the phone number
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.phone, line);

    // Read the address
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.address, line);

    // Read the education
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.education, line);

    // Read the experience
    fgets(line, MAX_SIZE, fp);
    strcpy(resume.experience, line);

    fclose(fp);
    return resume;
}

// Function to print the parsed information
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
    char filename[100];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    Resume resume = readResume(filename);
    printResume(resume);

    return 0;
}