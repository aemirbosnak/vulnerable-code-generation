//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20

// Struct to hold parsed resume data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} ResumeData;

// Function to remove leading/trailing whitespace from a string
void trim(char *str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            strcpy(str, &str[i]);
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

// Function to parse a line of text for name, email, and phone number
void parseLine(char *line, ResumeData *data) {
    char *token;
    int i;

    // Parse name
    token = strtok(line, " ");
    if (token!= NULL && strlen(token) <= MAX_NAME_LENGTH) {
        strcpy(data->name, token);
    } else {
        printf("Invalid name.\n");
        return;
    }

    // Parse email
    token = strtok(NULL, " ");
    if (token!= NULL && strlen(token) <= MAX_EMAIL_LENGTH) {
        strcpy(data->email, token);
    } else {
        printf("Invalid email.\n");
        return;
    }

    // Parse phone number
    token = strtok(NULL, " ");
    if (token!= NULL && strlen(token) <= MAX_PHONE_LENGTH) {
        strcpy(data->phone, token);
    } else {
        printf("Invalid phone number.\n");
        return;
    }
}

// Function to read a resume file and parse its contents
void readResumeFile(char *filename, ResumeData *data) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        trim(line);
        parseLine(line, data);
    }

    fclose(fp);
}

// Main function
int main() {
    ResumeData data;
    char filename[MAX_LINE_LENGTH];

    printf("Enter resume file name: ");
    scanf("%s", filename);

    readResumeFile(filename, &data);

    printf("Name: %s\n", data.name);
    printf("Email: %s\n", data.email);
    printf("Phone: %s\n", data.phone);

    return 0;
}