//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EDUCATION_LENGTH 100
#define MAX_WORK_EXPERIENCE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char education[MAX_EDUCATION_LENGTH];
    char work_experience[MAX_WORK_EXPERIENCE_LENGTH];
} Resume;

void parse_name(char* input, Resume* resume) {
    strncpy(resume->name, input, MAX_NAME_LENGTH);
}

void parse_age(char* input, Resume* resume) {
    resume->age = atoi(input);
}

void parse_education(char* input, Resume* resume) {
    strncpy(resume->education, input, MAX_EDUCATION_LENGTH);
}

void parse_work_experience(char* input, Resume* resume) {
    strncpy(resume->work_experience, input, MAX_WORK_EXPERIENCE_LENGTH);
}

int main() {
    Resume resume;
    char input[100];

    printf("Enter your name: ");
    scanf("%s", input);
    parse_name(input, &resume);

    printf("Enter your age: ");
    scanf("%s", input);
    parse_age(input, &resume);

    printf("Enter your education: ");
    scanf("%s", input);
    parse_education(input, &resume);

    printf("Enter your work experience: ");
    scanf("%s", input);
    parse_work_experience(input, &resume);

    printf("Name: %s\n", resume.name);
    printf("Age: %d\n", resume.age);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);

    return 0;
}