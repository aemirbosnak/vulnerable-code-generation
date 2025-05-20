//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char resume_text[MAX_NAME_LENGTH];
} Resume;

int main()
{
    Resume resume;
    char input_buffer[MAX_NAME_LENGTH];

    printf("Welcome to the Resume Parser!\n");

    // Get the candidate's name
    printf("Enter your name: ");
    scanf("%s", resume.name);

    // Get the candidate's address
    printf("Enter your address: ");
    scanf("%s", resume.address);

    // Get the candidate's phone number
    printf("Enter your phone number: ");
    scanf("%s", resume.phone);

    // Get the candidate's email address
    printf("Enter your email address: ");
    scanf("%s", resume.email);

    // Get the candidate's resume text
    printf("Enter your resume text: ");
    scanf("%s", resume.resume_text);

    // Print the candidate's information
    printf("\nName: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone Number: %s\n", resume.phone);
    printf("Email Address: %s\n", resume.email);
    printf("Resume Text: %s\n", resume.resume_text);

    return 0;
}