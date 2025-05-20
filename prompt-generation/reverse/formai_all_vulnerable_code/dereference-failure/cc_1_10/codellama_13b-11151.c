//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 256
#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_RESUME_LINES 500

typedef struct {
    char* name;
    char* email;
    char* phone;
    char* location;
    char* experience;
    char* skills;
    char* education;
} Resume;

Resume parse_resume(char* resume_text) {
    Resume resume;
    resume.name = malloc(MAX_LINE_LENGTH);
    resume.email = malloc(MAX_LINE_LENGTH);
    resume.phone = malloc(MAX_LINE_LENGTH);
    resume.location = malloc(MAX_LINE_LENGTH);
    resume.experience = malloc(MAX_PARAGRAPH_LENGTH);
    resume.skills = malloc(MAX_PARAGRAPH_LENGTH);
    resume.education = malloc(MAX_PARAGRAPH_LENGTH);

    // Split the resume text into lines
    char* lines[MAX_RESUME_LINES];
    int num_lines = 0;
    char* line = strtok(resume_text, "\n");
    while (line != NULL) {
        lines[num_lines] = line;
        num_lines++;
        line = strtok(NULL, "\n");
    }

    // Parse the resume text line by line
    for (int i = 0; i < num_lines; i++) {
        char* line = lines[i];
        char* keyword = strtok(line, " ");
        if (strcmp(keyword, "NAME") == 0) {
            char* name = strtok(NULL, " ");
            strcpy(resume.name, name);
        } else if (strcmp(keyword, "EMAIL") == 0) {
            char* email = strtok(NULL, " ");
            strcpy(resume.email, email);
        } else if (strcmp(keyword, "PHONE") == 0) {
            char* phone = strtok(NULL, " ");
            strcpy(resume.phone, phone);
        } else if (strcmp(keyword, "LOCATION") == 0) {
            char* location = strtok(NULL, " ");
            strcpy(resume.location, location);
        } else if (strcmp(keyword, "EXPERIENCE") == 0) {
            char* experience = strtok(NULL, " ");
            strcpy(resume.experience, experience);
        } else if (strcmp(keyword, "SKILLS") == 0) {
            char* skills = strtok(NULL, " ");
            strcpy(resume.skills, skills);
        } else if (strcmp(keyword, "EDUCATION") == 0) {
            char* education = strtok(NULL, " ");
            strcpy(resume.education, education);
        }
    }

    return resume;
}

int main() {
    char resume_text[MAX_PARAGRAPH_LENGTH];
    printf("Enter the resume text: ");
    fgets(resume_text, MAX_PARAGRAPH_LENGTH, stdin);
    Resume resume = parse_resume(resume_text);
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Location: %s\n", resume.location);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);
    printf("Education: %s\n", resume.education);
    return 0;
}