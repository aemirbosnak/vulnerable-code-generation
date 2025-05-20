//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct to hold resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char education[100];
    char experience[100];
} ResumeInfo;

//Function to parse resume and extract information
void parseResume(char *resumeText, ResumeInfo *resume) {
    char *token;

    //Extracting name
    token = strtok(resumeText, "\n");
    sscanf(token, "%[^\n]", resume->name);

    //Extracting email
    token = strtok(NULL, "\n");
    sscanf(token, "%[^\n]", resume->email);

    //Extracting phone number
    token = strtok(NULL, "\n");
    sscanf(token, "%[^\n]", resume->phone);

    //Extracting skills
    token = strtok(NULL, "\n");
    sscanf(token, "%[^\n]", resume->skills);

    //Extracting education details
    token = strtok(NULL, "\n");
    sscanf(token, "%[^\n]", resume->education);

    //Extracting work experience
    token = strtok(NULL, "\n");
    sscanf(token, "%[^\n]", resume->experience);
}

int main() {
    char resumeText[500];
    ResumeInfo resume;

    //Reading in resume text from file
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%[^\n]", resumeText);
    fclose(file);

    //Parsing resume and extracting information
    parseResume(resumeText, &resume);

    //Printing extracted information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}