//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EDUCATION_LENGTH 50
#define MAX_SKILLS_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

void parse_resume(const char* resume_text, Resume* resume) {
    char* name = strtok(resume_text, ",");
    strcpy(resume->name, name);

    char* email = strtok(NULL, ",");
    strcpy(resume->email, email);

    char* phone = strtok(NULL, ",");
    strcpy(resume->phone, phone);

    char* education = strtok(NULL, ",");
    strcpy(resume->education, education);

    char* skills = strtok(NULL, ",");
    strcpy(resume->skills, skills);
}

int main() {
    Resume resume;
    char resume_text[MAX_RESUME_LENGTH];

    printf("Enter your resume text: ");
    scanf("%s", resume_text);

    parse_resume(resume_text, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Skills: %s\n", resume.skills);

    return 0;
}