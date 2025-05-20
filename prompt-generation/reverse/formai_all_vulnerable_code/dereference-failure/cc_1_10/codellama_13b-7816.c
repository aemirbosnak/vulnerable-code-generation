//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: complex
// C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures

struct Resume {
    char name[100];
    char email[100];
    char phone[100];
    char job_title[100];
    char company[100];
    char location[100];
    char education[100];
    char experience[100];
    char skills[100];
};

struct Resume resume;

// Functions

void print_resume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Job Title: %s\n", resume.job_title);
    printf("Company: %s\n", resume.company);
    printf("Location: %s\n", resume.location);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);
    printf("Skills: %s\n", resume.skills);
}

void parse_resume(char *resume_text) {
    // Parse name
    char *name_end = strchr(resume_text, '\n');
    strncpy(resume.name, resume_text, name_end - resume_text);

    // Parse email
    char *email_start = strchr(name_end + 1, '<');
    char *email_end = strchr(email_start, '>');
    strncpy(resume.email, email_start + 1, email_end - email_start - 1);

    // Parse phone
    char *phone_start = strchr(email_end + 1, '(');
    char *phone_end = strchr(phone_start, ')');
    strncpy(resume.phone, phone_start + 1, phone_end - phone_start - 1);

    // Parse job title
    char *job_title_start = strchr(phone_end + 1, ',');
    char *job_title_end = strchr(job_title_start, '\n');
    strncpy(resume.job_title, job_title_start + 1, job_title_end - job_title_start - 1);

    // Parse company
    char *company_start = strchr(job_title_end + 1, ',');
    char *company_end = strchr(company_start, '\n');
    strncpy(resume.company, company_start + 1, company_end - company_start - 1);

    // Parse location
    char *location_start = strchr(company_end + 1, ',');
    char *location_end = strchr(location_start, '\n');
    strncpy(resume.location, location_start + 1, location_end - location_start - 1);

    // Parse education
    char *education_start = strchr(location_end + 1, ',');
    char *education_end = strchr(education_start, '\n');
    strncpy(resume.education, education_start + 1, education_end - education_start - 1);

    // Parse experience
    char *experience_start = strchr(education_end + 1, ',');
    char *experience_end = strchr(experience_start, '\n');
    strncpy(resume.experience, experience_start + 1, experience_end - experience_start - 1);

    // Parse skills
    char *skills_start = strchr(experience_end + 1, ',');
    char *skills_end = strchr(skills_start, '\n');
    strncpy(resume.skills, skills_start + 1, skills_end - skills_start - 1);
}

int main() {
    // Get resume text from user
    char resume_text[1000];
    printf("Enter resume text: ");
    fgets(resume_text, 1000, stdin);

    // Parse resume
    parse_resume(resume_text);

    // Print resume
    print_resume(resume);

    return 0;
}