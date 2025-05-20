//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define NAME_LENGTH 50
#define PHONE_LENGTH 20
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
} Applicant;

void parse_resume(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    Applicant applicant;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Skip lines that don't start with "Name:" or "Contact:"
        if (strncmp(line, "Name:", 4) != 0 && strncmp(line, "Contact:", 6) != 0) {
            continue;
        }

        // Extract name
        if (strncmp(line, "Name:", 4) == 0) {
            sscanf(line + 6, "%s", name);
            strcpy(applicant.name, name);
        }

        // Extract phone
        if (strncmp(line, "Contact:", 6) == 0) {
            sscanf(line + 8, "%s", phone);
            strcpy(applicant.phone, phone);

            // Extract email
            if (getc(fp) == ':') {
                fgets(line, MAX_LINE_LENGTH, fp);
                sscanf(line, "%s", applicant.email);
                line[strcspn(line, "\n")] = '\0'; // Remove newline character
            }
        }
    }

    printf("Name: %s\n", applicant.name);
    printf("Phone: %s\n", applicant.phone);
    printf("Email: %s\n", applicant.email);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    parse_resume(fp);
    fclose(fp);

    return 0;
}