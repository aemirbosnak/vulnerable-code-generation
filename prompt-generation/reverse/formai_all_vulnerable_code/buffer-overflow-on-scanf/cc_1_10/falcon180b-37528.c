//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

typedef struct {
    char name[MAX_WORD_SIZE];
    char email[MAX_WORD_SIZE];
    char phone[MAX_WORD_SIZE];
    char address[MAX_LINE_SIZE];
    int experience;
} Candidate;

void parseResume(char* resume) {
    char line[MAX_LINE_SIZE];
    Candidate candidate = { 0 };
    char* token;

    while (fgets(line, MAX_LINE_SIZE, resume)!= NULL) {
        token = strtok(line, " ");
        if (token!= NULL) {
            if (strcmp(token, "Name:") == 0) {
                strcpy(candidate.name, strtok(NULL, " "));
            } else if (strcmp(token, "Email:") == 0) {
                strcpy(candidate.email, strtok(NULL, " "));
            } else if (strcmp(token, "Phone:") == 0) {
                strcpy(candidate.phone, strtok(NULL, " "));
            } else if (strcmp(token, "Address:") == 0) {
                strcpy(candidate.address, strtok(NULL, " "));
            } else if (strcmp(token, "Experience:") == 0) {
                candidate.experience = atoi(strtok(NULL, " "));
            }
        }
    }

    printf("Name: %s\n", candidate.name);
    printf("Email: %s\n", candidate.email);
    printf("Phone: %s\n", candidate.phone);
    printf("Address: %s\n", candidate.address);
    printf("Experience: %d\n", candidate.experience);
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the resume file: ");
    scanf("%s", filename);

    FILE* resume = fopen(filename, "r");
    if (resume == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    parseResume(resume);

    fclose(resume);
    return 0;
}