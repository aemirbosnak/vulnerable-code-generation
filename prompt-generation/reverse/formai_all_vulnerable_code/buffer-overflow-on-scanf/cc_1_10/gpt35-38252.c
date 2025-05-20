//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for storing resume information
struct resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[1000];
};

//Function for parsing resumes
int parse_resume(char* filename, struct resume* r) {
    FILE* fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: file not found.\n");
        return 0;
    }

    char line[1000];

    //Loop through each line of the file
    while(fgets(line, 1000, fp) != NULL) {
        //Check for name
        if(strstr(line, "Name:")) {
            char* name = strstr(line, ":") + 1;
            strcpy(r->name, name);
        }
        //Check for email
        if(strstr(line, "Email:")) {
            char* email = strstr(line, ":") + 1;
            strcpy(r->email, email);
        }
        //Check for phone number
        if(strstr(line, "Phone:")) {
            char* phone = strstr(line, ":") + 1;
            strcpy(r->phone, phone);
        }
        //Check for skills
        if(strstr(line, "Skills:")) {
            char* skills = strstr(line, ":") + 1;
            strcpy(r->skills, skills);
        }
    }

    fclose(fp);

    return 1;
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    struct resume r;
    int success = parse_resume(filename, &r);

    if(success) {
        printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\n", r.name, r.email, r.phone, r.skills);
    }

    return 0;
}