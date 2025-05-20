//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone_number[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Resume;

int main()
{
    Resume resume;

    // Get the resume data from the user
    printf("Enter your name: ");
    scanf("%s", resume.name);

    printf("Enter your age: ");
    scanf("%d", &resume.age);

    printf("Enter your occupation: ");
    scanf("%s", resume.occupation);

    printf("Enter your address: ");
    scanf("%s", resume.address);

    printf("Enter your phone number: ");
    scanf("%s", resume.phone_number);

    printf("Enter your email address: ");
    scanf("%s", resume.email);

    // Print the resume data
    printf("\nName: %s", resume.name);

    printf("\nAge: %d", resume.age);

    printf("\nOccupation: %s", resume.occupation);

    printf("\nAddress: %s", resume.address);

    printf("\nPhone Number: %s", resume.phone_number);

    printf("\nEmail Address: %s", resume.email);

    return 0;
}