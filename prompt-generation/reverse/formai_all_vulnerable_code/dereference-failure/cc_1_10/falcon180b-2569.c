//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the structure of a resume
typedef struct {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    char education[100];
    char experience[200];
} Resume;

// function to parse the resume
Resume parseResume(char *resume) {
    Resume r;
    char *token;
    char *saveptr;

    // parse name
    token = strtok_r(resume, "\n", &saveptr);
    strcpy(r.name, token);

    // parse address
    token = strtok_r(NULL, "\n", &saveptr);
    strcpy(r.address, token);

    // parse phone number
    token = strtok_r(NULL, "\n", &saveptr);
    strcpy(r.phone, token);

    // parse email
    token = strtok_r(NULL, "\n", &saveptr);
    strcpy(r.email, token);

    // parse education
    token = strtok_r(NULL, "\n", &saveptr);
    strcpy(r.education, token);

    // parse experience
    token = strtok_r(NULL, "\n", &saveptr);
    strcpy(r.experience, token);

    return r;
}

// function to print the resume
void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Address: %s\n", r.address);
    printf("Phone: %s\n", r.phone);
    printf("Email: %s\n", r.email);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}

// main function
int main() {
    Resume r;
    char *resume = "John Doe\n123 Main St.\n555-1234\njohndoe@example.com\nBS in Computer Science\n5 years experience in software development";

    // parse the resume
    r = parseResume(resume);

    // print the resume
    printResume(r);

    return 0;
}