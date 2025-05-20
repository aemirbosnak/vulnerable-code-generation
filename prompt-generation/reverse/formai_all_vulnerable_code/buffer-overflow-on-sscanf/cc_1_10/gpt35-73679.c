//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUMES 10
#define MAX_FIELDS 5
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    int age;
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
} Resume;

void printResume(Resume resume);
void parseResumeField(char* field, char* value, Resume* resume);

int main() {
    Resume resumes[MAX_RESUMES];
    int numResumes = 0;
    char input[MAX_LENGTH];
    char field[MAX_LENGTH];
    char value[MAX_LENGTH];
    int i,j;

    printf("Welcome to the C Resume Parsing System!\n");
    printf("Please input information for up to %d resumes.\n", MAX_RESUMES);

    for(i=0; i<MAX_RESUMES; i++) {
        Resume resume;
        printf("\nResume %d:\n", i+1);

        for(j=0; j<MAX_FIELDS; j++) {
            printf("Enter %s: ", j==0 ? "name" : j==1 ? "email" : j==2 ? "age" : j==3 ? "education" : "experience");
            fgets(input, MAX_LENGTH, stdin);
            sscanf(input, "%s %s\n", field, value);
            parseResumeField(field, value, &resume);
        }

        resumes[numResumes++] = resume;

        printf("\nThank you for entering your information! Here is your resume:\n");
        printResume(resume);
    }

    printf("\nThat's all for now! Here are all the resumes:\n");
    for(i=0; i<numResumes; i++) {
        printResume(resumes[i]);
    }

    return 0;
}

void printResume(Resume resume) {
    printf("\nName: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Age: %d\n", resume.age);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
}

void parseResumeField(char* field, char* value, Resume* resume) {
    if(strcmp(field, "name") == 0) {
        strcpy(resume->name, value);
    } else if(strcmp(field, "email") == 0) {
        strcpy(resume->email, value);
    } else if(strcmp(field, "age") == 0) {
        resume->age = atoi(value);
    } else if(strcmp(field, "education") == 0) {
        strcpy(resume->education, value);
    } else if(strcmp(field, "experience") == 0) {
        strcpy(resume->experience, value);
    } else {
        printf("Invalid field: %s\n", field);
    }
}