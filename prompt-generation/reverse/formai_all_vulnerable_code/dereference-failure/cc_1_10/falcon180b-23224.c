//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_TITLE_LENGTH 100
#define MAX_COMPANY_LENGTH 100
#define MAX_EDUCATION_LENGTH 100
#define MAX_SKILL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skills[MAX_SKILL_LENGTH];
} Resume;

void parseResume(Resume *resume, char *line) {
    char *token;
    char *saveptr;

    token = strtok_r(line, ":", &saveptr);
    strcpy(resume->name, token);

    token = strtok_r(NULL, ":", &saveptr);
    strcpy(resume->title, token);

    token = strtok_r(NULL, ":", &saveptr);
    strcpy(resume->company, token);

    token = strtok_r(NULL, ":", &saveptr);
    strcpy(resume->education, token);

    token = strtok_r(NULL, ":", &saveptr);
    strcpy(resume->skills, token);
}

int main() {
    FILE *fp;
    char line[1024];
    Resume resume;

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening resume file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        parseResume(&resume, line);
        printf("Name: %s\n", resume.name);
        printf("Title: %s\n", resume.title);
        printf("Company: %s\n", resume.company);
        printf("Education: %s\n", resume.education);
        printf("Skills: %s\n\n", resume.skills);
    }

    fclose(fp);

    return 0;
}