//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a resume
typedef struct {
    char name[50];
    char education[100];
    char experience[100];
    char skills[100];
} Resume;

// Function to read a resume from a file
Resume readResume(FILE *fp) {
    Resume r;
    fscanf(fp, "%s", r.name);
    fscanf(fp, "%s", r.education);
    fscanf(fp, "%s", r.experience);
    fscanf(fp, "%s", r.skills);
    return r;
}

// Function to write a resume to a file
void writeResume(FILE *fp, Resume r) {
    fprintf(fp, "%s %s %s %s\n", r.name, r.education, r.experience, r.skills);
}

// Function to parse a resume and extract relevant information
void parseResume(Resume r, char *name, char *education, char *experience, char *skills) {
    strcpy(name, r.name);
    strcpy(education, r.education);
    strcpy(experience, r.experience);
    strcpy(skills, r.skills);
}

// Function to search for a specific keyword in a resume
int searchResume(Resume r, char *keyword) {
    if (strstr(r.name, keyword)!= NULL ||
        strstr(r.education, keyword)!= NULL ||
        strstr(r.experience, keyword)!= NULL ||
        strstr(r.skills, keyword)!= NULL) {
        return 1;
    }
    return 0;
}

// Main function to demonstrate the use of the resume parsing system
int main() {
    FILE *fp;
    Resume r;
    char name[50], education[100], experience[100], skills[100];

    // Open the resume file for reading
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: unable to open resume file.\n");
        return 1;
    }

    // Read the resume from the file
    r = readResume(fp);

    // Parse the resume and extract relevant information
    parseResume(r, name, education, experience, skills);

    // Search for a specific keyword in the resume
    if (searchResume(r, "programming")) {
        printf("This resume contains programming experience.\n");
    } else {
        printf("This resume does not contain programming experience.\n");
    }

    // Write the resume to a new file
    fp = fopen("new_resume.txt", "w");
    if (fp == NULL) {
        printf("Error: unable to create new resume file.\n");
        return 1;
    }
    writeResume(fp, r);
    fclose(fp);

    return 0;
}