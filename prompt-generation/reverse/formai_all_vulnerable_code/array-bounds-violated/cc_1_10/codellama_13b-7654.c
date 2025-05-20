//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
/*
 * C Resume Parsing System
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse a resume
void parse_resume(char *resume_text) {
    // Initialize variables
    char *name = NULL;
    char *email = NULL;
    char *phone = NULL;
    char *summary = NULL;
    char *education = NULL;
    char *experience = NULL;
    char *skills = NULL;

    // Split the resume text into sections
    char *sections[6] = {name, email, phone, summary, education, experience, skills};
    for (int i = 0; i < 6; i++) {
        sections[i] = strtok(resume_text, "\n");
        resume_text = NULL;
    }

    // Extract the relevant information from each section
    name = strtok(sections[0], ",");
    email = strtok(sections[1], ",");
    phone = strtok(sections[2], ",");
    summary = strtok(sections[3], ",");
    education = strtok(sections[4], ",");
    experience = strtok(sections[5], ",");
    skills = strtok(sections[6], ",");

    // Print the extracted information
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Summary: %s\n", summary);
    printf("Education: %s\n", education);
    printf("Experience: %s\n", experience);
    printf("Skills: %s\n", skills);
}

int main() {
    // Read the resume text from a file
    char resume_text[1024];
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fgets(resume_text, 1024, fp);
    fclose(fp);

    // Parse the resume
    parse_resume(resume_text);

    return 0;
}