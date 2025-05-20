//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1000

int main()
{
    char email[MAX_EMAIL_LENGTH];
    printf("Enter an email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    int length = strlen(email);
    if (email[length-1] == '\n') {
        email[length-1] = '\0'; // remove newline character added by fgets
    }

    // Check for spam keywords
    const char* spamKeywords[] = {"viagra", "lottery", "inheritance", "money-back guarantee"};
    int numKeywords = sizeof(spamKeywords) / sizeof(spamKeywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strstr(email, spamKeywords[i]) != NULL) {
            printf("This email is spam.\n");
            return 0;
        }
    }

    // Check for suspicious email address format
    char* atSymbol = strchr(email, '@');

    if (atSymbol == NULL) {
        printf("This email is invalid.\n");
        return 0;
    }

    if (strchr(atSymbol + 1, '@') != NULL) {
        printf("This email is invalid.\n");
        return 0;
    }

    char* dotSymbol = strchr(atSymbol, '.');

    if (dotSymbol == NULL || strchr(dotSymbol + 1, '.') != NULL) {
        printf("This email is invalid.\n");
        return 0;
    }

    printf("This email is not spam.\n");
    return 0;
}