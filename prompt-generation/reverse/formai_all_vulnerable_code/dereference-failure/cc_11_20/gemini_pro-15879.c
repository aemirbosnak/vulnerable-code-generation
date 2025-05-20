//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills[10];
    int num_skills;
} resume;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    resume r;
    r.name = NULL;
    r.email = NULL;
    r.phone = NULL;
    r.num_skills = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:") != NULL) {
            r.name = strdup(line + 5);
        } else if (strstr(line, "Email:") != NULL) {
            r.email = strdup(line + 6);
        } else if (strstr(line, "Phone:") != NULL) {
            r.phone = strdup(line + 6);
        } else if (strstr(line, "Skills:") != NULL) {
            char *skill = strtok(line + 7, ", ");
            while (skill != NULL) {
                r.skills[r.num_skills++] = strdup(skill);
                skill = strtok(NULL, ", ");
            }
        }
    }

    fclose(fp);

    if (line) {
        free(line);
    }

    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Skills:\n");
    for (int i = 0; i < r.num_skills; i++) {
        printf(" - %s\n", r.skills[i]);
    }

    for (int i = 0; i < r.num_skills; i++) {
        free(r.skills[i]);
    }
    free(r.name);
    free(r.email);
    free(r.phone);

    return 0;
}