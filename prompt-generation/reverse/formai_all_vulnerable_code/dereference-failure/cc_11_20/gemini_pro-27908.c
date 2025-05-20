//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *summary;
    char *skills;
    char *education;
    char *experience;
};

int main() {
    // Create a resume struct
    struct resume resume;

    // Parse the resume from a file
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line and extract the relevant information
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            resume.name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            resume.email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            resume.phone = strdup(value);
        } else if (strcmp(key, "Address") == 0) {
            resume.address = strdup(value);
        } else if (strcmp(key, "Summary") == 0) {
            resume.summary = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            resume.skills = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            resume.education = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            resume.experience = strdup(value);
        }
    }

    // Close the file
    fclose(file);

    // Print the resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Summary: %s\n", resume.summary);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    // Free the memory allocated for the resume
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.address);
    free(resume.summary);
    free(resume.skills);
    free(resume.education);
    free(resume.experience);

    return EXIT_SUCCESS;
}