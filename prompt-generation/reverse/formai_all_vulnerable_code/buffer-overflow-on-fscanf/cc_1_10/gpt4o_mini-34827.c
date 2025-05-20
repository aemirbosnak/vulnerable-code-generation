//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 256
#define THRESHOLD 3

// Structure to hold email details
typedef struct {
    char email[50];
    char subject[MAX_SUBJECT_LENGTH];
} Email;

// Function prototypes
void toLowerCase(char *str);
int isSpamKeyword(char *subject);
void detectSpamEmails(Email emails[], int count);
void logSpamEmail(Email email);
void printUsage(char *progName);

int main(int argc, char *argv[]) {
    Email emails[MAX_EMAILS];
    int emailCount = 0;
    
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Reading emails from the file
    while (fscanf(file, "%49s %255[^\n]\n", emails[emailCount].email, emails[emailCount].subject) == 2) {
        emailCount++;
        if (emailCount >= MAX_EMAILS) {
            printf("Maximum email limit reached!\n");
            break;
        }
    }
    fclose(file);

    detectSpamEmails(emails, emailCount);
    return 0;
}

// Convert string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Check if the subject contains spam keywords
int isSpamKeyword(char *subject) {
    const char *spamKeywords[] = {
        "win", "free", "cash", "prize",
        "offer", "now", "click", "buy",
        "urgent", NULL // Terminator for the array
    };

    toLowerCase(subject);
    
    int count = 0;
    for (int i = 0; spamKeywords[i] != NULL; i++) {
        if (strstr(subject, spamKeywords[i]) != NULL) {
            count++;
        }
    }

    return count >= THRESHOLD;
}

// Detect spam emails
void detectSpamEmails(Email emails[], int count) {
    printf("Scanning emails for spam...\n");
    for (int i = 0; i < count; i++) {
        if (isSpamKeyword(emails[i].subject)) {
            printf("Spam detected! Email: %s, Subject: %s\n", emails[i].email, emails[i].subject);
            logSpamEmail(emails[i]);
        }
    }
}

// Log spam email to a file
void logSpamEmail(Email email) {
    FILE *logFile = fopen("spam_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "Spam Email Detected: %s, Subject: %s\n", email.email, email.subject);
        fclose(logFile);
    } else {
        perror("Error logging spam email");
    }
}

// Print usage information
void printUsage(char *progName) {
    printf("Usage: %s <file_with_emails>\n", progName);
    printf("The file should contain lines in the format: <email> <subject>\n");
}