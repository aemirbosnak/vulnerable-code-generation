//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: rigorous
/*
 * resume_parser.c
 *
 * A unique C Resume Parsing System example program.
 *
 * This program takes a resume file as input and parses it to extract
 * relevant information such as name, contact information, skills,
 * experience, and education.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 256
#define MAX_SKILLS_LENGTH 1024

// Structure to hold resume information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char contact_info[MAX_LINE_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
    char experience[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
} Resume;

// Function to parse a resume file and populate a Resume structure
void parse_resume(FILE *fp, Resume *resume) {
    char line[MAX_LINE_LENGTH];
    char *token;

    // Read the first line of the resume file
    fgets(line, MAX_LINE_LENGTH, fp);

    // Extract the name from the first line
    token = strtok(line, " ");
    strcpy(resume->name, token);

    // Extract the contact information from the first line
    token = strtok(NULL, " ");
    strcpy(resume->contact_info, token);

    // Extract the skills from the first line
    token = strtok(NULL, " ");
    strcpy(resume->skills, token);

    // Extract the experience from the second line
    fgets(line, MAX_LINE_LENGTH, fp);
    token = strtok(line, " ");
    strcpy(resume->experience, token);

    // Extract the education from the third line
    fgets(line, MAX_LINE_LENGTH, fp);
    token = strtok(line, " ");
    strcpy(resume->education, token);
}

// Function to print the parsed resume information
void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Contact Information: %s\n", resume.contact_info);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);
}

int main() {
    Resume resume;
    FILE *fp;

    // Open the resume file
    fp = fopen("resume.txt", "r");

    // Parse the resume file and populate the Resume structure
    parse_resume(fp, &resume);

    // Print the parsed resume information
    print_resume(resume);

    // Close the resume file
    fclose(fp);

    return 0;
}