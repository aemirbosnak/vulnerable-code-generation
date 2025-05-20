//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Struct to hold parsed information from resume
typedef struct {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char phone[MAX_WORD_LENGTH];
    char address[MAX_LINE_LENGTH];
    char education[MAX_LINE_LENGTH];
    char experience[MAX_LINE_LENGTH];
} Resume;

Resume parseResume(FILE *fp) {
    Resume r;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    // Read in each line of the resume
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Extract name
        if (i == 0) {
            token = strtok(line, " ");
            strcpy(r.name, token);
        }

        // Extract email
        else if (i == 1) {
            token = strtok(line, " ");
            strcpy(r.email, token);
        }

        // Extract phone number
        else if (i == 2) {
            token = strtok(line, " ");
            strcpy(r.phone, token);
        }

        // Extract address
        else if (i == 3) {
            strcpy(r.address, line);
        }

        // Extract education
        else if (i == 4) {
            strcpy(r.education, line);
        }

        // Extract experience
        else if (i == 5) {
            strcpy(r.experience, line);
        }

        i++;
    }

    return r;
}

void printResume(Resume r) {
    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
}

int main() {
    FILE *fp;
    Resume r;

    // Open resume file
    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Parse resume
    r = parseResume(fp);

    // Print parsed resume
    printResume(r);

    // Close file
    fclose(fp);

    return 0;
}