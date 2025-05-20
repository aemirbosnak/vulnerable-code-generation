//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Resume
{
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char summary[200];
    char experience[500];
    char education[500];
} Resume;

int main()
{
    Resume resume;
    char input[1000];

    // Get the resume data from the user
    printf("Enter your name: ");
    scanf("%s", resume.name);

    printf("Enter your address: ");
    scanf("%s", resume.address);

    printf("Enter your phone number: ");
    scanf("%s", resume.phone);

    printf("Enter your email address: ");
    scanf("%s", resume.email);

    printf("Enter your summary: ");
    scanf("%s", resume.summary);

    printf("Enter your experience: ");
    scanf("%s", resume.experience);

    printf("Enter your education: ");
    scanf("%s", resume.education);

    // Print the resume data
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phone);
    printf("Email Address: %s\n", resume.email);
    printf("Summary: %s\n", resume.summary);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    return 0;
}