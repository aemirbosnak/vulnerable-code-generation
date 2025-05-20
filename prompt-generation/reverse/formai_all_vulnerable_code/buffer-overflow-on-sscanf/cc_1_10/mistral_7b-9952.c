//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120
#define MAX_PROJECTS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char projects[MAX_PROJECTS][50];
} Resume;

void parse_resume(FILE *fp, Resume *resume) {
    char line[100];
    char token[20];
    int index = 0;

    fgets(line, sizeof(line), fp); // consume first line

    sscanf(line, "%s %s", token, resume->name);
    sscanf(line, "%d %s", &resume->age, token);

    while (fgets(line, sizeof(line), fp) && index < MAX_PROJECTS) {
        sscanf(line, "%s: %s", token, resume->projects[index]);
        index++;
    }
}

int main() {
    FILE *fp;
    Resume my_resume;

    fp = fopen("my_romantic_resume.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    parse_resume(fp, &my_resume);

    printf("Name: %s\n", my_resume.name);
    printf("Age: %d\n", my_resume.age);

    for (int i = 0; i < MAX_PROJECTS && my_resume.projects[i][0] != '\0'; i++) {
        printf("Project %d: %s\n", i + 1, my_resume.projects[i]);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}