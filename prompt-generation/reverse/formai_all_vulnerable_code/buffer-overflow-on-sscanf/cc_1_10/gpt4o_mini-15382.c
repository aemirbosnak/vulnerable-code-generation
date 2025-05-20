//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

// Struct to hold resume information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Resume;

// Function to parse a single line for a specific keyword
void parseLine(Resume *resume, char *line) {
    if (strstr(line, "Name:") != NULL) {
        sscanf(line, "Name: %[^\n]", resume->name);
    } else if (strstr(line, "Email:") != NULL) {
        sscanf(line, "Email: %[^\n]", resume->email);
    } else if (strstr(line, "Phone:") != NULL) {
        sscanf(line, "Phone: %[^\n]", resume->phone);
    }
}

// Function to read the resume from a text file
void readResume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLine(resume, line);
    }

    fclose(file);
}

// Function to display the parsed resume information
void displayResume(const Resume *resume) {
    printf("Parsed Resume Information:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
}

int main() {
    Resume resume;
    // Initialize the resume data with empty strings
    memset(&resume, 0, sizeof(Resume));

    // Read the resume from the specified file
    readResume("resume.txt", &resume);
    
    // Display parsed resume information
    displayResume(&resume);
    
    return 0;
}