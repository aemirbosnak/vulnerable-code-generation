//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct resume {
    char name[100];
    char company[100];
    char position[100];
    char skills[100];
};

int parse_resume(FILE *file, struct resume *resume) {
    char line[1000];
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s", resume->name);
            i = 0;
        } else if (strncmp(line, "Company:", 7) == 0) {
            sscanf(line, "Company: %s", resume->company);
            i = 0;
        } else if (strncmp(line, "Position:", 8) == 0) {
            sscanf(line, "Position: %s", resume->position);
            i = 0;
        } else if (strncmp(line, "Skills:", 6) == 0) {
            sscanf(line, "Skills: %s", resume->skills);
            i = 0;
        } else {
            resume->skills[i++] = line[0];
        }
    }

    resume->skills[i] = '\0';
    return 0;
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    struct resume resume;

    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    if (parse_resume(file, &resume)!= 0) {
        printf("Parsing error\n");
        exit(1);
    }

    printf("Name: %s\n", resume.name);
    printf("Company: %s\n", resume.company);
    printf("Position: %s\n", resume.position);
    printf("Skills: %s\n", resume.skills);

    fclose(file);
    return 0;
}