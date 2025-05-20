//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_NAME_SIZE 64
#define MAX_COMPANY_SIZE 64
#define MAX_POSITION_SIZE 64
#define MAX_SKILLS_SIZE 256

typedef struct {
    char name[MAX_NAME_SIZE];
    char company[MAX_COMPANY_SIZE];
    char position[MAX_POSITION_SIZE];
    char skills[MAX_SKILLS_SIZE];
} resume_t;

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int count = 0;
    resume_t resume;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (line[0] == '#') {
            if (count == 0) {
                sscanf(line, "# Name: %s", resume.name);
            } else if (count == 1) {
                sscanf(line, "# Company: %s", resume.company);
            } else if (count == 2) {
                sscanf(line, "# Position: %s", resume.position);
            } else if (count == 3) {
                sscanf(line, "# Skills: %s", resume.skills);
            }
            count++;
        }
    }

    printf("Name: %s\n", resume.name);
    printf("Company: %s\n", resume.company);
    printf("Position: %s\n", resume.position);
    printf("Skills: %s\n", resume.skills);

    fclose(fp);

    return 0;
}