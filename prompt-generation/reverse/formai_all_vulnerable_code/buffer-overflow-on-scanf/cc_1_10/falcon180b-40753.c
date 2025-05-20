//Falcon-180B DATASET v1.0 Category: Email Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_EMAIL_SIZE 1024
#define MAX_SUBJECT_SIZE 1024
#define MAX_CONTENT_SIZE 10240

typedef struct {
    char name[MAX_LINE_SIZE];
    char email[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char content[MAX_CONTENT_SIZE];
} Email;

int main() {
    FILE *fp;
    Email email;
    char line[MAX_LINE_SIZE];
    char *token;
    int count = 0;
    char filename[MAX_LINE_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        count++;
        if (count == 1) {
            strcpy(email.name, line);
        } else if (count == 2) {
            token = strtok(line, " ");
            strcpy(email.email, token);
        } else if (count == 3) {
            strcpy(email.subject, line);
        } else if (count == 4) {
            fgets(email.content, MAX_CONTENT_SIZE, fp);
        }
    }

    fclose(fp);

    printf("\nName: %s\n", email.name);
    printf("Email: %s\n", email.email);
    printf("Subject: %s\n", email.subject);
    printf("Content:\n%s\n", email.content);

    return 0;
}