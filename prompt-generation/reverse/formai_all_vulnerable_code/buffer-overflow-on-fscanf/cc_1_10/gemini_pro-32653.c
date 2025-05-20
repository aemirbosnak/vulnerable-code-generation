//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_SKILL_LEN 256
#define MAX_SKILLS 10
#define MAX_EXPERIENCE_LEN 256
#define MAX_EXPERIENCES 10

typedef struct {
    char name[MAX_NAME_LEN];
    char skills[MAX_SKILLS][MAX_SKILL_LEN];
    int num_skills;
    char experiences[MAX_EXPERIENCES][MAX_EXPERIENCE_LEN];
    int num_experiences;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = malloc(sizeof(Resume));
    if (resume == NULL) {
        return NULL;
    }

    // Parse the name
    if (fscanf(fp, "%s", resume->name) != 1) {
        free(resume);
        return NULL;
    }

    // Parse the skills
    int num_skills = 0;
    while (fscanf(fp, "%s", resume->skills[num_skills]) == 1) {
        num_skills++;
        if (num_skills == MAX_SKILLS) {
            break;
        }
    }
    resume->num_skills = num_skills;

    // Parse the experiences
    int num_experiences = 0;
    while (fscanf(fp, "%s", resume->experiences[num_experiences]) == 1) {
        num_experiences++;
        if (num_experiences == MAX_EXPERIENCES) {
            break;
        }
    }
    resume->num_experiences = num_experiences;

    return resume;
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("    %s\n", resume->skills[i]);
    }
    printf("Experiences:\n");
    for (int i = 0; i < resume->num_experiences; i++) {
        printf("    %s\n", resume->experiences[i]);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open resume file\n");
        return 1;
    }

    Resume *resume = parse_resume(fp);
    if (resume == NULL) {
        printf("Error: could not parse resume file\n");
        return 1;
    }

    print_resume(resume);

    fclose(fp);
    free(resume);

    return 0;
}