//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_RESUME_LENGTH 10000

typedef struct {
    char name[MAX_WORD_LENGTH];
    char education[MAX_WORD_LENGTH];
    char experience[MAX_WORD_LENGTH];
    char skills[MAX_WORD_LENGTH];
} Resume;

Resume parseResume(char *resumeText) {
    Resume resume = { 0 };
    char *token;
    char *saveptr;
    int count = 0;

    token = strtok_r(resumeText, "\n", &saveptr);
    while (token!= NULL) {
        if (count == 0) {
            strcpy(resume.name, token);
        } else if (count == 1) {
            strcpy(resume.education, token);
        } else if (count == 2) {
            strcpy(resume.experience, token);
        } else if (count == 3) {
            strcpy(resume.skills, token);
        }
        count++;
        token = strtok_r(NULL, "\n", &saveptr);
    }

    return resume;
}

int main() {
    FILE *fp;
    char resumeText[MAX_RESUME_LENGTH];
    Resume resume;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (fileSize > MAX_RESUME_LENGTH) {
        printf("Resume is too long.\n");
        fclose(fp);
        exit(1);
    }

    fread(resumeText, fileSize, 1, fp);
    fclose(fp);

    resume = parseResume(resumeText);

    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}