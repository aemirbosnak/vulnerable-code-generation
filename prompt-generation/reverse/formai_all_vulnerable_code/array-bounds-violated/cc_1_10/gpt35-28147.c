//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // Maximum size for each section of the resume
#define MAX_RES 5 // Maximum number of resumes to parse

int main()
{
    // Create variables for each section of the resume
    char name[MAX_SIZE], email[MAX_SIZE], phone[MAX_SIZE];
    char education[MAX_SIZE], skills[MAX_SIZE], experience[MAX_SIZE];

    // Array to store all the resumes
    char resumes[MAX_RES][MAX_SIZE];

    printf("Welcome to the Resume Parsing System!\n");

    // Get the information for each resume
    for (int i=0; i<MAX_RES; i++)
    {
        printf("Please enter the name for resume #%d: ", i+1);
        fgets(resumes[i], MAX_SIZE, stdin);
        resumes[i][strlen(resumes[i])-1] = '\0'; // Replace newline with null terminator
        
        printf("Please enter %s's email: ", resumes[i]);
        fgets(email, MAX_SIZE, stdin);
        email[strlen(email)-1] = '\0';

        printf("Please enter %s's phone number: ", resumes[i]);
        fgets(phone, MAX_SIZE, stdin);
        phone[strlen(phone)-1] = '\0';

        printf("Please enter %s's education: ", resumes[i]);
        fgets(education, MAX_SIZE, stdin);
        education[strlen(education)-1] = '\0';

        printf("Please enter %s's skills: ", resumes[i]);
        fgets(skills, MAX_SIZE, stdin);
        skills[strlen(skills)-1] = '\0';

        printf("Please enter %s's experience: ", resumes[i]);
        fgets(experience, MAX_SIZE, stdin);
        experience[strlen(experience)-1] = '\0';

        // The following code segment could be used to parse the resume and store information in a database
        // For example, use strtok() to split the skills string into individual skills and store in a separate
        // table that would link back to the candidate's ID
        printf("Resume #%d parsed successfully!\n", i+1);
    }

    return 0;
}