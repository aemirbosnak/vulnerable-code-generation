//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_COMPANY_LENGTH 100
#define MAX_EDUCATION_LENGTH 100
#define MAX_SKILL_LENGTH 100
#define MAX_LANGUAGE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char company[MAX_COMPANY_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skill[MAX_SKILL_LENGTH];
    char language[MAX_LANGUAGE_LENGTH];
} Resume;

Resume* createResume() {
    Resume* resume = (Resume*) malloc(sizeof(Resume));
    strcpy(resume->name, "");
    strcpy(resume->company, "");
    strcpy(resume->education, "");
    strcpy(resume->skill, "");
    strcpy(resume->language, "");
    return resume;
}

void freeResume(Resume* resume) {
    free(resume);
}

char* extractName(char* input) {
    char* name = (char*) malloc(MAX_NAME_LENGTH * sizeof(char));
    int i = 0;
    while (i < strlen(input) && input[i]!= ',') {
        name[i] = input[i];
        i++;
    }
    name[i] = '\0';
    return name;
}

char* extractCompany(char* input) {
    char* company = (char*) malloc(MAX_COMPANY_LENGTH * sizeof(char));
    int i = 0;
    while (i < strlen(input) && input[i]!= ',') {
        company[i] = input[i];
        i++;
    }
    company[i] = '\0';
    return company;
}

char* extractEducation(char* input) {
    char* education = (char*) malloc(MAX_EDUCATION_LENGTH * sizeof(char));
    int i = 0;
    while (i < strlen(input) && input[i]!= ',') {
        education[i] = input[i];
        i++;
    }
    education[i] = '\0';
    return education;
}

char* extractSkill(char* input) {
    char* skill = (char*) malloc(MAX_SKILL_LENGTH * sizeof(char));
    int i = 0;
    while (i < strlen(input) && input[i]!= ',') {
        skill[i] = input[i];
        i++;
    }
    skill[i] = '\0';
    return skill;
}

char* extractLanguage(char* input) {
    char* language = (char*) malloc(MAX_LANGUAGE_LENGTH * sizeof(char));
    int i = 0;
    while (i < strlen(input) && input[i]!= ',') {
        language[i] = input[i];
        i++;
    }
    language[i] = '\0';
    return language;
}

void printResume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Company: %s\n", resume->company);
    printf("Education: %s\n", resume->education);
    printf("Skill: %s\n", resume->skill);
    printf("Language: %s\n", resume->language);
}

int main() {
    char* input = "John Doe,Google,Stanford,Programming,English";
    char* name = extractName(input);
    char* company = extractCompany(input);
    char* education = extractEducation(input);
    char* skill = extractSkill(input);
    char* language = extractLanguage(input);

    Resume* resume = createResume();

    strcpy(resume->name, name);
    strcpy(resume->company, company);
    strcpy(resume->education, education);
    strcpy(resume->skill, skill);
    strcpy(resume->language, language);

    printResume(resume);

    freeResume(resume);
    free(name);
    free(company);
    free(education);
    free(skill);
    free(language);

    return 0;
}