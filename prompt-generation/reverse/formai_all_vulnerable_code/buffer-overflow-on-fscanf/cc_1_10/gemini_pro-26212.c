//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_SKILL_LEN 25

struct resume {
    char name[MAX_NAME_LEN];
    char skills[MAX_SKILL_LEN][MAX_SKILL_LEN];
    int num_skills;
};

struct resume *read_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%s\n", resume->name);

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *skill = strtok(line, ",");
        while (skill != NULL) {
            strcpy(resume->skills[resume->num_skills], skill);
            resume->num_skills++;
            skill = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(struct resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Skills:\n");
    for (int i = 0; i < resume->num_skills; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct resume *resume = read_resume(argv[1]);
    if (resume == NULL) {
        return EXIT_FAILURE;
    }

    print_resume(resume);

    return EXIT_SUCCESS;
}