//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_SKILLS 10

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char address[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH];
    char skills[MAX_SKILLS][MAX_LENGTH];
    int num_skills;
} resume;

void parse_resume(char *filename, resume *r) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    char line[MAX_LENGTH];
    int in_education = 0;
    int in_experience = 0;

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        // Remove trailing newline character
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (strcmp(line, "EDUCATION") == 0) {
            in_education = 1;
            in_experience = 0;
        } else if (strcmp(line, "EXPERIENCE") == 0) {
            in_education = 0;
            in_experience = 1;
        } else if (in_education) {
            strcat(r->education, line);
        } else if (in_experience) {
            strcat(r->experience, line);
        } else {
            if (strstr(line, "Name:") != NULL) {
                sscanf(line, "%*s %[^\n]", r->name);
            } else if (strstr(line, "Email:") != NULL) {
                sscanf(line, "%*s %[^\n]", r->email);
            } else if (strstr(line, "Phone:") != NULL) {
                sscanf(line, "%*s %[^\n]", r->phone);
            } else if (strstr(line, "Address:") != NULL) {
                sscanf(line, "%*s %[^\n]", r->address);
            } else if (strstr(line, "Skills:") != NULL) {
                char *token = strtok(line, ":");
                token = strtok(NULL, ":");
                char *skill = strtok(token, ",");
                while (skill != NULL) {
                    strcpy(r->skills[r->num_skills], skill);
                    r->num_skills++;
                    skill = strtok(NULL, ",");
                }
            }
        }
    }

    fclose(fp);
}

void print_resume(resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
    printf("Skills:");
    for (int i = 0; i < r->num_skills; i++) {
        printf(" %s", r->skills[i]);
    }
    printf("\n");
}

int main(void) {
    resume r;
    memset(&r, 0, sizeof(resume));

    parse_resume("resume.txt", &r);
    print_resume(&r);

    return 0;
}