//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024
#define MAX_NUM_RESUMES 50

typedef struct {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
} Resume;

int main() {
    FILE *resumeFile;
    Resume resumeData[MAX_NUM_RESUMES];
    int numResumes = 0;
    char line[MAX_LINE_LENGTH];
    char *token;

    printf("Enter resume file name: ");
    scanf("%s", line);
    resumeFile = fopen(line, "r");

    if (resumeFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, resumeFile)) {
        token = strtok(line, "\n"); // Skip the line
        if (token == NULL) continue;

        token = strtok(NULL, ":\t\n"); // Name
        strcpy(resumeData[numResumes].name, token);

        token = strtok(NULL, ":\t\n"); // Address
        strcpy(resumeData[numResumes].address, token);

        token = strtok(NULL, ":\t\n"); // Phone
        strcpy(resumeData[numResumes].phone, token);

        token = strtok(NULL, ":\t\n"); // Email
        strcpy(resumeData[numResumes].email, token);

        numResumes++;

        if (numResumes >= MAX_NUM_RESUMES) {
            printf("Max number of resumes reached.\n");
            break;
        }
    }

    fclose(resumeFile);

    // Print the extracted data
    for (int i = 0; i < numResumes; i++) {
        printf("\nName: %s", resumeData[i].name);
        printf("\nAddress: %s", resumeData[i].address);
        printf("\nPhone: %s", resumeData[i].phone);
        printf("\nEmail: %s\n", resumeData[i].email);
    }

    return 0;
}