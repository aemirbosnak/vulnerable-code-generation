//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store resume data
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char skills[500];
    char education[500];
    char experience[500];
} Resume;

// Function to parse a resume from a text file
Resume* parse_resume(const char* filename) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Create a new resume struct
    Resume* resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fprintf(stderr, "Error allocating memory for resume struct\n");
        fclose(file);
        return NULL;
    }

    // Read the resume data from the file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line, "Email: %s", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line, "Phone: %s", resume->phone);
        } else if (strncmp(line, "Address:", 8) == 0) {
            sscanf(line, "Address: %s", resume->address);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            sscanf(line, "Skills: %s", resume->skills);
        } else if (strncmp(line, "Education:", 10) == 0) {
            sscanf(line, "Education: %s", resume->education);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            sscanf(line, "Experience: %s", resume->experience);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Function to print a resume
void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Main function
int main() {
    // Parse the resume
    Resume* resume = parse_resume("resume.txt");
    if (resume == NULL) {
        fprintf(stderr, "Error parsing resume\n");
        return EXIT_FAILURE;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume struct
    free(resume);

    return EXIT_SUCCESS;
}