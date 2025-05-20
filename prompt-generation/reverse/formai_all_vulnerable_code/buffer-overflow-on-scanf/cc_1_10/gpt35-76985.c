//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS_LENGTH 100

struct Candidate {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
};

void print_candidate(struct Candidate);
void parse_resume(char *);

int main()
{
    char resume_file_name[MAX_NAME_LENGTH];
    printf("Enter the name of the resume file: ");
    scanf("%s", resume_file_name);
    parse_resume(resume_file_name);
    return 0;
}

void print_candidate(struct Candidate c) 
{
    printf("Name: %s\n", c.name);
    printf("Address: %s\n", c.address);
    printf("Email: %s\n", c.email);
    printf("Skills: %s\n", c.skills);
}

void parse_resume(char *resume_file_name) 
{
    struct Candidate c;
    FILE *fp = fopen(resume_file_name, "r");
    if (fp == NULL) {
        printf("Could not open the resume file.\n");
        return;
    }
    fscanf(fp, "Name: %[^\n]\n", c.name);
    fscanf(fp, "Address: %[^\n]\n", c.address);
    fscanf(fp, "Email: %[^\n]\n", c.email);
    fscanf(fp, "Skills: %[^\n]\n", c.skills);
    fclose(fp);
    print_candidate(c);
}