//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Define the structure of a resume
typedef struct {
    char *name;
    char *email;
    char *phone;
    char *address;
    char *skills;
    char *experience;
    char *education;
} Resume;

// Define the regular expressions for parsing the resume
const char *name_regex = "Name: ([a-zA-Z ]+)";
const char *email_regex = "Email: ([a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+\\.[a-zA-Z]+)";
const char *phone_regex = "Phone: ([0-9-]+)";
const char *address_regex = "Address: ([a-zA-Z0-9, ]+)";
const char *skills_regex = "Skills: (.*)";
const char *experience_regex = "Experience: (.*)";
const char *education_regex = "Education: (.*)";

// Parse the resume and store the data in a struct
Resume *parse_resume(char *resume) {
    Resume *r = malloc(sizeof(Resume));

    // Compile the regular expressions
    regex_t name_re;
    regex_t email_re;
    regex_t phone_re;
    regex_t address_re;
    regex_t skills_re;
    regex_t experience_re;
    regex_t education_re;
    regcomp(&name_re, name_regex, REG_EXTENDED);
    regcomp(&email_re, email_regex, REG_EXTENDED);
    regcomp(&phone_re, phone_regex, REG_EXTENDED);
    regcomp(&address_re, address_regex, REG_EXTENDED);
    regcomp(&skills_re, skills_regex, REG_EXTENDED);
    regcomp(&experience_re, experience_regex, REG_EXTENDED);
    regcomp(&education_re, education_regex, REG_EXTENDED);

    // Match the regular expressions against the resume
    regmatch_t matches[1];
    regexec(&name_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->name = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&email_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->email = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&phone_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->phone = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&address_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->address = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&skills_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->skills = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&experience_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->experience = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }
    regexec(&education_re, resume, 1, matches, 0);
    if (matches[0].rm_so != -1) {
        r->education = strndup(resume + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
    }

    // Free the compiled regular expressions
    regfree(&name_re);
    regfree(&email_re);
    regfree(&phone_re);
    regfree(&address_re);
    regfree(&skills_re);
    regfree(&experience_re);
    regfree(&education_re);

    return r;
}

// Print the resume data
void print_resume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Skills: %s\n", r->skills);
    printf("Experience: %s\n", r->experience);
    printf("Education: %s\n", r->education);
}

// Free the resume data
void free_resume(Resume *r) {
    free(r->name);
    free(r->email);
    free(r->phone);
    free(r->address);
    free(r->skills);
    free(r->experience);
    free(r->education);
    free(r);
}

int main() {
    // Read the resume from a file
    FILE *fp = fopen("resume.txt", "r");
    char *resume = malloc(1024);
    fread(resume, 1, 1024, fp);
    fclose(fp);

    // Parse the resume
    Resume *r = parse_resume(resume);

    // Print the resume
    print_resume(r);

    // Free the resume
    free_resume(r);

    return 0;
}