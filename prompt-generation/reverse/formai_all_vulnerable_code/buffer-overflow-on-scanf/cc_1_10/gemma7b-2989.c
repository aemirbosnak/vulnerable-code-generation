//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    char skills[MAX_EXPERIENCE_LENGTH];
} Resume;

int main() {
    Resume resume;
    char input[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    char skills[MAX_EXPERIENCE_LENGTH];

    printf("Enter your name: ");
    scanf("%s", resume.name);

    printf("Enter your address: ");
    scanf("%s", resume.address);

    printf("Enter your phone number: ");
    scanf("%s", resume.phone);

    printf("Enter your email address: ");
    scanf("%s", resume.email);

    printf("Enter your experience: ");
    scanf("%s", experience);

    strcpy(resume.experience, experience);

    printf("Enter your skills: ");
    scanf("%s", skills);

    strcpy(resume.skills, skills);

    printf("Here is your resume:\n");

    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phone);
    printf("Email Address: %s\n", resume.email);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}