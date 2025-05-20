//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define SPAM_THRESHOLD 5

typedef struct {
    char email[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

typedef struct {
    char keyword[20];
    int score;
} SpamKeyword;

// List of keywords commonly found in spam
SpamKeyword spamKeywords[] = {
    {"free", 2},
    {"winner", 3},
    {"prize", 2},
    {"click here", 3},
    {"urgent", 3},
    {"money", 2},
    {"rich", 2},
    {"offer", 1},
    {"buy", 1}
};

int isSpam(const Email *email) {
    int totalScore = 0;

    // Convert subject and body to lowercase for matching
    char subjectLower[MAX_SUBJECT_LENGTH];
    char bodyLower[MAX_BODY_LENGTH];
    for (int i = 0; email->subject[i]; i++) {
        subjectLower[i] = tolower(email->subject[i]);
    }
    subjectLower[strlen(email->subject)] = '\0';
    
    for (int i = 0; email->body[i]; i++) {
        bodyLower[i] = tolower(email->body[i]);
    }
    bodyLower[strlen(email->body)] = '\0';
    
    // Check for spam keywords in both subject and body
    for (int i = 0; i < sizeof(spamKeywords) / sizeof(spamKeywords[0]); i++) {
        if (strstr(subjectLower, spamKeywords[i].keyword) != NULL) {
            totalScore += spamKeywords[i].score;
        }
        if (strstr(bodyLower, spamKeywords[i].keyword) != NULL) {
            totalScore += spamKeywords[i].score;
        }
    }
    
    return totalScore >= SPAM_THRESHOLD; // Return true if score exceeds threshold
}

void printEmail(const Email *email, int isSpam) {
    printf("Email From: %s\n", email->email);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
    if (isSpam) {
        printf("Status: SPAM\n");
    } else {
        printf("Status: NOT SPAM\n");
    }
    printf("\n");
}

int main() {
    Email emails[MAX_EMAILS];
    int emailCount = 0;

    // Input Emails
    while (emailCount < MAX_EMAILS) {
        printf("Enter email (or 'exit' to finish): ");
        scanf("%s", emails[emailCount].email);
        if (strcmp(emails[emailCount].email, "exit") == 0) {
            break;
        }

        printf("Enter subject: ");
        getchar(); // To consume the newline character
        fgets(emails[emailCount].subject, MAX_SUBJECT_LENGTH, stdin);
        emails[emailCount].subject[strcspn(emails[emailCount].subject, "\n")] = 0; // Remove newline

        printf("Enter body: ");
        fgets(emails[emailCount].body, MAX_BODY_LENGTH, stdin);
        emails[emailCount].body[strcspn(emails[emailCount].body, "\n")] = 0; // Remove newline

        emailCount++;
    }

    // Analyze and print results
    for (int i = 0; i < emailCount; i++) {
        int spamStatus = isSpam(&emails[i]);
        printEmail(&emails[i], spamStatus);
    }

    return 0;
}