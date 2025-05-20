//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EDUCATION_LEN 200
#define MAX_EXPERIENCE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char education[MAX_EDUCATION_LEN];
    char experience[MAX_EXPERIENCE_LEN];
} Resume;

Resume parseResume(char *input) {
    Resume resume;
    char *token;
    char *saveptr;

    // Parse name
    token = strtok_r(input, "\n", &saveptr);
    if (token == NULL) {
        printf("Error: Invalid input format.\n");
        exit(1);
    }
    strncpy(resume.name, token, MAX_NAME_LEN);

    // Parse education
    token = strtok_r(NULL, "\n", &saveptr);
    if (token == NULL) {
        printf("Error: Invalid input format.\n");
        exit(1);
    }
    strncpy(resume.education, token, MAX_EDUCATION_LEN);

    // Parse experience
    token = strtok_r(NULL, "\n", &saveptr);
    if (token == NULL) {
        printf("Error: Invalid input format.\n");
        exit(1);
    }
    strncpy(resume.experience, token, MAX_EXPERIENCE_LEN);

    return resume;
}

void printResume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    char input[1000];
    Resume resume;

    printf("Enter your resume:\n");
    fgets(input, sizeof(input), stdin);

    resume = parseResume(input);
    printResume(resume);

    return 0;
}