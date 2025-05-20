//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 50
#define MAX_SKILLS 10
#define MAX_SKILL_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char skills[MAX_SKILLS][MAX_SKILL_LEN];
    int num_skills;
} Resume;

int main() {
    Resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    char filename[50];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        Resume resume;
        char *token = strtok(line, ",");
        strcpy(resume.name, token);

        token = strtok(NULL, ",");
        strcpy(resume.email, token);

        token = strtok(NULL, ",");
        int i = 0;
        while (token) {
            strcpy(resume.skills[i], token);
            resume.num_skills++;
            token = strtok(NULL, ",");
            i++;
        }

        resumes[num_resumes] = resume;
        num_resumes++;
    }

    fclose(fp);

    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Skills (%d): ", resumes[i].num_skills);
        for (int j = 0; j < resumes[i].num_skills; j++) {
            printf("%s ", resumes[i].skills[j]);
        }
        printf("\n\n");
    }

    return 0;
}