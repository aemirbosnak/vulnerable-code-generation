//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char *name;
    char *email;
    char *phone;
    char *summary;
    char *skills[10];
    char *experience[10];
    char *education[10];
};

int main() {
    struct Resume resume;

    // Get the resume data from the user
    printf("Enter your name: ");
    scanf("%s", &resume.name);
    printf("Enter your email: ");
    scanf("%s", &resume.email);
    printf("Enter your phone number: ");
    scanf("%s", &resume.phone);
    printf("Enter a brief summary of your skills: ");
    scanf("%s", &resume.summary);
    printf("Enter your skills (separate with commas): ");
    scanf("%s", &resume.skills);
    printf("Enter your experience (separate with commas): ");
    scanf("%s", &resume.experience);
    printf("Enter your education (separate with commas): ");
    scanf("%s", &resume.education);

    // Print the resume data
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Summary: %s\n", resume.summary);
    printf("Skills: ");
    for (int i = 0; i < 10; i++) {
        printf("%s ", resume.skills[i]);
    }
    printf("\nExperience: ");
    for (int i = 0; i < 10; i++) {
        printf("%s ", resume.experience[i]);
    }
    printf("\nEducation: ");
    for (int i = 0; i < 10; i++) {
        printf("%s ", resume.education[i]);
    }

    return 0;
}