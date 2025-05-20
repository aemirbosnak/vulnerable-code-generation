//Falcon-180B DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024 // maximum length of a line
#define MAX_WORD 64 // maximum length of a word
#define MAX_SUBJECT 256 // maximum length of a subject

typedef struct {
    char from[MAX_LINE]; // sender's email address
    char to[MAX_LINE]; // recipient's email address
    char subject[MAX_SUBJECT]; // email subject
    char body[MAX_LINE]; // email body
} email_t;

int main() {
    FILE *fp;
    char line[MAX_LINE];
    char word[MAX_WORD];
    email_t email;
    int in_body = 0; // flag to indicate if we are in the email body

    fp = fopen("email.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open email file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (in_body) { // we are in the body of the email
            strcat(email.body, line);
        } else { // we are in the header of the email
            sscanf(line, "%s %s %s", word, word, word);
            strcpy(email.from, word);
            strcpy(email.to, word);
            strcpy(email.subject, word);
            in_body = 1;
        }
    }

    fclose(fp);

    // do something with the email data
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);

    return 0;
}