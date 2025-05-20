//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
// C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a candidate
struct Candidate {
    char name[50];
    char email[50];
    char phone[20];
    char experience[100];
    char skills[100];
};

// Function to parse a resume and store information in a candidate structure
void parseResume(struct Candidate *candidate, char *resume) {
    char line[100];
    char *token;
    int i = 0;

    // Open the resume file
    FILE *file = fopen(resume, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read the file line by line
    while (fgets(line, 100, file) != NULL) {
        // Remove the newline character at the end of the line
        line[strlen(line) - 1] = '\0';

        // Tokenize the line
        token = strtok(line, " ");

        // Check if the line is a name
        if (strcmp(token, "Name:") == 0) {
            // Store the name
            strcpy(candidate->name, strtok(NULL, " "));
        }

        // Check if the line is an email
        if (strcmp(token, "Email:") == 0) {
            // Store the email
            strcpy(candidate->email, strtok(NULL, " "));
        }

        // Check if the line is a phone number
        if (strcmp(token, "Phone:") == 0) {
            // Store the phone number
            strcpy(candidate->phone, strtok(NULL, " "));
        }

        // Check if the line is experience
        if (strcmp(token, "Experience:") == 0) {
            // Store the experience
            strcpy(candidate->experience, strtok(NULL, " "));
        }

        // Check if the line is skills
        if (strcmp(token, "Skills:") == 0) {
            // Store the skills
            strcpy(candidate->skills, strtok(NULL, " "));
        }
    }

    // Close the file
    fclose(file);
}

// Function to print the candidate information
void printCandidate(struct Candidate *candidate) {
    printf("Name: %s\n", candidate->name);
    printf("Email: %s\n", candidate->email);
    printf("Phone: %s\n", candidate->phone);
    printf("Experience: %s\n", candidate->experience);
    printf("Skills: %s\n", candidate->skills);
}

int main() {
    // Create a candidate structure
    struct Candidate candidate;

    // Parse a resume file
    parseResume(&candidate, "resume.txt");

    // Print the candidate information
    printCandidate(&candidate);

    return 0;
}