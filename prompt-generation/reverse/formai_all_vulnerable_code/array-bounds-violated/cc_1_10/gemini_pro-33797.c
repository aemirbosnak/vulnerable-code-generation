//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *education;
    char *experience;
} resume;

int main() {
    // Define the resume fields
    char *fields[] = {"name", "email", "phone", "skills", "education", "experience"};

    // Create a resume struct
    resume my_resume;

    // Parse the resume
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Find the field name
        char *field_name = strtok(line, ":");

        // Find the field value
        char *field_value = strtok(NULL, "\n");

        // Set the field value in the resume struct
        if (strcmp(field_name, "name") == 0) {
            my_resume.name = strdup(field_value);
        } else if (strcmp(field_name, "email") == 0) {
            my_resume.email = strdup(field_value);
        } else if (strcmp(field_name, "phone") == 0) {
            my_resume.phone = strdup(field_value);
        } else if (strcmp(field_name, "skills") == 0) {
            my_resume.skills = strdup(field_value);
        } else if (strcmp(field_name, "education") == 0) {
            my_resume.education = strdup(field_value);
        } else if (strcmp(field_name, "experience") == 0) {
            my_resume.experience = strdup(field_value);
        }
    }

    // Close the file
    fclose(fp);

    // Print the resume
    printf("Name: %s\n", my_resume.name);
    printf("Email: %s\n", my_resume.email);
    printf("Phone: %s\n", my_resume.phone);
    printf("Skills: %s\n", my_resume.skills);
    printf("Education: %s\n", my_resume.education);
    printf("Experience: %s\n", my_resume.experience);

    // Free the memory allocated for the resume fields
    free(my_resume.name);
    free(my_resume.email);
    free(my_resume.phone);
    free(my_resume.skills);
    free(my_resume.education);
    free(my_resume.experience);

    return EXIT_SUCCESS;
}