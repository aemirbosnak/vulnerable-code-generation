//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SKILL_LEN 20
#define MAX_EXP_LEN 100
#define NUM_FIELDS 4

typedef struct {
    char name[MAX_NAME_LEN];
    char skills[NUM_FIELDS][MAX_SKILL_LEN];
    char experience[MAX_EXP_LEN];
} Candidate;

int main() {
    FILE *fp;
    Candidate resumes[10];
    char line[100];
    int index = 0;

    fp = fopen("resumes.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^:]: %[^:]: %[^:]: %[^\n]",
               resumes[index].name,
               resumes[index].skills[0],
               resumes[index].skills[1],
               resumes[index].experience);

        index++;
        if (index >= 10) {
            printf("Maximum number of resumes reached.\n");
            break;
        }
    }

    fclose(fp);

    for (int i = 0; i < index; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Skills:\n");
        for (int j = 0; j < NUM_FIELDS; j++) {
            printf("- %s\n", resumes[i].skills[j]);
        }
        printf("Experience: %s\n", resumes[i].experience);
        printf("\n");
    }

    return 0;
}