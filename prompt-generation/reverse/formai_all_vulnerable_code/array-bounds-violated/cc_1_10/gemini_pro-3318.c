//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store resume data
typedef struct Resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Function to parse a resume from a file
Resume *parse_resume(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Allocate memory for the resume
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        fclose(file);
        return NULL;
    }

    // Initialize the resume fields
    resume->name = NULL;
    resume->email = NULL;
    resume->phone = NULL;
    resume->skills = NULL;
    resume->experience = NULL;
    resume->education = NULL;

    // Parse the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Check if the line is empty
        if (strlen(line) == 0) {
            continue;
        }

        // Parse the line
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\0");

        // Check if the key is valid
        if (strcmp(key, "name") == 0) {
            // Allocate memory for the name
            resume->name = malloc(strlen(value) + 1);
            if (resume->name == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the name to the resume
            strcpy(resume->name, value);
        } else if (strcmp(key, "email") == 0) {
            // Allocate memory for the email
            resume->email = malloc(strlen(value) + 1);
            if (resume->email == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the email to the resume
            strcpy(resume->email, value);
        } else if (strcmp(key, "phone") == 0) {
            // Allocate memory for the phone number
            resume->phone = malloc(strlen(value) + 1);
            if (resume->phone == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the phone number to the resume
            strcpy(resume->phone, value);
        } else if (strcmp(key, "skills") == 0) {
            // Allocate memory for the skills
            resume->skills = malloc(strlen(value) + 1);
            if (resume->skills == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the skills to the resume
            strcpy(resume->skills, value);
        } else if (strcmp(key, "experience") == 0) {
            // Allocate memory for the experience
            resume->experience = malloc(strlen(value) + 1);
            if (resume->experience == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the experience to the resume
            strcpy(resume->experience, value);
        } else if (strcmp(key, "education") == 0) {
            // Allocate memory for the education
            resume->education = malloc(strlen(value) + 1);
            if (resume->education == NULL) {
                fclose(file);
                free(resume);
                return NULL;
            }

            // Copy the education to the resume
            strcpy(resume->education, value);
        }
    }

    // Close the file
    fclose(file);

    // Return the resume
    return resume;
}

// Function to print a resume
void print_resume(Resume *resume) {
    // Print the resume fields
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
    printf("Education: %s\n", resume->education);
}

// Function to free the memory allocated for a resume
void free_resume(Resume *resume) {
    // Free the memory allocated for the resume fields
    free(resume->name);
    free(resume->email);
    free(resume->phone);
    free(resume->skills);
    free(resume->experience);
    free(resume->education);

    // Free the memory allocated for the resume
    free(resume);
}

// Main function
int main() {
    // Parse the resume from a file
    Resume *resume = parse_resume("resume.txt");
    if (resume == NULL) {
        printf("Error parsing resume.\n");
        return 1;
    }

    // Print the resume
    print_resume(resume);

    // Free the memory allocated for the resume
    free_resume(resume);

    return 0;
}