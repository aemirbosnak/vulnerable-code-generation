//Falcon-180B DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000

struct Email {
    char from[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    time_t timestamp;
};

int main() {
    FILE *fp;
    char filename[MAX_EMAIL_LENGTH];
    char line[MAX_EMAIL_LENGTH];
    int count = 0;
    struct Email emails[MAX_EMAILS];

    printf("Enter filename to read emails from: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    while (fgets(line, MAX_EMAIL_LENGTH, fp)!= NULL) {
        if (count >= MAX_EMAILS) {
            printf("Error: Maximum number of emails reached.\n");
            fclose(fp);
            return 1;
        }

        char *token = strtok(line, ":");
        strcpy(emails[count].from, token);

        token = strtok(NULL, ":");
        strcpy(emails[count].subject, token);

        token = strtok(NULL, "\r\n");
        strcpy(emails[count].body, token);

        emails[count].timestamp = time(NULL);
        count++;
    }

    fclose(fp);

    printf("Enter filename to write emails to: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "From: %s\nSubject: %s\nBody:\n%s\n\n", emails[i].from, emails[i].subject, emails[i].body);
    }

    fclose(fp);

    printf("Emails successfully saved to file.\n");

    return 0;
}