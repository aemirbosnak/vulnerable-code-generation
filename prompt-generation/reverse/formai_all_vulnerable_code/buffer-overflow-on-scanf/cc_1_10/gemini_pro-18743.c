//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char title[100];
    char company[100];
    char dates[100];
    char skills[1000];
} Resume;

int main() {
    // Declare an array of resumes
    Resume resumes[10];

    // Get the number of resumes
    int numResumes;
    printf("How many resumes do you have? ");
    scanf("%d", &numResumes);

    // Get the resumes
    for (int i = 0; i < numResumes; i++) {
        printf("Enter the name of the resume: ");
        scanf("%s", resumes[i].name);
        printf("Enter the title of the resume: ");
        scanf("%s", resumes[i].title);
        printf("Enter the company of the resume: ");
        scanf("%s", resumes[i].company);
        printf("Enter the dates of the resume: ");
        scanf("%s", resumes[i].dates);
        printf("Enter the skills of the resume: ");
        scanf("%s", resumes[i].skills);
    }

    // Parse the resumes
    for (int i = 0; i < numResumes; i++) {
        // Get the name of the resume
        char *name = resumes[i].name;

        // Get the title of the resume
        char *title = resumes[i].title;

        // Get the company of the resume
        char *company = resumes[i].company;

        // Get the dates of the resume
        char *dates = resumes[i].dates;

        // Get the skills of the resume
        char *skills = resumes[i].skills;

        // Print the resume
        printf("\nResume of %s\n", name);
        printf("Title: %s\n", title);
        printf("Company: %s\n", company);
        printf("Dates: %s\n", dates);
        printf("Skills: %s\n", skills);
    }

    return 0;
}