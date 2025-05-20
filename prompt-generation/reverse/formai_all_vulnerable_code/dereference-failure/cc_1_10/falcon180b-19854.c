//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char name[MAX_LINE_LEN];
    char address[MAX_LINE_LEN];
    char phone_number[MAX_LINE_LEN];
    char email[MAX_LINE_LEN];
    char education[MAX_LINE_LEN];
    char work_experience[MAX_LINE_LEN];
} Resume;

Resume* parse_resume(char* resume_file) {
    FILE* fp;
    char line[MAX_LINE_LEN];
    Resume* resume = NULL;

    fp = fopen(resume_file, "r");
    if (fp == NULL) {
        printf("Error opening resume file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (resume == NULL) {
            resume = (Resume*)malloc(sizeof(Resume));
            strcpy(resume->name, line);
        } else if (strstr(line, "Address:") == line) {
            strcpy(resume->address, line + strlen("Address:"));
        } else if (strstr(line, "Phone Number:") == line) {
            strcpy(resume->phone_number, line + strlen("Phone Number:"));
        } else if (strstr(line, "Email:") == line) {
            strcpy(resume->email, line + strlen("Email:"));
        } else if (strstr(line, "Education:") == line) {
            strcpy(resume->education, line + strlen("Education:"));
        } else if (strstr(line, "Work Experience:") == line) {
            strcpy(resume->work_experience, line + strlen("Work Experience:"));
        }
    }

    fclose(fp);

    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Address: %s\n", resume->address);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("Email: %s\n", resume->email);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
}

int main() {
    Resume* resume = parse_resume("resume.txt");
    print_resume(resume);

    free(resume);
    return 0;
}