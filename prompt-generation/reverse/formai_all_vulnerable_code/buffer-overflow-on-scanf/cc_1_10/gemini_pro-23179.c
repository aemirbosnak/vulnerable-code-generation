//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Spam filter function
bool isSpam(char *email) {
    // Check for common spam keywords
    char *keywords[] = {"free", "money", "win", "prize", "urgent"};
    for (int i = 0; i < 5; i++) {
        if (strstr(email, keywords[i]) != NULL) {
            return true;
        }
    }

    // Check for suspicious sender addresses
    char *suspicious_domains[] = {"@spam.com", "@scam.net", "@phishing.org"};
    for (int i = 0; i < 3; i++) {
        if (strstr(email, suspicious_domains[i]) != NULL) {
            return true;
        }
    }

    // Check for excessive capitalization
    int capital_count = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] >= 'A' && email[i] <= 'Z') {
            capital_count++;
        }
    }

    if (capital_count > strlen(email) / 2) {
        return true;
    }

    // Check for excessive punctuation
    int punctuation_count = 0;
    char punctuation[] = {'.', ',', '!', '?', ':'};
    for (int i = 0; i < strlen(email); i++) {
        for (int j = 0; j < 5; j++) {
            if (email[i] == punctuation[j]) {
                punctuation_count++;
            }
        }
    }

    if (punctuation_count > strlen(email) / 10) {
        return true;
    }

    // Otherwise, not spam
    return false;
}

int main() {
    // Get the email from the user
    char email[100];
    printf("Enter the email address: ");
    scanf("%s", email);

    // Check if the email is spam
    bool result = isSpam(email);

    // Print the result
    if (result) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}