//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 10
#define MAX_EMAIL_LENGTH 256
#define KEYWORD_LENGTH 16

// Define the keywords to be checked for
char *keywords[MAX_KEYWORDS] = {
    "viagra",
    "cialis",
    "levitra",
    "priapism",
    "penis",
    "erectile",
    "dick",
    "penis_enlargement",
    "free_money",
    "work_from_home"
};

// Function to check if a given string contains any of the keywords
int contains_keyword(char *email, char *keyword) {
    int keyword_length = strlen(keyword);
    int email_length = strlen(email);

    for (int i = 0; i <= email_length - keyword_length; i++) {
        int j;
        for (j = 0; j < keyword_length; j++) {
            if (toupper(email[i + j]) != toupper(keyword[j])) {
                break;
            }
        }
        if (j == keyword_length) {
            return 1;
        }
    }

    return 0;
}

// Function to check if an email is potential spam based on keyword presence
int is_spam(char *email) {
    int num_keywords = 0;

    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (contains_keyword(email, keywords[i])) {
            num_keywords++;
        }
    }

    return num_keywords > 3;
}

int main() {
    char email[MAX_EMAIL_LENGTH];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (is_spam(email)) {
        printf("This email is likely spam.\n");
    } else {
        printf("This email is not likely spam.\n");
    }

    return 0;
}