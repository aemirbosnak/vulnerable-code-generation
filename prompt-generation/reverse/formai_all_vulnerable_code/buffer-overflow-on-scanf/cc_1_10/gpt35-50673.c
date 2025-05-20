//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[50];
    char email[50];
    char contact[20];
    char address[100];
    char skills[200];
    char experience[300];
} resume;

void parse_resume(char* filename, struct resume* resume_ptr) {
    FILE* fp;
    fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    char line[200];

    // Parsing name
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->name);

    // Parsing email
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->email);

    // Parsing contact number
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->contact);

    // Parsing address   
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->address);

    // Parsing skills
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->skills);

    // Parsing experience
    fgets(line, sizeof(line), fp);
    sscanf(line, "%[^\n]", resume_ptr->experience);

    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    parse_resume(filename, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Contact number: %s\n", resume.contact);
    printf("Address: %s\n", resume.address);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);

    return 0;
}