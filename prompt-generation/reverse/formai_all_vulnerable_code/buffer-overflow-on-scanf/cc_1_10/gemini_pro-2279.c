//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of common spam words
const char *spam_words[] = {
    "free", "money", "win", "prize", "offer",
    "click", "subscribe", "unsubscribe", "remove", "stop",
    "urgent", "important", "limited time", "exclusive offer", "don't miss out",
    "act now", "call today", "order now", "buy now", "sale",
    "discount", "coupon", "voucher", "code", "promotion",
    "guarantee", "satisfaction", "risk-free", "no obligation", "100% free",
    "earn money", "make money", "work from home", "get rich quick", "financial independence",
    "investment", "stock", "forex", "cryptocurrency", "bitcoin",
    "phishing", "scam", "fraud", "malware", "virus",
    "spam", "junk mail", "unsolicited email", "UCE", "UBE",
    NULL
};

// List of common email addresses used by spammers
const char *spam_email_addresses[] = {
    "@gmail.com", "@yahoo.com", "@hotmail.com", "@aol.com", "@outlook.com",
    "@protonmail.com", "@tutanota.com", "@fastmail.com", "@gmx.com", "@yandex.com",
    NULL
};

// List of common email subject lines used by spammers
const char *spam_subject_lines[] = {
    "You've won!", "Free money!", "Click here to get rich quick!",
    "Don't miss out on this exclusive offer!", "Act now before it's too late!",
    "Urgent: Phishing alert!", "Your account has been compromised!",
    "Spam", "Junk mail", "UCE", "UBE",
    NULL
};

// Function to check if a string contains any of the spam words
int contains_spam_words(const char *str) {
    for (int i = 0; spam_words[i] != NULL; i++) {
        if (strstr(str, spam_words[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Function to check if an email address is used by spammers
int is_spam_email_address(const char *email) {
    for (int i = 0; spam_email_addresses[i] != NULL; i++) {
        if (strstr(email, spam_email_addresses[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Function to check if an email subject line is used by spammers
int is_spam_subject_line(const char *subject) {
    for (int i = 0; spam_subject_lines[i] != NULL; i++) {
        if (strstr(subject, spam_subject_lines[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Function to check if an email is spam
int is_spam(const char *email) {
    // Convert email to lowercase
    char *email_lower = strdup(email);
    for (int i = 0; email_lower[i]; i++) {
        email_lower[i] = tolower(email_lower[i]);
    }

    // Check if email contains any spam words
    if (contains_spam_words(email_lower)) {
        free(email_lower);
        return 1;
    }

    // Check if email address is used by spammers
    char *email_address = strchr(email_lower, '@');
    if (email_address != NULL && is_spam_email_address(email_address)) {
        free(email_lower);
        return 1;
    }

    // Check if email subject line is used by spammers
    char *subject_line = strchr(email_lower, ':');
    if (subject_line != NULL && is_spam_subject_line(subject_line)) {
        free(email_lower);
        return 1;
    }

    // Otherwise, email is not spam
    free(email_lower);
    return 0;
}

int main() {
    // Get email from user
    char email[256];
    printf("Enter email: ");
    scanf("%s", email);

    // Check if email is spam
    if (is_spam(email)) {
        printf("Spam detected!\n");
    } else {
        printf("Email is not spam.\n");
    }

    return 0;
}