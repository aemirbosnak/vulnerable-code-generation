//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone_number[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char summary[MAX_NAME_LENGTH];
} Resume;

int main()
{
    Resume resume;
    char input[MAX_NAME_LENGTH];

    printf("Enter your name: ");
    scanf("%s", input);

    strcpy(resume.name, input);

    printf("Enter your address: ");
    scanf("%s", input);

    strcpy(resume.address, input);

    printf("Enter your phone number: ");
    scanf("%s", input);

    strcpy(resume.phone_number, input);

    printf("Enter your email address: ");
    scanf("%s", input);

    strcpy(resume.email, input);

    printf("Enter your summary: ");
    scanf("%s", input);

    strcpy(resume.summary, input);

    printf("Your resume:\n");
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phone_number);
    printf("Email Address: %s\n", resume.email);
    printf("Summary: %s\n", resume.summary);

    return 0;
}