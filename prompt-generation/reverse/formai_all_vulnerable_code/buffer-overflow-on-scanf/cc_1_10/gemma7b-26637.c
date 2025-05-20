//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    printf("Enter a message: ");
    scanf("%s", str);

    int spam_score = 0;

    // Check for common spam words
    char* spam_words[] = {"free", "lottery", "miracle", "miracle"};
    for (int i = 0; i < 4; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            spam_score++;
        }
    }

    // Check for suspicious sentence structure
    char* suspicious_sentences[] = {"You will inherit a million dollars", "Click here to claim your prize", "Free gift!"};
    for (int i = 0; i < 3; i++)
    {
        if (strstr(str, suspicious_sentences[i]) != NULL)
        {
            spam_score++;
        }
    }

    // Check for excessive punctuation
    if (str[0] == '!' || str[0] == '?')
    {
        spam_score++;
    }

    // Check for strange character combinations
    if (strstr(str, "$%^&") != NULL)
    {
        spam_score++;
    }

    // Determine the spam score
    if (spam_score >= 3)
    {
        printf("Your message has been flagged as spam.\n");
    }
    else
    {
        printf("Your message has been accepted.\n");
    }

    return 0;
}