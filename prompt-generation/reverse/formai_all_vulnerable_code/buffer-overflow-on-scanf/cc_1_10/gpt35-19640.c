//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[100];
    char email[50];
    char education[50];
    char skills[100];
    char experience[500];
};

char *get_field(char *line, int index) {
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
        if (i == index) {
            return token;
        }
        token = strtok(NULL, ",");
        i++;
    }
    return "";
}

int main() {
    char filename[50], line[1000];
    int count = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    printf("\nResume Parsing Results:\n");
    printf("----------------------------------------------\n");
    while (fgets(line, 1000, file) != NULL) {
        struct Resume resume;
        strcpy(resume.name, get_field(line, 0));
        strcpy(resume.email, get_field(line, 1));
        strcpy(resume.education, get_field(line, 2));
        strcpy(resume.skills, get_field(line, 3));
        strcpy(resume.experience, get_field(line, 4));
        printf("Name: %s\n", resume.name);
        printf("Email: %s\n", resume.email);
        printf("Education: %s\n", resume.education);
        printf("Skills: %s\n", resume.skills);
        printf("Experience: %s\n", resume.experience);
        printf("----------------------------------------------\n");
        count++;
    }
    fclose(file);
    printf("\nParsed %d resumes from file %s\n", count, filename);
    return 0;
}