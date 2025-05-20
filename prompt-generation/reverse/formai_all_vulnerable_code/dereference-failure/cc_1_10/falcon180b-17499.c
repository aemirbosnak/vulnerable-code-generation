//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} ResumeField;

typedef struct {
    int numFields;
    ResumeField fields[MAX_LINE_LENGTH];
} Resume;

Resume *parseResume(char *input) {
    Resume *resume = malloc(sizeof(Resume));
    int numFields = 0;
    char *token = strtok(input, ":");

    while (token!= NULL) {
        if (numFields >= MAX_LINE_LENGTH) {
            printf("Error: Too many fields in line.\n");
            exit(1);
        }
        strncpy(resume->fields[numFields].name, token, MAX_NAME_LENGTH);
        resume->fields[numFields].value[0] = '\0';
        numFields++;
        token = strtok(NULL, ":");
    }

    if (numFields == 0) {
        printf("Error: Line must have at least one field.\n");
        exit(1);
    }

    return resume;
}

void printResume(Resume *resume) {
    printf("Name: %s\n", resume->fields[0].value);
    printf("Address: %s\n", resume->fields[1].value);
    printf("Phone: %s\n", resume->fields[2].value);
    printf("Email: %s\n", resume->fields[3].value);
    printf("Objective: %s\n", resume->fields[4].value);
    printf("Education: %s\n", resume->fields[5].value);
    printf("Experience: %s\n", resume->fields[6].value);
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter resume in format: Name:John Doe:Address:123 Main St.:Phone:555-1234:Email:johndoe@email.com:Objective:To obtain a challenging position in a dynamic organization.:Education:Bachelor of Science in Computer Science:Experience:5 years of experience in software development.\n");
    fgets(input, MAX_LINE_LENGTH, stdin);
    Resume *resume = parseResume(input);
    printResume(resume);
    free(resume);
    return 0;
}