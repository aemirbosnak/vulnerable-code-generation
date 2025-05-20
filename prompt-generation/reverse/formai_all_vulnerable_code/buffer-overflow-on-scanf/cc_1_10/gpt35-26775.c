//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[1000];
} Resume;

// Function for parsing resume file
Resume parseResume(char filename[]) {
    Resume resume;
    FILE *fp;
    char line[200];
    char tempStr[1000];

    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fgets(line, 200, fp);   // Read first line for name
    strcpy(resume.name, line);

    fgets(line, 200, fp);   // Read second line for email
    strcpy(resume.email, line);

    fgets(line, 200, fp);   // Read third line for phone
    strcpy(resume.phone, line);

    fgets(line, 200, fp);   // Read fourth line for education
    strcpy(resume.education, line);

    while(fgets(line, 200, fp)) {   // Read all lines after education for experience
        sprintf(tempStr, "%s%s", resume.experience, line);
        strcpy(resume.experience, tempStr);
    }

    fclose(fp);

    return resume;
}

int main() {
    char filename[50];
    Resume resume;

    printf("Welcome to C Resume Parsing System!\n\n");

    printf("Please enter the filename of the resume to parse (including extension): ");
    scanf("%s", filename);

    printf("\nParsing resume...\n\n");

    resume = parseResume(filename);

    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);

    printf("\n\nThank you for using C Resume Parsing System!\n");

    return 0;
}