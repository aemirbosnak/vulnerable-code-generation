//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char education[100];
    char skills[200];
    char experience[300];
} Resume;

void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
}

void parseResume(char* filename, Resume* r) {
    FILE* fp = fopen(filename, "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "Name:") != NULL) {
            line = strstr(line, "Name:");
            line += 5;
            strcpy(r->name, line);
            r->name[strcspn(r->name, "\r\n")] = 0;
        }
        else if (strstr(line, "Email:") != NULL) {
            line = strstr(line, "Email:");
            line += 6;
            strcpy(r->email, line);
            r->email[strcspn(r->email, "\r\n")] = 0;
        }
        else if (strstr(line, "Education:") != NULL) {
            line = strstr(line, "Education:");
            line += 10;
            strcpy(r->education, line);
            r->education[strcspn(r->education, "\r\n")] = 0;
        }
        else if (strstr(line, "Skills:") != NULL) {
            line = strstr(line, "Skills:");
            line += 7;
            strcpy(r->skills, line);
            r->skills[strcspn(r->skills, "\r\n")] = 0;
        }
        else if (strstr(line, "Experience:") != NULL) {
            line = strstr(line, "Experience:");
            line += 11;
            strcpy(r->experience, line);
            r->experience[strcspn(r->experience, "\r\n")] = 0;
        }
    }

    fclose(fp);
    if (line)
        free(line);
}

int main() {
    char filename[50];
    Resume r;

    printf("Enter the filename to parse: ");
    scanf("%s", filename);
    parseResume(filename, &r);
    printResume(r);

    return 0;
}