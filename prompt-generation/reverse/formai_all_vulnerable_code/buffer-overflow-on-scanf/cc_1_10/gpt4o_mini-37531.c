//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LINES 100
#define MAX_LINE_LENGTH 256
#define NAME_TOKEN "Name:"
#define EMAIL_TOKEN "Email:"
#define PHONE_TOKEN "Phone:"
#define EDUCATION_TOKEN "Education:"
#define EXPERIENCE_TOKEN "Experience:"
#define SKILLS_TOKEN "Skills:"

typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[MAX_RESUME_LINES][MAX_LINE_LENGTH];
    char experience[MAX_RESUME_LINES][MAX_LINE_LENGTH];
    char skills[MAX_RESUME_LINES][MAX_LINE_LENGTH];
    int education_count;
    int experience_count;
    int skills_count;
} Resume;

void parse_line(const char *line, Resume *resume) {
    if (strncmp(line, NAME_TOKEN, strlen(NAME_TOKEN)) == 0) {
        sscanf(line + strlen(NAME_TOKEN), " %[^\n]", resume->name);
    } else if (strncmp(line, EMAIL_TOKEN, strlen(EMAIL_TOKEN)) == 0) {
        sscanf(line + strlen(EMAIL_TOKEN), " %[^\n]", resume->email);
    } else if (strncmp(line, PHONE_TOKEN, strlen(PHONE_TOKEN)) == 0) {
        sscanf(line + strlen(PHONE_TOKEN), " %[^\n]", resume->phone);
    } else if (strncmp(line, EDUCATION_TOKEN, strlen(EDUCATION_TOKEN)) == 0) {
        strcpy(resume->education[resume->education_count], line + strlen(EDUCATION_TOKEN));
        resume->education_count++;
    } else if (strncmp(line, EXPERIENCE_TOKEN, strlen(EXPERIENCE_TOKEN)) == 0) {
        strcpy(resume->experience[resume->experience_count], line + strlen(EXPERIENCE_TOKEN));
        resume->experience_count++;
    } else if (strncmp(line, SKILLS_TOKEN, strlen(SKILLS_TOKEN)) == 0) {
        strcpy(resume->skills[resume->skills_count], line + strlen(SKILLS_TOKEN));
        resume->skills_count++;
    }
}

void print_resume(const Resume *resume) {
    printf("-------- Resume --------\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    
    printf("\nEducation:\n");
    for (int i = 0; i < resume->education_count; i++) {
        printf("  %s\n", resume->education[i]);
    }

    printf("\nExperience:\n");
    for (int i = 0; i < resume->experience_count; i++) {
        printf("  %s\n", resume->experience[i]);
    }

    printf("\nSkills:\n");
    for (int i = 0; i < resume->skills_count; i++) {
        printf("  %s\n", resume->skills[i]);
    }
    printf("-------------------------\n");
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    Resume resume = {"", "", "", {{0}}, {{0}}, {{0}}, 0, 0, 0};
    
    printf("Enter the resume file name: ");
    char filename[MAX_LINE_LENGTH];
    scanf("%s", filename);
    
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    while (fgets(line, sizeof(line), file)) {
        parse_line(line, &resume);
    }

    fclose(file);
    
    print_resume(&resume);
    return EXIT_SUCCESS;
}