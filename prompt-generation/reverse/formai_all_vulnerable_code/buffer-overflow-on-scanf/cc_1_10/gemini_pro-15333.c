//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct resume {
    char *name;
    char *email;
    char *phone;
    char *skills[10];
    int numSkills;
};

void parseResume(char *filename, struct resume *r) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Parse the name
        if (strstr(buffer, "Name:")) {
            r->name = strdup(buffer + 6);
            r->name[strlen(r->name) - 1] = '\0';
        }
        // Parse the email
        else if (strstr(buffer, "Email:")) {
            r->email = strdup(buffer + 7);
            r->email[strlen(r->email) - 1] = '\0';
        }
        // Parse the phone
        else if (strstr(buffer, "Phone:")) {
            r->phone = strdup(buffer + 7);
            r->phone[strlen(r->phone) - 1] = '\0';
        }
        // Parse the skills
        else if (strstr(buffer, "Skills:")) {
            char *skills = strdup(buffer + 8);
            char *skill;
            while ((skill = strtok(skills, ", ")) != NULL) {
                r->skills[r->numSkills] = strdup(skill);
                r->numSkills++;
                skills = NULL;
            }
        }
    }

    fclose(fp);
}

void printResume(struct resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Skills: ");
    for (int i = 0; i < r->numSkills; i++) {
        printf("%s, ", r->skills[i]);
    }
    printf("\n");
}

int main() {
    struct resume r;

    char filename[100];
    printf("Enter the filename of the resume: ");
    scanf("%s", filename);

    parseResume(filename, &r);
    printResume(&r);

    return 0;
}