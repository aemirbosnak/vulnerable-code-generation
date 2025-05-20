//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

void parse_resume(const char *resume_text, Resume *resume) {
    // Reset resume
    memset(resume, 0, sizeof(Resume));
    
    // Simulating parsing, using simple string operations
    sscanf(resume_text, "Name: %[^\n]\nEmail: %[^\n]\nPhone: %[^\n]\n", 
           resume->name, resume->email, resume->phone);

    // Assuming skills are listed at the end, line by line
    char *line;
    char *token;
    char temp_text[strlen(resume_text) + 1]; // Temporary buffer
    strcpy(temp_text, resume_text);
    
    line = strtok(temp_text, "\n");
    while (line != NULL) {
        if (strstr(line, "Skill:") != NULL) {
            token = strtok(line, "Skill: ");
            if (token != NULL && resume->skill_count < MAX_SKILLS) {
                strncpy(resume->skills[resume->skill_count], token, MAX_SKILL_LENGTH);
                resume->skill_count++;
            }
        }
        line = strtok(NULL, "\n");
    }
}

void display_resume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf(" - %s\n", resume->skills[i]);
    }
}

void display_all_resumes(Resume resumes[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nResume %d:\n", i + 1);
        display_resume(&resumes[i]);
    }
}

int main() {
    Resume resumes[MAX_RESUMES];
    char *raw_resumes[MAX_RESUMES];
    int resume_count = 0;

    // Example resumes in a string format
    raw_resumes[0] = "Name: John Doe\nEmail: john@example.com\nPhone: 123-456-7890\nSkill: C\nSkill: C++\nSkill: Python\n";
    raw_resumes[1] = "Name: Jane Smith\nEmail: jane@example.com\nPhone: 987-654-3210\nSkill: Java\nSkill: JavaScript\n";
    raw_resumes[2] = "Name: Alice Johnson\nEmail: alice@example.com\nPhone: 555-555-5555\nSkill: Go\nSkill: Ruby\nSkill: Rust\n";

    // Parsing resumes
    for (int i = 0; i < 3; i++) {
        parse_resume(raw_resumes[i], &resumes[resume_count]);
        resume_count++;
    }

    // Displaying all parsed resumes
    display_all_resumes(resumes, resume_count);

    return 0;
}