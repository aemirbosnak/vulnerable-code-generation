//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SECTION_LEN 100
#define MAX_SECTIONS 10

typedef struct {
    char name[MAX_NAME_LEN];
    char sections[MAX_SECTIONS][MAX_SECTION_LEN];
    int num_sections;
} Resume;

Resume parse_resume(FILE *file) {
    Resume resume = {0};
    char line[100];
    int i = 0;
    char delim = ',';

    while (fgets(line, 100, file)!= NULL) {
        if (i == 0) {
            strcpy(resume.name, line);
        } else if (i < MAX_SECTIONS) {
            char *token = strtok(line, &delim);
            while (token!= NULL) {
                strcpy(resume.sections[i], token);
                i++;
                token = strtok(NULL, &delim);
            }
            resume.num_sections = i;
        }
        i++;
    }

    return resume;
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Sections:\n");
    for (int i = 0; i < resume.num_sections; i++) {
        printf("\t%s\n", resume.sections[i]);
    }
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Resume resume = parse_resume(file);
    print_resume(resume);

    fclose(file);
    return 0;
}