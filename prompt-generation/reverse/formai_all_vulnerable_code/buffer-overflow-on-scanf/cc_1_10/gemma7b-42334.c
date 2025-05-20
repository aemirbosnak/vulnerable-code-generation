//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 1000

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phoneNumber[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

int main()
{
    Resume resume;
    char input[MAX_NAME_LENGTH];
    char* pInput = NULL;
    int i = 0;

    printf("Enter your name: ");
    scanf("%s", input);

    pInput = strdup(input);

    strcpy(resume.name, pInput);

    printf("Enter your address: ");
    scanf("%s", input);

    strcpy(resume.address, pInput);

    printf("Enter your phone number: ");
    scanf("%s", input);

    strcpy(resume.phoneNumber, pInput);

    printf("Enter your email address: ");
    scanf("%s", input);

    strcpy(resume.email, pInput);

    printf("Enter your experience: ");
    scanf("%s", input);

    strcpy(resume.experience, input);

    printf("Your resume:\n");
    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phoneNumber);
    printf("Email Address: %s\n", resume.email);
    printf("Experience: %s\n", resume.experience);

    free(pInput);

    return 0;
}