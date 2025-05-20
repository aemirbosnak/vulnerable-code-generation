//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing individual resume data
struct Resume {
    char* name;
    char* email;
    char* education;
    char* skills;
    char* experience;
};

int main() {
    printf("Welcome to the C Resume Parsing System!\n");

    // Create a variable to store the number of resumes to be parsed
    int num_resumes = 0;

    // Get user input for number of resumes to be parsed
    printf("How many resumes would you like to parse?\n");
    scanf("%d", &num_resumes);

    // Create an array of Resume structs dynamically
    struct Resume* resumes = (struct Resume*)malloc(num_resumes * sizeof(struct Resume));

    // Loop through each resume and prompt user for resume data
    for (int i = 0; i < num_resumes; i++) {
        // Create a string buffer for getting user input
        char buffer[256];

        // Prompt user for name
        printf("Enter the name for resume #%d:\n", i+1);
        scanf("%s", buffer);
        resumes[i].name = strdup(buffer);

        // Prompt user for email
        printf("Enter the email for resume #%d:\n", i+1);
        scanf("%s", buffer);
        resumes[i].email = strdup(buffer);

        // Prompt user for education
        printf("Enter the education information for resume #%d:\n", i+1);
        scanf("%s", buffer);
        resumes[i].education = strdup(buffer);

        // Prompt user for skills
        printf("Enter the skills information for resume #%d:\n", i+1);
        scanf("%s", buffer);
        resumes[i].skills = strdup(buffer);

        // Prompt user for experience
        printf("Enter the experience information for resume #%d:\n", i+1);
        scanf("%s", buffer);
        resumes[i].experience = strdup(buffer);
    }

    // Print out all resume data for each parsed resume
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume #%d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Education: %s\n", resumes[i].education);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %s\n", resumes[i].experience);
    }

    // Free all dynamically allocated memory
    for (int i = 0; i < num_resumes; i++) {
        free(resumes[i].name);
        free(resumes[i].email);
        free(resumes[i].education);
        free(resumes[i].skills);
        free(resumes[i].experience);
    }
    free(resumes);

    return 0;
}