//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    printf("Enter a message: ");
    scanf("%s", str);

    int spamscore = 0;
    char *p = str;

    // Check for common spam words
    char *words[] = {"free", "lottery", "miracle", "prize", "miracle"};
    for (int i = 0; i < 5; i++)
    {
        if (strstr(p, words[i]) != NULL)
        {
            spamscore++;
        }
    }

    // Check for suspicious punctuation
    char suspicious_punc[] = {'.', '?', '!', '$', '*'};
    for (int i = 0; i < 6; i++)
    {
        if (strchr(p, suspicious_punc[i]) != NULL)
        {
            spamscore++;
        }
    }

    // Check for unusual word combinations
    char *combo[] = {" Viagra", "Cialis", "Get Quick", "Free Money", "Click Here"};
    for (int i = 0; i < 5; i++)
    {
        if (strstr(p, combo[i]) != NULL)
        {
            spamscore++;
        }
    }

    // Check for excessive capitalization
    int caps_count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            caps_count++;
        }
    }

    if (spamscore > 3)
    {
        printf("Your message is likely to be spam. Score: %d", spamscore);
    }
    else
    {
        printf("Your message is not likely to be spam. Score: %d", spamscore);
    }

    return 0;
}