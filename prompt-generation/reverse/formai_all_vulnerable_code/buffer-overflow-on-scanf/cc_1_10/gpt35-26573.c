//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the data structure for storing the parsed resume */
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[100];
    char skills[100];
} Resume;

/* Declare the resume parsing function */
Resume parseResume(char* filePath);

int main() {
    char filePath[50];
    printf("Enter the path to the resume file: ");
    scanf("%s", filePath);

    /* Parse the resume */
    Resume resume = parseResume(filePath);

    /* Print the parsed resume */
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}

Resume parseResume(char* filePath) {
    Resume resume;

    /* Open the resume file for reading */
    FILE* file = fopen(filePath, "r");
    if(file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    /* Read and parse the content of the file */
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL) {
        /* Search for name */
        if(strstr(line, "Name: ")) {
            sscanf(line, "Name: %s", resume.name);
        }
        /* Search for email */
        if(strstr(line, "Email: ")) {
            sscanf(line, "Email: %s", resume.email);
        }
        /* Search for phone */
        if(strstr(line, "Phone: ")) {
            sscanf(line, "Phone: %s", resume.phone);
        }
        /* Search for education */
        if(strstr(line, "Education: ")) {
            sscanf(line, "Education: %s", resume.education);
        }
        /* Search for experience */
        if(strstr(line, "Experience: ")) {
            sscanf(line, "Experience: %s", resume.experience);
        }
        /* Search for skills */
        if(strstr(line, "Skills: ")) {
            sscanf(line, "Skills: %s", resume.skills);
        }
    }

    /* Close the file */
    fclose(file);

    return resume;
}