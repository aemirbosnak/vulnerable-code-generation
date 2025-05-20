//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_EDUCATION_LENGTH 100
#define MAX_WORK_EXPERIENCE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char education[MAX_EDUCATION_LENGTH];
    char work_experience[MAX_WORK_EXPERIENCE_LENGTH];
} resume;

void parse_name(resume *r, char *input) {
    strcpy(r->name, input);
}

void parse_address(resume *r, char *input) {
    strcpy(r->address, input);
}

void parse_phone_number(resume *r, char *input) {
    strcpy(r->phone_number, input);
}

void parse_email(resume *r, char *input) {
    strcpy(r->email, input);
}

void parse_education(resume *r, char *input) {
    strcpy(r->education, input);
}

void parse_work_experience(resume *r, char *input) {
    strcpy(r->work_experience, input);
}

int main() {
    char input[1000];
    resume r;

    printf("enter your name: ");
    scanf("%s", input);
    parse_name(&r, input);

    printf("enter your address: ");
    scanf("%s", input);
    parse_address(&r, input);

    printf("enter your phone number: ");
    scanf("%s", input);
    parse_phone_number(&r, input);

    printf("enter your email: ");
    scanf("%s", input);
    parse_email(&r, input);

    printf("enter your education: ");
    scanf("%s", input);
    parse_education(&r, input);

    printf("enter your work experience: ");
    scanf("%s", input);
    parse_work_experience(&r, input);

    printf("name: %s\n", r.name);
    printf("address: %s\n", r.address);
    printf("phone number: %s\n", r.phone_number);
    printf("email: %s\n", r.email);
    printf("education: %s\n", r.education);
    printf("work experience: %s\n", r.work_experience);

    return 0;
}