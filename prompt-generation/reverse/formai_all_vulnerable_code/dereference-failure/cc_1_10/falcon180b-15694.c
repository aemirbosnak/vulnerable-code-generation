//Falcon-180B DATASET v1.0 Category: Email Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256

struct email {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
};

int main() {
    char buffer[MAX_EMAIL_LENGTH];
    struct email email;
    int email_count = 0;
    int i;

    // Read in email
    printf("Enter email:\n");
    fgets(buffer, MAX_EMAIL_LENGTH, stdin);

    // Parse email into fields
    char *token = strtok(buffer, "\r\n");
    strcpy(email.from, token);
    token = strtok(NULL, "\r\n");
    strcpy(email.to, token);
    token = strtok(NULL, "\r\n");
    strcpy(email.subject, token);
    strcpy(email.body, strtok(NULL, "\r\n"));

    // Print email fields
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);

    // Save email to file
    char filename[20];
    sprintf(filename, "email_%d.txt", email_count);
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "From: %s\n", email.from);
    fprintf(fp, "To: %s\n", email.to);
    fprintf(fp, "Subject: %s\n", email.subject);
    fprintf(fp, "Body:\n%s\n", email.body);
    fclose(fp);

    printf("Email saved to file: %s\n", filename);

    return 0;
}