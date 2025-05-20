//Falcon-180B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_TO_LENGTH 100
#define MAX_FROM_LENGTH 100

// Function prototypes
int is_valid_email(char *email);
void send_email(char *to, char *from, char *subject, char *body);
void read_email(char *email_file);

int main() {
    char email_file[100] = "emails.txt";
    char email[100];
    FILE *fp;

    fp = fopen(email_file, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", email)!= EOF) {
        if (is_valid_email(email)) {
            send_email(email, "sender@example.com", "Test Email", "Hello World!");
        } else {
            printf("Invalid email: %s\n", email);
        }
    }

    fclose(fp);
    return 0;
}

int is_valid_email(char *email) {
    int i, j;
    char *at_pos = NULL;

    // Check for valid format
    if (strlen(email) > MAX_TO_LENGTH) {
        return 0;
    }

    at_pos = strrchr(email, '@');
    if (at_pos == NULL || at_pos == email || at_pos - email >= MAX_TO_LENGTH) {
        return 0;
    }

    // Check for valid domain name
    for (i = at_pos + 1; i < strlen(email); i++) {
        if (!isalpha(email[i]) &&!isdigit(email[i]) && email[i]!= '.' && email[i]!= '-') {
            return 0;
        }
    }

    return 1;
}

void send_email(char *to, char *from, char *subject, char *body) {
    printf("Sending email from %s to %s with subject %s and body %s\n", from, to, subject, body);
}

void read_email(char *email_file) {
    char email[100];
    FILE *fp;

    fp = fopen(email_file, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", email)!= EOF) {
        printf("Email: %s\n", email);
    }

    fclose(fp);
}