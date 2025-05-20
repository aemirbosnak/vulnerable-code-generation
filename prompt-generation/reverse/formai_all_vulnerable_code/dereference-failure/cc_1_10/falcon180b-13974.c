//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    int experience;
} Resume;

Resume parseResume(char *line) {
    Resume r = {0};
    char *token = strtok(line, ",");
    while (token!= NULL) {
        if (strcasecmp(token, "Name") == 0) {
            strcpy(r.name, strtok(NULL, ","));
        } else if (strcasecmp(token, "Email") == 0) {
            strcpy(r.email, strtok(NULL, ","));
        } else if (strcasecmp(token, "Phone") == 0) {
            strcpy(r.phone, strtok(NULL, ","));
        } else if (strcasecmp(token, "Address") == 0) {
            strcpy(r.address, strtok(NULL, ","));
        } else if (strcasecmp(token, "Experience") == 0) {
            r.experience = atoi(strtok(NULL, ","));
        }
        token = strtok(NULL, ",");
    }
    return r;
}

void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Experience: %d\n", r.experience);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    Resume r;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        r = parseResume(line);
        printResume(r);
    }

    fclose(fp);
    return 0;
}