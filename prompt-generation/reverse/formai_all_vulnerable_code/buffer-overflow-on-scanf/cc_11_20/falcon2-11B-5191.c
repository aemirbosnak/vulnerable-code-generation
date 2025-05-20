//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_SPAM_SIZE 512

int main() {
    char email[MAX_EMAIL_SIZE];
    char spam[MAX_SPAM_SIZE];
    char *email_ptr = NULL;
    char *spam_ptr = NULL;
    char *ptr;
    char *regex_ptr;
    int is_spam = 0;

    printf("Enter the email address: ");
    scanf("%s", email);

    // Convert to lowercase for case-insensitive matching
    for (ptr = email; *ptr!= '\0'; ptr++) {
        *ptr = tolower(*ptr);
    }

    // Check for common spam keywords
    if (strstr(email, "viagra")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "cialis")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "pills")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "discount")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "free")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "buy now")!= NULL) {
        is_spam = 1;
    }

    // Check for spam patterns using regular expressions
    regex_ptr = regexec(&(regex_t){0}, email, 0, NULL, 0);
    if (regex_ptr!= NULL) {
        is_spam = 1;
    }

    // Check if the email has a suspicious subject line
    if (strstr(email, "[subject]")!= NULL) {
        is_spam = 1;
    }

    // Check if the email has a suspicious attachment
    if (strstr(email, "attachment")!= NULL) {
        is_spam = 1;
    }

    // Check if the email has a suspicious sender
    if (strstr(email, "noreply")!= NULL) {
        is_spam = 1;
    }

    // Check if the email has a suspicious recipient
    if (strstr(email, "undisclosed-recipients")!= NULL) {
        is_spam = 1;
    }

    // Check if the email has a suspicious body
    if (strstr(email, "click here")!= NULL) {
        is_spam = 1;
    }
    if (strstr(email, "http://www.example.com")!= NULL) {
        is_spam = 1;
    }

    // If the email is spam, print a warning message
    if (is_spam == 1) {
        printf("Warning: %s is a spam message!\n", email);
    }

    // If the email is not spam, print a success message
    if (is_spam == 0) {
        printf("Success: %s is not a spam message.\n", email);
    }

    return 0;
}