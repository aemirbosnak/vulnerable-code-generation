//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64

// Struct to hold the parsed resume data
typedef struct {
    char name[MAX_WORD_LEN];
    char email[MAX_WORD_LEN];
    char phone[MAX_WORD_LEN];
    char address[MAX_LINE_LEN];
    char education[MAX_LINE_LEN];
    char work_experience[MAX_LINE_LEN];
} Resume;

// Function to read the resume file and parse the data
Resume* parse_resume(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    Resume* resume = malloc(sizeof(Resume));
    memset(resume, 0, sizeof(Resume));

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char* word = strtok(line, " \t\r\n");
        if (word == NULL) {
            continue;
        }

        if (strcmp(word, "Name") == 0) {
            strcpy(resume->name, strtok(NULL, " \t\r\n"));
        } else if (strcmp(word, "Email") == 0) {
            strcpy(resume->email, strtok(NULL, " \t\r\n"));
        } else if (strcmp(word, "Phone") == 0) {
            strcpy(resume->phone, strtok(NULL, " \t\r\n"));
        } else if (strcmp(word, "Address") == 0) {
            strcpy(resume->address, strtok(NULL, " \t\r\n"));
        } else if (strcmp(word, "Education") == 0) {
            strcpy(resume->education, strtok(NULL, " \t\r\n"));
        } else if (strcmp(word, "Work Experience") == 0) {
            strcpy(resume->work_experience, strtok(NULL, " \t\r\n"));
        }
    }

    fclose(fp);
    return resume;
}

// Function to print the parsed resume data
void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Address: %s\n", resume->address);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        exit(1);
    }

    Resume* resume = parse_resume(argv[1]);
    print_resume(resume);

    free(resume);
    return 0;
}