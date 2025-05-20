//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: recursive
/*
 * Email Client Example
 *
 * This program is an example of a simple email client written in C.
 * It demonstrates the use of a recursive function to read and display
 * emails in a tree-like structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 100
#define MAX_EMAILS 100

struct email {
    char subject[MAX_SUBJECT_LEN];
    char body[1000];
    struct email *next;
};

struct email *emails[MAX_EMAILS];

void read_emails(FILE *fp, struct email *parent) {
    struct email *email = malloc(sizeof(struct email));
    char line[100];
    int i = 0;

    while (fgets(line, 100, fp) != NULL) {
        if (line[0] == 'S') {
            // Subject
            strcpy(email->subject, line + 2);
            email->subject[strlen(email->subject) - 1] = '\0';
        } else if (line[0] == 'B') {
            // Body
            strcpy(email->body, line + 2);
            email->body[strlen(email->body) - 1] = '\0';
        } else if (line[0] == 'E') {
            // End of email
            if (parent != NULL) {
                email->next = parent->next;
                parent->next = email;
            } else {
                email->next = emails[i];
                emails[i] = email;
            }
            i++;
            email = NULL;
        }
    }

    if (email != NULL) {
        free(email);
    }
}

void display_emails(struct email *email) {
    if (email == NULL) {
        return;
    }

    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);

    if (email->next != NULL) {
        display_emails(email->next);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc != 2) {
        printf("Usage: %s [email file]\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    read_emails(fp, NULL);

    display_emails(emails[0]);

    fclose(fp);

    return 0;
}