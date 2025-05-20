//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_SKILLS 10
#define MAX_EXPERIENCE 5

typedef struct {
    char name[MAX_NAME_LEN];
    char skills[MAX_SKILLS][MAX_NAME_LEN];
    int num_skills;
    int experience[MAX_EXPERIENCE][3];
} Resume;

void parse_name(char line[], Resume *resume) {
    strcpy(resume->name, line);
}

void parse_skills(char line[], Resume *resume) {
    int i = resume->num_skills;
    char *token = strtok(line, ";");
    while (token != NULL && i < MAX_SKILLS) {
        strcpy(resume->skills[i], token);
        i++;
        token = strtok(NULL, ";");
    }
    resume->num_skills = i;
}

void parse_experience(char line[], Resume *resume, int index) {
    int i = 0;
    char *token = strtok(line, ":");
    while (token != NULL && i < 3) {
        switch (i) {
            case 0:
                resume->experience[index][i] = atoi(token);
                break;
            case 1:
                strcpy(resume->experience[index][i], strtok(NULL, " "));
                break;
            case 2:
                strcpy(resume->experience[index][i], strtok(NULL, ":"));
                break;
        }
        token = strtok(NULL, ":");
        i++;
    }
}

void parse_line(char line[], Resume *resume) {
    if (sscanf(line, "%s;%s", parse_name, parse_skills) == 2) {
        resume->num_skills++;
    } else if (resume->num_skills < MAX_EXPERIENCE) {
        parse_experience(line, resume, resume->num_skills);
        resume->num_skills++;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    Resume resumes[10];
    char line[100];
    int i = 0;

    fp = fopen(argv[1], "r");
    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_line(line, &resumes[i]);
        i++;
    }
    fclose(fp);

    for (int j = 0; j < i; j++) {
        printf("\nName: %s\n", resumes[j].name);
        printf("Skills:\n");
        for (int k = 0; k < resumes[j].num_skills; k++) {
            printf("%s\n", resumes[j].skills[k]);
        }
        printf("Experience:\n");
        for (int k = 0; k < resumes[j].num_skills && k < MAX_EXPERIENCE; k++) {
            printf("Company: %s, Position: %s, Years: %d\n", resumes[j].experience[k][1], resumes[j].experience[k][2], resumes[j].experience[k][0]);
        }
    }

    return 0;
}