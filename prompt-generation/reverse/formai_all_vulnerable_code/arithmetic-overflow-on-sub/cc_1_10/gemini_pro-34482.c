//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Define the regular expressions for parsing the resume
#define NAME_REGEX "^[A-Za-z ]+$"
#define EMAIL_REGEX "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$"
#define PHONE_REGEX "^[0-9]{3}-[0-9]{3}-[0-9]{4}$"
#define SKILL_REGEX "^[A-Za-z0-9,. ]+$"

// Define the structure for storing the resume data
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills;
} Resume;

// Function to parse the name from the resume
char *parse_name(char *resume) {
    regex_t regex;
    regmatch_t match;

    // Compile the regular expression
    if (regcomp(&regex, NAME_REGEX, REG_EXTENDED) != 0) {
        perror("regcomp");
        return NULL;
    }

    // Execute the regular expression
    if (regexec(&regex, resume, 1, &match, 0) != 0) {
        regfree(&regex);
        return NULL;
    }

    // Extract the name from the resume
    char *name = malloc(match.rm_eo - match.rm_so + 1);
    strncpy(name, resume + match.rm_so, match.rm_eo - match.rm_so);
    name[match.rm_eo - match.rm_so] = '\0';

    // Free the regular expression
    regfree(&regex);

    return name;
}

// Function to parse the email from the resume
char *parse_email(char *resume) {
    regex_t regex;
    regmatch_t match;

    // Compile the regular expression
    if (regcomp(&regex, EMAIL_REGEX, REG_EXTENDED) != 0) {
        perror("regcomp");
        return NULL;
    }

    // Execute the regular expression
    if (regexec(&regex, resume, 1, &match, 0) != 0) {
        regfree(&regex);
        return NULL;
    }

    // Extract the email from the resume
    char *email = malloc(match.rm_eo - match.rm_so + 1);
    strncpy(email, resume + match.rm_so, match.rm_eo - match.rm_so);
    email[match.rm_eo - match.rm_so] = '\0';

    // Free the regular expression
    regfree(&regex);

    return email;
}

// Function to parse the phone number from the resume
char *parse_phone(char *resume) {
    regex_t regex;
    regmatch_t match;

    // Compile the regular expression
    if (regcomp(&regex, PHONE_REGEX, REG_EXTENDED) != 0) {
        perror("regcomp");
        return NULL;
    }

    // Execute the regular expression
    if (regexec(&regex, resume, 1, &match, 0) != 0) {
        regfree(&regex);
        return NULL;
    }

    // Extract the phone number from the resume
    char *phone = malloc(match.rm_eo - match.rm_so + 1);
    strncpy(phone, resume + match.rm_so, match.rm_eo - match.rm_so);
    phone[match.rm_eo - match.rm_so] = '\0';

    // Free the regular expression
    regfree(&regex);

    return phone;
}

// Function to parse the skills from the resume
char *parse_skills(char *resume) {
    regex_t regex;
    regmatch_t match;

    // Compile the regular expression
    if (regcomp(&regex, SKILL_REGEX, REG_EXTENDED) != 0) {
        perror("regcomp");
        return NULL;
    }

    // Execute the regular expression
    if (regexec(&regex, resume, 1, &match, 0) != 0) {
        regfree(&regex);
        return NULL;
    }

    // Extract the skills from the resume
    char *skills = malloc(match.rm_eo - match.rm_so + 1);
    strncpy(skills, resume + match.rm_so, match.rm_eo - match.rm_so);
    skills[match.rm_eo - match.rm_so] = '\0';

    // Free the regular expression
    regfree(&regex);

    return skills;
}

// Function to print the resume data
void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    // Read the resume file into a string
    char *resume = NULL;
    size_t len = 0;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    getline(&resume, &len, file);
    fclose(file);

    // Parse the resume data
    Resume resume_data;
    resume_data.name = parse_name(resume);
    resume_data.email = parse_email(resume);
    resume_data.phone = parse_phone(resume);
    resume_data.skills = parse_skills(resume);

    // Print the resume data
    print_resume(&resume_data);

    // Free the allocated memory
    free(resume);
    free(resume_data.name);
    free(resume_data.email);
    free(resume_data.phone);
    free(resume_data.skills);

    return 0;
}