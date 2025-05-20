//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CV_SIZE 4096
#define MAX_NAME_SIZE 256
#define MAX_EMAIL_SIZE 128
#define MAX_PHONE_SIZE 16

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    char phone[MAX_PHONE_SIZE];
    char skills[MAX_CV_SIZE / 2];
} CV;

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void parse_cv(const char *cv_text, CV *cv) {
    const char *ptr = strstr(cv_text, "name:");
    if (ptr) {
        sscanf(ptr, "name: %[^\n]", cv->name);
    }
    
    ptr = strstr(cv_text, "email:");
    if (ptr) {
        sscanf(ptr, "email: %[^\n]", cv->email);
    }
    
    ptr = strstr(cv_text, "phone:");
    if (ptr) {
        sscanf(ptr, "phone: %[^\n]", cv->phone);
    }
    
    ptr = strstr(cv_text, "skills:");
    if (ptr) {
        sscanf(ptr, "skills: %[^\n]", cv->skills);
    }
}

void print_cv(const CV *cv) {
    printf("************\n");
    printf("Cyberpunk CV\n");
    printf("------------\n");
    printf("Name: %s\n", cv->name);
    printf("Email: %s\n", cv->email);
    printf("Phone: %s\n", cv->phone);
    printf("Skills: %s\n", cv->skills);
    printf("************\n");
}

int main() {
    char cv_text[MAX_CV_SIZE] = 
        "name: Alex Cyberhawk\n"
        "email: alex.cyb@netrunner.com\n"
        "phone: 555-01234\n"
        "skills: Hacking, Drone Ops, Stealth, Cybernetics\n";
    
    CV parsed_cv;
    memset(&parsed_cv, 0, sizeof(parsed_cv));

    parse_cv(cv_text, &parsed_cv);
    
    // Convert names and relevant fields to lower case for uniformity
    to_lower(parsed_cv.name);
    to_lower(parsed_cv.email);
    to_lower(parsed_cv.phone);
    to_lower(parsed_cv.skills);

    // Print parsed CV
    print_cv(&parsed_cv);

    // A simple search for a skill in the resume for extra functionality
    char skill_to_search[MAX_NAME_SIZE];
    printf("Enter a skill to search: ");
    fgets(skill_to_search, sizeof(skill_to_search), stdin);
    skill_to_search[strcspn(skill_to_search, "\n")] = 0; // Strip newline character
    to_lower(skill_to_search);

    if (strstr(parsed_cv.skills, skill_to_search)) {
        printf("Skill '%s' found in the CV. Potential hire!\n", skill_to_search);
    } else {
        printf("Skill '%s' not found. Keep searching in the neon mist!\n", skill_to_search);
    }

    return 0;
}