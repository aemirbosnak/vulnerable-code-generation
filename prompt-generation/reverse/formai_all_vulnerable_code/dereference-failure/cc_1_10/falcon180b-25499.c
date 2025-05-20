//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    int experience;
    char education[100];
    char skills[200];
} Candidate;

void read_csv(FILE *fp, Candidate *candidate) {
    char line[1000];
    char *token;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(candidate->name, token);

        token = strtok(NULL, ",");
        strcpy(candidate->email, token);

        token = strtok(NULL, ",");
        strcpy(candidate->phone, token);

        token = strtok(NULL, ",");
        candidate->experience = atoi(token);

        token = strtok(NULL, ",");
        strcpy(candidate->education, token);

        token = strtok(NULL, ",");
        strcpy(candidate->skills, token);
    }
}

int main() {
    FILE *fp;
    Candidate candidate;

    fp = fopen("resume.csv", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    read_csv(fp, &candidate);

    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Experience: %d years\n", candidate.experience);
    printf("Education: %s\n", candidate.education);
    printf("Skills: %s\n", candidate.skills);

    fclose(fp);
    return 0;
}