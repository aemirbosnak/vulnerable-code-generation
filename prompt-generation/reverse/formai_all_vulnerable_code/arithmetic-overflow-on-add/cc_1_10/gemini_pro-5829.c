//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SKILLS 10
#define MAX_SKILLS_LEN 50

// Structure to store skills.
typedef struct {
    char skill[MAX_SKILLS_LEN];
    int proficiency;
} Skill;

// Structure to store resume data.
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char summary[250];
    Skill skills[MAX_SKILLS];
    int num_skills;
} Resume;

int ParseResume(const char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return -1;
    }

    // Read name
    fscanf(file, "%s", resume->name);

    // Read email
    fscanf(file, "%s", resume->email);

    // Read phone
    fscanf(file, "%s", resume->phone);

    // Read summary
    fscanf(file, "%*[^\n]\n"); // Skip the first line
    fgets(resume->summary, 250, file);

    // Read skills
    resume->num_skills = 0;
    while (fscanf(file, "%s %d", resume->skills[resume->num_skills].skill, &resume->skills[resume->num_skills].proficiency) == 2) {
        resume->num_skills++;
    }

    fclose(file);

    return 0;
}

int PrintResume(const Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Summary: %s\n", resume->summary);
    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("\t- %s: %d\n", resume->skills[i].skill, resume->skills[i].proficiency);
    }

    return 0;
}

int main() {
    Resume resume;

    if (ParseResume("input.txt", &resume) == 0) {
        PrintResume(&resume);
    } else {
        fprintf(stderr, "Error parsing resume file.\n");
    }

    return 0;
}