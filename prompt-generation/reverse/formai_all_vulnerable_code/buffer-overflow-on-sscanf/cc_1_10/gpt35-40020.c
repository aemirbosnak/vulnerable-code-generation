//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[50][100]; // An array of 50 education entries each with 100 characters
    int num_education_entries;
    char experience[50][100]; // An array of 50 experience entries each with 100 characters
    int num_experience_entries;
    char skills[50][100];  // An array of 50 skill entries each with 100 characters
    int num_skill_entries;
};

void parse_resume(struct Resume *r, char *filename) {
    FILE *fp;
    char buffer[1000];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Parse name
    fgets(buffer, 1000, fp);
    sscanf(buffer, "%s", r->name);

    // Parse email
    fgets(buffer, 1000, fp);
    sscanf(buffer, "%s", r->email);

    // Parse phone
    fgets(buffer, 1000, fp);
    sscanf(buffer, "%s", r->phone);

    // Parse education
    r->num_education_entries = 0;
    while (fgets(buffer, 1000, fp) != NULL && strncmp(buffer, "Experience", 9) != 0) {
        sscanf(buffer, "%s", r->education[r->num_education_entries]);
        r->num_education_entries++;
    }

    // Parse experience
    r->num_experience_entries = 0;
    while (fgets(buffer, 1000, fp) != NULL && strncmp(buffer, "Skills", 6) != 0) {
        sscanf(buffer, "%s", r->experience[r->num_experience_entries]);
        r->num_experience_entries++;
    }

    // Parse skills
    r->num_skill_entries = 0;
    while (fgets(buffer, 1000, fp) != NULL) {
        sscanf(buffer, "%s", r->skills[r->num_skill_entries]);
        r->num_skill_entries++;
    }

    fclose(fp);
}

void print_resume(struct Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);

    printf("Education:\n");
    for (int i = 0; i < r->num_education_entries; i++) {
        printf("- %s\n", r->education[i]);
    }

    printf("Experience:\n");
    for (int i = 0; i < r->num_experience_entries; i++) {
        printf("- %s\n", r->experience[i]);
    }

    printf("Skills:\n");
    for (int i = 0; i < r->num_skill_entries; i++) {
        printf("- %s\n", r->skills[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }

    struct Resume r;
    parse_resume(&r, argv[1]);

    printf("Parsed Resume:\n");
    print_resume(&r);

    return 0;
}