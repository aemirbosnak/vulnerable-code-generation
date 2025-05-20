//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for resume information
typedef struct {
    char name[50];
    char email[50];
    char education[50];
    char experience[50];
    char skills[50];
} Resume;

// Define struct for keyword information
typedef struct {
    char keyword[50];
    int count;
} Keyword;

// Function to parse resume and store keyword count
void parseResume(Resume *resume, Keyword *keywords, int numKeywords) {
    // Loop through each keyword
    for (int i = 0; i < numKeywords; i++) {
        // Check if keyword is in education section
        if (strstr(resume->education, keywords[i].keyword) != NULL) {
            keywords[i].count++;
        }
        // Check if keyword is in experience section
        if (strstr(resume->experience, keywords[i].keyword) != NULL) {
            keywords[i].count++;
        }
        // Check if keyword is in skills section
        if (strstr(resume->skills, keywords[i].keyword) != NULL) {
            keywords[i].count++;
        }
    }
}

int main() {
    int numKeywords = 5;
    Keyword keywords[numKeywords];
    Resume resume;
    char line[50];
    char *name, *email, *education, *experience, *skills;

    // Input keywords to search for
    printf("Enter %d keywords to search for:\n", numKeywords);
    for (int i = 0; i < numKeywords; i++) {
        scanf("%s", keywords[i].keyword);
        keywords[i].count = 0;
    }

    // Input resume information
    printf("Enter your name:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%[^\n]", resume.name);

    printf("Enter your email:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%[^\n]", resume.email);

    printf("Enter your education:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%[^\n]", resume.education);

    printf("Enter your experience:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%[^\n]", resume.experience);

    printf("Enter your skills:\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%[^\n]", resume.skills);

    // Parse resume and store keyword count
    parseResume(&resume, keywords, numKeywords);

    // Output results
    printf("\n%s\n%s\n%s\n%s\n%s\n", resume.name, resume.email, resume.education, resume.experience, resume.skills);
    for (int i = 0; i < numKeywords; i++) {
        printf("%s: %d\n", keywords[i].keyword, keywords[i].count);
    }

    return 0;
}