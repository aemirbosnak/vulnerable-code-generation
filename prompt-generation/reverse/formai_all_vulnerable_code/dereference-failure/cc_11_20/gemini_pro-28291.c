//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
    char *experience;
    char *education;
} resume;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    resume r = {0};

    while ((read = getline(&line, &len, fp)) != -1) {
        if (read == 0) {
            continue;
        }

        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            r.name = strdup(value);
        } else if (strcmp(key, "Email") == 0) {
            r.email = strdup(value);
        } else if (strcmp(key, "Phone") == 0) {
            r.phone = strdup(value);
        } else if (strcmp(key, "Skills") == 0) {
            r.skills = strdup(value);
        } else if (strcmp(key, "Experience") == 0) {
            r.experience = strdup(value);
        } else if (strcmp(key, "Education") == 0) {
            r.education = strdup(value);
        }
    }

    fclose(fp);

    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
    printf("Education: %s\n", r.education);

    free(r.name);
    free(r.email);
    free(r.phone);
    free(r.skills);
    free(r.experience);
    free(r.education);

    return EXIT_SUCCESS;
}