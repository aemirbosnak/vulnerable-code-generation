//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RESUME_LENGTH 10000

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char address[200];
    char education[200];
    char experience[200];
} resume;

resume parse_resume(char* resume_text) {
    resume result;
    char* token;
    char* saveptr;
    int education_index = 0;
    int experience_index = 0;

    // Extract name
    token = strtok_r(resume_text, "\n", &saveptr);
    if (token!= NULL) {
        strcpy(result.name, token);
    } else {
        printf("Error: Name not found.\n");
        exit(1);
    }

    // Extract email
    token = strtok_r(NULL, "\n", &saveptr);
    if (token!= NULL) {
        strcpy(result.email, token);
    } else {
        printf("Error: Email not found.\n");
        exit(1);
    }

    // Extract phone number
    token = strtok_r(NULL, "\n", &saveptr);
    if (token!= NULL) {
        strcpy(result.phone, token);
    } else {
        printf("Error: Phone number not found.\n");
        exit(1);
    }

    // Extract address
    token = strtok_r(NULL, "\n", &saveptr);
    if (token!= NULL) {
        strcpy(result.address, token);
    } else {
        printf("Error: Address not found.\n");
        exit(1);
    }

    // Extract education
    while ((token = strtok_r(NULL, "\n", &saveptr))!= NULL) {
        if (education_index >= MAX_RESUME_LENGTH) {
            printf("Error: Education section too long.\n");
            exit(1);
        }
        strcat(result.education + strlen(result.education), token);
        strcat(result.education + strlen(result.education), " ");
        education_index += strlen(token) + 1;
    }

    // Extract experience
    while ((token = strtok_r(NULL, "\n", &saveptr))!= NULL) {
        if (experience_index >= MAX_RESUME_LENGTH) {
            printf("Error: Experience section too long.\n");
            exit(1);
        }
        strcat(result.experience + strlen(result.experience), token);
        strcat(result.experience + strlen(result.experience), " ");
        experience_index += strlen(token) + 1;
    }

    return result;
}

void print_resume(resume* r) {
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("Phone: %s\n", r->phone);
    printf("Address: %s\n", r->address);
    printf("Education: %s\n", r->education);
    printf("Experience: %s\n", r->experience);
}

int main() {
    char resume_text[MAX_RESUME_LENGTH];
    resume r;

    // Read resume from standard input
    fgets(resume_text, MAX_RESUME_LENGTH, stdin);

    // Parse resume
    r = parse_resume(resume_text);

    // Print resume
    print_resume(&r);

    return 0;
}