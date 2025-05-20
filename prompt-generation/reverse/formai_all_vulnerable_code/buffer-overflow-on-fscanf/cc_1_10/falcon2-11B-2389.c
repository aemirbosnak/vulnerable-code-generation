//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the parsed resume information
typedef struct {
    char name[100];
    char email[100];
    char phone[20];
} Resume;

// Define a function to parse the resume file
Resume* parseResume(FILE* resumeFile) {
    Resume* resume = (Resume*)malloc(sizeof(Resume));
    
    // Read the name, email, and phone number from the resume file
    fscanf(resumeFile, "%s %s %s", resume->name, resume->email, resume->phone);
    
    // Return the parsed resume information
    return resume;
}

// Define a function to print the parsed resume information to the console
void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
}

// Main function
int main() {
    FILE* resumeFile = fopen("resume.txt", "r");
    
    if (resumeFile == NULL) {
        printf("Error opening resume file.\n");
        return 1;
    }
    
    // Parse the resume file
    Resume* parsedResume = parseResume(resumeFile);
    
    // Print the parsed resume information to the console
    printResume(parsedResume);
    
    // Free the memory allocated for the parsed resume information
    free(parsedResume);
    
    // Close the resume file
    fclose(resumeFile);
    
    return 0;
}