//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
    char skills[200];
};

void parseResume(struct Resume *res, char *filename);
void printResume(struct Resume res);

int main() {
    struct Resume myResume;
    char filename[50];
    printf("Enter resume filename: ");
    scanf("%s", filename);
    parseResume(&myResume, filename);
    printResume(myResume);
    return 0;
}

void parseResume(struct Resume *res, char *filename) {
    FILE *fp;
    char line[200];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(1);
    }
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            char *ptr = strchr(line, ':');
            strcpy(res->name, ptr + 1);
        } else if (strstr(line, "Email:")) {
            char *ptr = strchr(line, ':');
            strcpy(res->email, ptr + 1);
        } else if (strstr(line, "Phone:")) {
            char *ptr = strchr(line, ':');
            strcpy(res->phone, ptr + 1);
        } else if (strstr(line, "Education:")) {
            char education[100] = "";
            while (fgets(line, sizeof(line), fp) && !strstr(line, "Experience:")) {
                strcat(education, line);
            }
            strcpy(res->education, education);
            continue;
        } else if (strstr(line, "Experience:")) {
            char experience[200] = "";
            while (fgets(line, sizeof(line), fp) && !strstr(line, "Skills:")) {
                strcat(experience, line);
            }
            strcpy(res->experience, experience);
            continue;
        } else if (strstr(line, "Skills:")) {
            char skills[200] = "";
            while (fgets(line, sizeof(line), fp)) {
                strcat(skills, line);
            }
            strcpy(res->skills, skills);
            continue;
        }
    }
    fclose(fp);
}

void printResume(struct Resume res) {
    printf("Name: %s", res.name);
    printf("Email: %s", res.email);
    printf("Phone: %s", res.phone);
    printf("Education:\n%s", res.education);
    printf("Experience:\n%s", res.experience);
    printf("Skills:\n%s", res.skills);
}