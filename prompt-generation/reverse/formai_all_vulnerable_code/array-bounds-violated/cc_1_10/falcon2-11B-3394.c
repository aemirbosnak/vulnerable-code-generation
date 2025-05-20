//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if the email is spam or not
bool isSpam(char* email) {
    // Check for common spam email words
    char* spamWords[] = {"money", "win", "free", "offer", "discount", "subscribe", "earn", "work", "home", "rich"};
    int len = sizeof(spamWords) / sizeof(spamWords[0]);

    for (int i = 0; i < len; i++) {
        if (strstr(email, spamWords[i])) {
            return true;
        }
    }

    // Check for common spam email domains
    char* spamDomains[] = {"gmail.com", "hotmail.com", "yahoo.com", "outlook.com", "aol.com", "msn.com", "comcast.net", "live.com", "mail.com", "mail.ru", "mail.yahoo.com"};
    int domainLen = sizeof(spamDomains) / sizeof(spamDomains[0]);

    for (int i = 0; i < domainLen; i++) {
        if (strstr(email, spamDomains[i])) {
            return true;
        }
    }

    return false;
}

// Function to read emails from file
void readEmails(char* filename, int* numEmails) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[1000];
    int count = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        if (strlen(line) > 0) {
            count++;
            char* email = strtok(line, "\n");
            while (email!= NULL) {
                *numEmails += 1;
                if (isSpam(email)) {
                    printf("%s is spam\n", email);
                }
                email = strtok(NULL, "\n");
            }
        }
    }

    fclose(fp);
}

int main() {
    char* emailsFile = "emails.txt";
    int numEmails;
    readEmails(emailsFile, &numEmails);

    printf("Total number of emails: %d\n", numEmails);
    return 0;
}