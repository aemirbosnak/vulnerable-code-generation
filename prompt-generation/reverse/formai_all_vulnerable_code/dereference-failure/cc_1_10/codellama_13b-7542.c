//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    typedef struct {
        char* name;
        char* email;
        char* phone;
        char* skills;
        char* education;
        char* experience;
    } Resume;

    Resume* parse_resume(char* resume_text) {
        Resume* resume = malloc(sizeof(Resume));

        // Extract name
        char* name_start = strstr(resume_text, "Name:");
        char* name_end = strstr(name_start, "\n");
        resume->name = malloc(name_end - name_start);
        strncpy(resume->name, name_start + 5, name_end - name_start);

        // Extract email
        char* email_start = strstr(resume_text, "Email:");
        char* email_end = strstr(email_start, "\n");
        resume->email = malloc(email_end - email_start);
        strncpy(resume->email, email_start + 6, email_end - email_start);

        // Extract phone
        char* phone_start = strstr(resume_text, "Phone:");
        char* phone_end = strstr(phone_start, "\n");
        resume->phone = malloc(phone_end - phone_start);
        strncpy(resume->phone, phone_start + 6, phone_end - phone_start);

        // Extract skills
        char* skills_start = strstr(resume_text, "Skills:");
        char* skills_end = strstr(skills_start, "\n");
        resume->skills = malloc(skills_end - skills_start);
        strncpy(resume->skills, skills_start + 7, skills_end - skills_start);

        // Extract education
        char* education_start = strstr(resume_text, "Education:");
        char* education_end = strstr(education_start, "\n");
        resume->education = malloc(education_end - education_start);
        strncpy(resume->education, education_start + 9, education_end - education_start);

        // Extract experience
        char* experience_start = strstr(resume_text, "Experience:");
        char* experience_end = strstr(experience_start, "\n");
        resume->experience = malloc(experience_end - experience_start);
        strncpy(resume->experience, experience_start + 10, experience_end - experience_start);

        return resume;
    }

    int main() {
        char* resume_text = "Name: John Doe\nEmail: johndoe@example.com\nPhone: 555-555-5555\nSkills: C, C++, Java\nEducation: Bachelor's in Computer Science\nExperience: 3 years";
        Resume* resume = parse_resume(resume_text);

        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone: %s\n", resume->phone);
        printf("Skills: %s\n", resume->skills);
        printf("Education: %s\n", resume->education);
        printf("Experience: %s\n", resume->experience);

        return 0;
    }