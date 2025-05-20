//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_PHONE_LEN 256
#define MAX_SKILL_LEN 256
#define MAX_EXPERIENCE_LEN 1024

struct resume {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
    char skills[MAX_SKILL_LEN];
    char experience[MAX_EXPERIENCE_LEN];
};

struct resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    struct resume *resume = malloc(sizeof(struct resume));
    if (resume == NULL) {
        fclose(fp);
        return NULL;
    }

    int line_number = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_number++;

        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line, "Name: %s", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line, "Email: %s", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line, "Phone: %s", resume->phone);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            sscanf(line, "Skills: %s", resume->skills);
        } else if (strncmp(line, "Experience:", 11) == 0) {
            sscanf(line, "Experience: %s", resume->experience);
        } else {
            printf("Error: Invalid line %d in resume file '%s'\n", line_number, filename);
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(struct resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    struct resume *resume = parse_resume(argv[1]);
    if (resume == NULL) {
        printf("Error: Couldn't parse resume file '%s'\n", argv[1]);
        return 1;
    }

    print_resume(resume);

    free(resume);

    return 0;
}