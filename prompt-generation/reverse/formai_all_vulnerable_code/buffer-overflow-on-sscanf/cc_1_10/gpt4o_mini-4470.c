//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_SKILLS 10
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_NAME_LENGTH];
    int skill_count;
} Resume;

void initialize_resume(Resume *resume) {
    memset(resume->name, 0, sizeof(resume->name));
    memset(resume->email, 0, sizeof(resume->email));
    memset(resume->phone, 0, sizeof(resume->phone));
    resume->skill_count = 0;
}

void parse_line(char *line, Resume *resume) {
    if (strstr(line, "Name:") != NULL) {
        sscanf(line, "Name: %[^\n]", resume->name);
    } else if (strstr(line, "Email:") != NULL) {
        sscanf(line, "Email: %[^\n]", resume->email);
    } else if (strstr(line, "Phone:") != NULL) {
        sscanf(line, "Phone: %[^\n]", resume->phone);
    } else if (strstr(line, "Skills:") != NULL) {
        char *skill = strtok(line + strlen("Skills: "), ",");
        while (skill != NULL && resume->skill_count < MAX_SKILLS) {
            strcpy(resume->skills[resume->skill_count++], skill);
            skill = strtok(NULL, ",");
        }
    }
}

void print_resume(const Resume *resume) {
    printf("Parsed Resume:\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
}

void parse_resume_file(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening resume file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_line(line, resume);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    Resume resume;
    initialize_resume(&resume);
    parse_resume_file(argv[1], &resume);
    print_resume(&resume);
    
    return EXIT_SUCCESS;
}