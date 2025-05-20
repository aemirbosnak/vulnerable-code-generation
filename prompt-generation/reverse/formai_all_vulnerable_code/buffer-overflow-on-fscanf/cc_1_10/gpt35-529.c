//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the maximum length of resume fields
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_EDUCATION_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 200

// Define a struct to represent a resume
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

// Define a function to parse a resume from a file
Resume parse_resume(FILE* file) {
    Resume resume;

    // Read the name from the file
    char name[MAX_NAME_LENGTH];
    fscanf(file, "Name: %s", name);
    strncpy(resume.name, name, MAX_NAME_LENGTH);

    // Read the email from the file
    char email[MAX_EMAIL_LENGTH];
    fscanf(file, "Email: %s", email);
    strncpy(resume.email, email, MAX_EMAIL_LENGTH);

    // Read the education from the file
    char education[MAX_EDUCATION_LENGTH];
    fscanf(file, "Education: %s", education);
    strncpy(resume.education, education, MAX_EDUCATION_LENGTH);

    // Read the experience from the file
    char experience[MAX_EXPERIENCE_LENGTH];
    fseek(file, 0, SEEK_END); // Move the file pointer to the end of the file
    long file_size = ftell(file); // Get the size of the file
    fseek(file, 0, SEEK_SET); // Move the file pointer back to the start of the file
    int experience_start = 0;
    int experience_length = 0;
    char* file_contents = malloc(file_size + 1); // Allocate memory for the file contents
    fread(file_contents, file_size, 1, file); // Read the file contents into memory
    file_contents[file_size] = '\0'; // Add a null terminator to the end of the file contents
    char* experience_start_str = strstr(file_contents, "Experience:"); // Find the start of the experience section
    if (experience_start_str != NULL) {
        experience_start = experience_start_str - file_contents;
    }
    char* next_section_str = strstr(file_contents + experience_start, "\n\n"); // Find the end of the experience section
    if (next_section_str != NULL) {
        experience_length = next_section_str - (file_contents + experience_start);
    } else {
        experience_length = file_size - experience_start;
    }
    strncpy(experience, file_contents + experience_start, experience_length);
    free(file_contents); // Free the memory allocated for the file contents
    strncpy(resume.experience, experience, MAX_EXPERIENCE_LENGTH);

    return resume;
}

int main() {
    // Parse a sample resume from a file and print the results
    FILE* file = fopen("example_resume.txt", "r"); // Open the file for reading
    Resume resume = parse_resume(file);
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    fclose(file); // Close the file

    return 0;
}