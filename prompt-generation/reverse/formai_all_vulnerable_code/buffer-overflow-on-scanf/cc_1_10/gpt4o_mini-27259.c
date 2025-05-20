//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to hold information of a resume
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char skills[200];
    char experience[500];
} Resume;

// Function declarations
void parseResume(const char *filename, Resume *resume);
void printResume(const Resume *resume);

// Main function - where the magic begins!
int main() {
    printf("!!!! Welcome to the SHOCKING Resume Parsing System !!!!\n");

    Resume myResume;
    char filename[100];

    // Ask for the file name
    printf("Please enter the name of the resume file to parse (e.g., resume.txt): ");
    scanf("%s", filename);

    // Parse the resume from the file
    parseResume(filename, &myResume);

    // Print the resume details
    printf("\n@@@ Parsed Resume Details @@@\n");
    printResume(&myResume);

    return 0;
}

// Function to parse the resume, line by line
void parseResume(const char *filename, Resume *resume) {
    printf("Parsing the filename: %s...\n", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "!!! Error: Could not open file %s !!!\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[256];

    // Reading each line and extracting data
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") != NULL) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } 
        else if (strstr(line, "Email:") != NULL) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } 
        else if (strstr(line, "Phone:") != NULL) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } 
        else if (strstr(line, "Skills:") != NULL) {
            sscanf(line, "Skills: %[^\n]", resume->skills);
        } 
        else if (strstr(line, "Experience:") != NULL) {
            sscanf(line, "Experience: %[^\n]", resume->experience);
        }
    }

    fclose(file);
    printf("Parsing complete! All details have been extracted! 😱\n");
}

// Function to display the parsed resume
void printResume(const Resume *resume) {
    printf("===================================================\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("===================================================\n");
}