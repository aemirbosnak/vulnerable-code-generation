//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the resume structure
typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *summary;
    char *skills;
    char *education;
    char *experience;
} resume_t;

// Define the parser function
resume_t *parse_resume(char *filename) {
    // Open the resume file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Allocate memory for the resume struct
    resume_t *resume = malloc(sizeof(resume_t));
    if (resume == NULL) {
        fprintf(stderr, "Error allocating memory for resume\n");
        fclose(file);
        return NULL;
    }

    // Parse the resume file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from line
        line[strlen(line) - 1] = '\0';

        // Check if the line is a header
        if (strstr(line, "Name:")) {
            // Parse the name
            resume->name = strdup(line + 6);
        } else if (strstr(line, "Email:")) {
            // Parse the email
            resume->email = strdup(line + 7);
        } else if (strstr(line, "Phone:")) {
            // Parse the phone
            resume->phone = strdup(line + 7);
        } else if (strstr(line, "Summary:")) {
            // Parse the summary
            resume->summary = strdup(line + 9);
        } else if (strstr(line, "Skills:")) {
            // Parse the skills
            resume->skills = strdup(line + 8);
        } else if (strstr(line, "Education:")) {
            // Parse the education
            resume->education = strdup(line + 11);
        } else if (strstr(line, "Experience:")) {
            // Parse the experience
            resume->experience = strdup(line + 12);
        }
    }

    // Close the resume file
    fclose(file);

    // Return the resume struct
    return resume;
}

// Define the print_resume function
void print_resume(resume_t *resume) {
    // Print the resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Summary: %s\n", resume->summary);
    printf("Skills: %s\n", resume->skills);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
}

// Define the main function
int main(int argc, char **argv) {
    // Check if the user provided a filename
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Parse the resume file
    resume_t *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the resume struct
    free(resume);

    return 0;
}