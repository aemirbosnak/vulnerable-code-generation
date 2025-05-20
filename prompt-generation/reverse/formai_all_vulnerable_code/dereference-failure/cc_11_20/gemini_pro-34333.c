//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Resume resume;

    while ((read = getline(&line, &len, fp)) != -1) {
        // Parse the line.
        char *field = strtok(line, ": ");
        if (field == NULL) {
            continue;
        }

        char *value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }

        // Store the value in the resume struct.
        if (strcmp(field, "Name") == 0) {
            resume.name = strdup(value);
        } else if (strcmp(field, "Email") == 0) {
            resume.email = strdup(value);
        } else if (strcmp(field, "Phone") == 0) {
            resume.phone = strdup(value);
        } else if (strcmp(field, "Address") == 0) {
            resume.address = strdup(value);
        } else if (strcmp(field, "Skills") == 0) {
            resume.skills = strdup(value);
        } else if (strcmp(field, "Experience") == 0) {
            resume.experience = strdup(value);
        } else if (strcmp(field, "Education") == 0) {
            resume.education = strdup(value);
        }
    }

    // Print the resume.
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    // Free the memory.
    free(resume.name);
    free(resume.email);
    free(resume.phone);
    free(resume.address);
    free(resume.skills);
    free(resume.experience);
    free(resume.education);

    return 0;
}