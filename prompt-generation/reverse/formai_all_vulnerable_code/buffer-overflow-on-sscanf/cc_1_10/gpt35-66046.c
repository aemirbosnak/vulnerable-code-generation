//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_RESUME 1000
#define MAX_SKILLS 100

typedef struct {
    char name[MAX_INPUT];
    int years;
} Skill;

typedef struct {
    char name[MAX_INPUT];
    int age;
    Skill skills[MAX_SKILLS];
    int num_skills;
} Candidate;

void parse_resume(char* filename, Candidate* candidate) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    char line[MAX_INPUT];
    while (fgets(line, MAX_INPUT, file)) {
        if (strstr(line, "Name:")) {
            sscanf(line + strlen("Name:"), "%[^\n]", candidate->name);
        } else if (strstr(line, "Age:")) {
            sscanf(line + strlen("Age:"), "%d", &candidate->age);
        } else if (strstr(line, "Skill:")) {
            if (candidate->num_skills == MAX_SKILLS) {
                printf("Too many skills!\n");
                exit(1);
            }
            char name[MAX_INPUT];
            int years;
            sscanf(line + strlen("Skill:"), "%[^,],%d", name, &years);
            strcpy(candidate->skills[candidate->num_skills].name, name);
            candidate->skills[candidate->num_skills].years = years;
            candidate->num_skills++;
        }
    }
    fclose(file);
}

int main() {
    printf("Welcome to the C Resume Parsing System (Post-Apocalyptic Edition)!\n");
    printf("Please enter the filename of the candidate's resume: ");
    char filename[MAX_INPUT];
    fgets(filename, MAX_INPUT, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    Candidate candidate;
    parse_resume(filename, &candidate);
    printf("Candidate Name: %s\n", candidate.name);
    printf("Candidate Age: %d\n", candidate.age);
    printf("Candidate Skills:\n");
    for (int i = 0; i < candidate.num_skills; i++) {
        printf("- %s (%d years)\n", candidate.skills[i].name, candidate.skills[i].years);
    }
    return 0;
}