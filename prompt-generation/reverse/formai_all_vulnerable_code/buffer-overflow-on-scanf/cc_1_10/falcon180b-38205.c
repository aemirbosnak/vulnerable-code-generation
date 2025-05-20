//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_EDUCATION_LEN 100
#define MAX_WORK_EXPERIENCE_LEN 100
#define MAX_SKILLS_LEN 100
#define MAX_CERTIFICATIONS_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char education[MAX_EDUCATION_LEN];
    char work_experience[MAX_WORK_EXPERIENCE_LEN];
    char skills[MAX_SKILLS_LEN];
    char certifications[MAX_CERTIFICATIONS_LEN];
} Resume;

Resume* create_resume() {
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    if (resume == NULL) {
        printf("Error: Failed to allocate memory for resume.\n");
        exit(1);
    }
    memset(resume, 0, sizeof(Resume));
    return resume;
}

void destroy_resume(Resume* resume) {
    free(resume);
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
    printf("Skills: %s\n", resume->skills);
    printf("Certifications: %s\n", resume->certifications);
}

int main() {
    Resume* resume = create_resume();

    char input[100];
    printf("Enter your name: ");
    scanf("%s", input);
    strcpy(resume->name, input);

    printf("Enter your education: ");
    scanf("%s", input);
    strcpy(resume->education, input);

    printf("Enter your work experience: ");
    scanf("%s", input);
    strcpy(resume->work_experience, input);

    printf("Enter your skills: ");
    scanf("%s", input);
    strcpy(resume->skills, input);

    printf("Enter your certifications: ");
    scanf("%s", input);
    strcpy(resume->certifications, input);

    print_resume(resume);

    destroy_resume(resume);

    return 0;
}