//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
    char name[100];
    char email[100];
    char phone[20];
    char education[100];
    char skills[200];
} Resume;

Resume *parseResume(char *filepath) {
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error: Unable to read file %s\n", filepath);
        return NULL;
    }

    Resume *resume = (Resume *) malloc(sizeof(Resume));
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (strcmp(key, "Name") == 0) {
            strcpy(resume->name, value);
        } else if (strcmp(key, "Email") == 0) {
            strcpy(resume->email, value);
        } else if (strcmp(key, "Phone") == 0) {
            strcpy(resume->phone, value);
        } else if (strcmp(key, "Education") == 0) {
            strcpy(resume->education, value);
        } else if (strcmp(key, "Skills") == 0) {
            strcpy(resume->skills, value);
        }
    }

    fclose(fp);
    return resume;
}

int main() {
    printf("Welcome to the Resume Parsing System!\n");
    printf("Please enter the filepath of the resume you would like to parse:\n");

    char filepath[100];
    scanf("%s", filepath);

    Resume *resume = parseResume(filepath);

    if (resume != NULL) {
        printf("\nResume Parsed Successfully!\n\n");
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone: %s\n", resume->phone);
        printf("Education: %s\n", resume->education);
        printf("Skills: %s\n", resume->skills);
    }

    free(resume);
    return 0;
}