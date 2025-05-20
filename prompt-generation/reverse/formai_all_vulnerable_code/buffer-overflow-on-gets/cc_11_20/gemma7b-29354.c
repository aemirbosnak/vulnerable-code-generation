//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[1000];
    printf("Enter a message: ");
    gets(str);

    // Check if the message contains common spam words
    char* spam_words[] = {"free", "lottery", "miracle", "prize", "miracle"};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (strstr(str, spam_words[i]) != NULL)
        {
            printf("Warning: This message contains spam words.\n");
            break;
        }
    }

    // Check if the message contains excessive punctuation
    int punct_count = 0;
    char* punct_chars = {".", ",", "?", "!", "$", "&"};
    for (i = 0; i < 7; i++)
    {
        if (strstr(str, punct_chars[i]) != NULL)
        {
            punct_count++;
        }
    }
    if (punct_count > 10)
    {
        printf("Warning: This message contains excessive punctuation.\n");
    }

    // Check if the message contains unusual formatting
    if (strstr(str, "**") != NULL || strstr(str, "_") != NULL)
    {
        printf("Warning: This message contains unusual formatting.\n");
    }

    // If no warnings are found, print the message
    if (i == 5 && punct_count <= 10 && strstr(str, "**") == NULL && strstr(str, "_") == NULL)
    {
        printf("Your message: %s\n", str);
    }

    return 0;
}