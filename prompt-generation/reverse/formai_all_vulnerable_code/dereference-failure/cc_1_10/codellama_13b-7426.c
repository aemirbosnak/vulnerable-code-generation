//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
// C Resume Parsing System
// Sherlock Holmes style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_RESUME_LENGTH 5000

// Function to get the name from a resume
char *get_name(char *resume) {
    char *name = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *ptr = strchr(resume, '\n');
    if (ptr != NULL) {
        strncpy(name, resume, ptr - resume);
        name[ptr - resume] = '\0';
    } else {
        strcpy(name, resume);
    }
    return name;
}

// Function to get the skills from a resume
char **get_skills(char *resume) {
    char **skills = malloc(MAX_RESUME_LENGTH * sizeof(char *));
    char *ptr = resume;
    while (ptr != NULL) {
        char *skill = malloc(MAX_LINE_LENGTH * sizeof(char));
        ptr = strchr(ptr, '\n');
        if (ptr != NULL) {
            strncpy(skill, ptr + 1, MAX_LINE_LENGTH);
            skill[MAX_LINE_LENGTH - 1] = '\0';
            skills[ptr - resume] = skill;
        } else {
            skills[ptr - resume] = skill;
        }
    }
    return skills;
}

// Function to get the education from a resume
char *get_education(char *resume) {
    char *education = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *ptr = strstr(resume, "Education");
    if (ptr != NULL) {
        ptr = strchr(ptr, '\n');
        if (ptr != NULL) {
            strncpy(education, ptr + 1, MAX_LINE_LENGTH);
            education[MAX_LINE_LENGTH - 1] = '\0';
        } else {
            strcpy(education, "");
        }
    } else {
        strcpy(education, "");
    }
    return education;
}

// Function to get the experience from a resume
char *get_experience(char *resume) {
    char *experience = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *ptr = strstr(resume, "Experience");
    if (ptr != NULL) {
        ptr = strchr(ptr, '\n');
        if (ptr != NULL) {
            strncpy(experience, ptr + 1, MAX_LINE_LENGTH);
            experience[MAX_LINE_LENGTH - 1] = '\0';
        } else {
            strcpy(experience, "");
        }
    } else {
        strcpy(experience, "");
    }
    return experience;
}

// Function to get the references from a resume
char *get_references(char *resume) {
    char *references = malloc(MAX_LINE_LENGTH * sizeof(char));
    char *ptr = strstr(resume, "References");
    if (ptr != NULL) {
        ptr = strchr(ptr, '\n');
        if (ptr != NULL) {
            strncpy(references, ptr + 1, MAX_LINE_LENGTH);
            references[MAX_LINE_LENGTH - 1] = '\0';
        } else {
            strcpy(references, "");
        }
    } else {
        strcpy(references, "");
    }
    return references;
}

// Function to parse the resume
void parse_resume(char *resume) {
    char *name = get_name(resume);
    char **skills = get_skills(resume);
    char *education = get_education(resume);
    char *experience = get_experience(resume);
    char *references = get_references(resume);

    // Print the resume details
    printf("Name: %s\n", name);
    printf("Skills: ");
    for (int i = 0; skills[i] != NULL; i++) {
        printf("%s ", skills[i]);
    }
    printf("\nEducation: %s\n", education);
    printf("Experience: %s\n", experience);
    printf("References: %s\n", references);

    // Free the memory
    free(name);
    free(skills);
    free(education);
    free(experience);
    free(references);
}

// Main function
int main() {
    // Sample resume
    char *resume = "John Doe\n"
                  "Skills: C, C++, Java\n"
                  "Education: Bachelor's in Computer Science\n"
                  "Experience: 2 years\n"
                  "References: Available upon request";

    // Parse the resume
    parse_resume(resume);

    return 0;
}