//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 10
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char skills[MAX_SKILLS][MAX_NAME_LENGTH];
    int num_skills;
} Resume;

int parse_resume(char* filename, Resume* resume);
void print_resume(Resume* resume);
void search_skill(char* skill, Resume* resumes, int num_resumes);

int main() {
    char filenames[MAX_RESUMES][MAX_NAME_LENGTH] = {"resume1.txt", "resume2.txt", "resume3.txt"};
    int num_resumes = sizeof(filenames) / sizeof(char[MAX_NAME_LENGTH]);
    Resume resumes[MAX_RESUMES];

    for (int i = 0; i < num_resumes; i++) {
        parse_resume(filenames[i], &resumes[i]);
        printf("Parsed resume %d:\n", i);
        print_resume(&resumes[i]);
        printf("\n");
    }

    printf("Search resumes for a skill:\n");
    char skill[MAX_NAME_LENGTH];
    scanf("%s", skill);
    search_skill(skill, resumes, num_resumes);

    return 0;
}

int parse_resume(char* filename, Resume* resume) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return 0;
    }

    char line[MAX_NAME_LENGTH];
    fgets(line, MAX_NAME_LENGTH, fp);
    sscanf(line, "%s", resume->name);

    resume->num_skills = 0;
    while (fgets(line, MAX_NAME_LENGTH, fp) != NULL && resume->num_skills < MAX_SKILLS) {
        sscanf(line, "%s", resume->skills[resume->num_skills++]);
    }

    fclose(fp);
    return 1;
}

void print_resume(Resume* resume) {
    printf("Name: %s\nSkills:\n", resume->name);
    for (int i = 0; i < resume->num_skills; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
}

void search_skill(char* skill, Resume* resumes, int num_resumes) {
    printf("Resumes that match skill '%s':\n", skill);
    for (int i = 0; i < num_resumes; i++) {
        Resume* resume = &resumes[i];
        for (int j = 0; j < resume->num_skills; j++) {
            if (strcmp(skill, resume->skills[j]) == 0) {
                print_resume(resume);
                break;
            }
        }
    }
}