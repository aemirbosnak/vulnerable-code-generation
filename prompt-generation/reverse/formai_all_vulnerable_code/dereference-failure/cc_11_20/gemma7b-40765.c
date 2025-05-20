//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1024];
    printf("Enter a message: ");
    fgets(str, 1024, stdin);

    // Check for common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "miracle"};
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strstr(str, spam_words[i]))
        {
            printf("Spam detected!\n");
            break;
        }
    }

    // Check for excessive punctuation
    int count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
            count++;
    }
    if (count > 10)
    {
        printf("Excessive punctuation detected!\n");
    }

    // Check for unusual character combinations
    char suspicious_chars[] = {"$%^&*()"};
    for (i = 0; i < 6; i++)
    {
        if (strstr(str, suspicious_chars[i]))
        {
            printf("Suspicious character combinations detected!\n");
            break;
        }
    }

    if (spam_words[i] || count > 10 || suspicious_chars[i])
    {
        printf("Message flagged as suspicious.\n");
    }
    else
    {
        printf("Message is safe.\n");
    }

    return 0;
}