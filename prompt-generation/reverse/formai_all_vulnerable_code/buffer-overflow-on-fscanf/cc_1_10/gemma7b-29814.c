//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Resume {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

void parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    Resume resume;

    // Parse name
    fscanf(fp, "%s", resume.name);

    // Parse email
    fscanf(fp, "%s", resume.email);

    // Parse phone
    fscanf(fp, "%s", resume.phone);

    // Parse address
    fscanf(fp, "%s", resume.address);

    // Parse experience
    fscanf(fp, "%s", resume.experience);

    fclose(fp);

    // Print resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Experience: %s\n", resume.experience);
}

int main() {
    parse_resume("resume.txt");

    return 0;
}