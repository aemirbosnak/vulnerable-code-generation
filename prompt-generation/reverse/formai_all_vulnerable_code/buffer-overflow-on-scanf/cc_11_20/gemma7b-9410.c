//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char email[1024];
    printf("Enter email address: ");
    scanf("%s", email);

    // Check if email address contains common spam indicators
    int contains_spam_indicator = 0;
    char *indicators[] = {"free", "lottery", "miracle", "quick", "urgent", "prize"};
    for (int i = 0; i < 6; i++)
    {
        if (strstr(email, indicators[i]) != NULL)
        {
            contains_spam_indicator = 1;
        }
    }

    // Check if email has excessive punctuation or capitalization
    int has_excessive_punctuation = 0;
    char *punctuation_indicators[] = {".", ",", "!", "?"};
    for (int i = 0; i < 3; i++)
    {
        if (strstr(email, punctuation_indicators[i]) != NULL)
        {
            has_excessive_punctuation = 1;
        }
    }

    // Check if email has a suspicious sender or domain name
    int has_suspicious_sender = 0;
    char *suspicious_senders[] = {"hotmail.com", "gmail.com", "yahoo.com"};
    char *suspicious_domains[] = {"hotmail.com", "gmail.com", "yahoo.com"};
    for (int i = 0; i < 3; i++)
    {
        if (strstr(email, suspicious_senders[i]) != NULL || strstr(email, suspicious_domains[i]) != NULL)
        {
            has_suspicious_sender = 1;
        }
    }

    // If any indicators are found, flag the email as spam
    if (contains_spam_indicator || has_excessive_punctuation || has_suspicious_sender)
    {
        printf("Your email has been flagged as spam.\n");
    }
    else
    {
        printf("Your email is not flagged as spam.\n");
    }

    return 0;
}