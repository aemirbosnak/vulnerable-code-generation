//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the parsed resume information
typedef struct {
    char name[100];
    char contact[100];
    char education[100];
    char work_experience[100];
    char skills[100];
} Resume;

// Function to parse the resume and populate the Resume structure
void parse_resume(FILE* file, Resume* resume) {
    // Read the name from the file
    fscanf(file, "%s", resume->name);
    
    // Read the contact information from the file
    fscanf(file, "%s", resume->contact);
    
    // Read the education information from the file
    fscanf(file, "%s", resume->education);
    
    // Read the work experience information from the file
    fscanf(file, "%s", resume->work_experience);
    
    // Read the skills information from the file
    fscanf(file, "%s", resume->skills);
}

// Function to print the parsed resume information
void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Contact: %s\n", resume.contact);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);
    printf("Skills: %s\n", resume.skills);
}

// Main function
int main() {
    // Open the resume file for reading
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Create a Resume structure to hold the parsed information
    Resume resume;
    
    // Parse the resume and populate the Resume structure
    parse_resume(file, &resume);
    
    // Print the parsed resume information
    print_resume(resume);
    
    // Close the file
    fclose(file);
    
    return 0;
}