//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_NAME_LEN 64
#define MAX_EDU_LEN 128
#define MAX_EXP_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char education[MAX_EDU_LEN];
    char experience[MAX_EXP_LEN];
} Resume;

Resume parseResume(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    Resume resume = {0};

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (strstr(line, "Name:") == line) {
            strcpy(resume.name, line + strlen("Name:"));
        } else if (strstr(line, "Education:") == line) {
            strcpy(resume.education, line + strlen("Education:"));
        } else if (strstr(line, "Experience:") == line) {
            strcpy(resume.experience, line + strlen("Experience:"));
        }
    }

    fclose(fp);
    return resume;
}

int main() {
    char filename[MAX_LINE_LEN];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    Resume resume = parseResume(filename);

    printf("Name: %s\n", resume.name);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}