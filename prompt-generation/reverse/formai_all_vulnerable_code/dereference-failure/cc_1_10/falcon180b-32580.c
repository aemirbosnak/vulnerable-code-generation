//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_NAME_LEN 50
#define MAX_ADDR_LEN 100
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 100

struct token {
    char *name;
    char *address;
    char *phone;
    char *email;
};

struct token parse_resume(char *resume) {
    struct token result;
    char *token;
    int i = 0;

    result.name = malloc(MAX_NAME_LEN * sizeof(char));
    result.address = malloc(MAX_ADDR_LEN * sizeof(char));
    result.phone = malloc(MAX_PHONE_LEN * sizeof(char));
    result.email = malloc(MAX_EMAIL_LEN * sizeof(char));

    token = strtok(resume, "\n");
    while (token!= NULL && i < MAX_TOKENS) {
        if (i == 0) {
            strcpy(result.name, token);
        } else if (i == 1) {
            strcpy(result.address, token);
        } else if (i == 2) {
            strcpy(result.phone, token);
        } else if (i == 3) {
            strcpy(result.email, token);
        }
        i++;
        token = strtok(NULL, "\n");
    }

    return result;
}

int main() {
    FILE *fp;
    char resume[10000];
    struct token parsed_resume;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open resume file.\n");
        exit(1);
    }

    fread(resume, sizeof(char), 10000, fp);
    fclose(fp);

    parsed_resume = parse_resume(resume);

    printf("Name: %s\n", parsed_resume.name);
    printf("Address: %s\n", parsed_resume.address);
    printf("Phone: %s\n", parsed_resume.phone);
    printf("Email: %s\n", parsed_resume.email);

    free(parsed_resume.name);
    free(parsed_resume.address);
    free(parsed_resume.phone);
    free(parsed_resume.email);

    return 0;
}