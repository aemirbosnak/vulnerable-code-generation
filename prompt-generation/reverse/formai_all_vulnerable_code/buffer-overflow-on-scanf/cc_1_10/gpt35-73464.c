//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    int age;
    char email[50];
    char phone_number[15];
    char skills[500];
    char experience[500];
    char education[100];
};

void parseResume(struct Resume *r, char *filename) {
    FILE *fp;
    char line[500];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            strcpy(r->name, line + strlen("Name:"));
        } else if (strstr(line, "Age:")) {
            r->age = atoi(line + strlen("Age:"));
        } else if (strstr(line, "Email:")) {
            strcpy(r->email, line + strlen("Email:"));
        } else if (strstr(line, "Phone:")) {
            strcpy(r->phone_number, line + strlen("Phone:"));
        } else if (strstr(line, "Skills:")) {
            strcpy(r->skills, line + strlen("Skills:"));
        } else if (strstr(line, "Experience:")) {
            strcpy(r->experience, line + strlen("Experience:"));
        } else if (strstr(line, "Education:")) {
            strcpy(r->education, line + strlen("Education:"));
        }
    }

    fclose(fp);
}

void printResume(struct Resume *r) {
    printf("Name: %s", r->name);
    printf("Age: %d\n", r->age);
    printf("Email: %s", r->email);
    printf("Phone: %s", r->phone_number);
    printf("Skills: %s", r->skills);
    printf("Experience: %s", r->experience);
    printf("Education: %s", r->education);
}

int main() {
    struct Resume r;
    char filename[50];

    printf("Enter resume filename: ");
    scanf("%s", filename);

    parseResume(&r, filename);

    printResume(&r);

    return 0;
}