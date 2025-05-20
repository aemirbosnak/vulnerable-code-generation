//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
} resume;

int main() {
    // Read the resume from the user.
    char *resume_text = malloc(1024);
    printf("Enter your resume: ");
    scanf("%s", resume_text);

    // Parse the name.
    char *name_start = strstr(resume_text, "Name: ");
    if (name_start == NULL) {
        printf("Error: Name not found in resume.\n");
        return 1;
    }
    char *name_end = strchr(name_start, '\n');
    if (name_end == NULL) {
        printf("Error: Name not found in resume.\n");
        return 1;
    }
    char *name = malloc(name_end - name_start + 1);
    strncpy(name, name_start + 6, name_end - name_start - 6);

    // Parse the email.
    char *email_start = strstr(resume_text, "Email: ");
    if (email_start == NULL) {
        printf("Error: Email not found in resume.\n");
        return 1;
    }
    char *email_end = strchr(email_start, '\n');
    if (email_end == NULL) {
        printf("Error: Email not found in resume.\n");
        return 1;
    }
    char *email = malloc(email_end - email_start + 1);
    strncpy(email, email_start + 7, email_end - email_start - 7);

    // Parse the phone.
    char *phone_start = strstr(resume_text, "Phone: ");
    if (phone_start == NULL) {
        printf("Error: Phone not found in resume.\n");
        return 1;
    }
    char *phone_end = strchr(phone_start, '\n');
    if (phone_end == NULL) {
        printf("Error: Phone not found in resume.\n");
        return 1;
    }
    char *phone = malloc(phone_end - phone_start + 1);
    strncpy(phone, phone_start + 7, phone_end - phone_start - 7);

    // Parse the skills.
    char *skills_start = strstr(resume_text, "Skills: ");
    if (skills_start == NULL) {
        printf("Error: Skills not found in resume.\n");
        return 1;
    }
    char *skills_end = strchr(skills_start, '\n');
    if (skills_end == NULL) {
        printf("Error: Skills not found in resume.\n");
        return 1;
    }
    char *skills = malloc(skills_end - skills_start + 1);
    strncpy(skills, skills_start + 8, skills_end - skills_start - 8);

    // Print the parsed resume.
    printf("Name: %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Skills: %s\n", skills);

    // Free the allocated memory.
    free(resume_text);
    free(name);
    free(email);
    free(phone);
    free(skills);

    return 0;
}