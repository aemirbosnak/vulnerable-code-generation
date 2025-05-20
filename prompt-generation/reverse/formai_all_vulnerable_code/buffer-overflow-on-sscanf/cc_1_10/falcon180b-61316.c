//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_COMPANY_LEN 100
#define MAX_POSITION_LEN 100
#define MAX_EDUCATION_LEN 100
#define MAX_SKILL_LEN 100

#define MAX_LINE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char company[MAX_COMPANY_LEN];
    char position[MAX_POSITION_LEN];
    char education[MAX_EDUCATION_LEN];
    char skills[MAX_SKILL_LEN];
} Resume;

void readResume(Resume *resume) {
    char line[MAX_LINE_LEN];
    int lineNum = 0;
    while (fgets(line, MAX_LINE_LEN, stdin)!= NULL) {
        lineNum++;
        if (lineNum == 1) {
            sscanf(line, "%s", resume->name);
        } else if (lineNum == 2) {
            sscanf(line, "%s", resume->company);
        } else if (lineNum == 3) {
            sscanf(line, "%s", resume->position);
        } else if (lineNum == 4) {
            sscanf(line, "%s", resume->education);
        } else if (lineNum == 5) {
            sscanf(line, "%s", resume->skills);
        }
    }
}

void printResume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Company: %s\n", resume->company);
    printf("Position: %s\n", resume->position);
    printf("Education: %s\n", resume->education);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    Resume resume;
    readResume(&resume);
    printResume(&resume);
    return 0;
}