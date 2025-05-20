//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[1000];

    printf("Enter a message: ");
    gets(str);

    // Check for common spam words
    char *spam_words[] = {"free", "lottery", "miracle", "prize", "miracle"};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            printf("Spam detected!\n");
            break;
        }
    }

    // Check for caps lock abuse
    int caps_count = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            caps_count++;
        }
    }
    if (caps_count > 10)
    {
        printf("Caps lock abuse detected!\n");
    }

    // Check for excessive punctuation
    int punctuation_count = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
        {
            punctuation_count++;
        }
    }
    if (punctuation_count > 5)
    {
        printf("Excessive punctuation detected!\n");
    }

    // Check for suspicious email addresses
    char *suspicious_domains[] = {"hotmail.com", "yahoo.com", "gmail.com"};
    for (i = 0; i < 3; i++)
    {
        if (strstr(str, suspicious_domains[i]) != NULL)
        {
            printf("Suspicious email address detected!\n");
            break;
        }
    }

    // If no spam indicators found, print "Message accepted"
    if (i == 5 && caps_count <= 10 && punctuation_count <= 5 && suspicious_domains[i] == NULL)
    {
        printf("Message accepted.\n");
    }

    return 0;
}