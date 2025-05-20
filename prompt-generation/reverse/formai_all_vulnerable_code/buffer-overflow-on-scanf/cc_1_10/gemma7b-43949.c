//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to detect spam in an email
int detectSpam(char *email)
{
    // Check for common spam words
    char *spamWords[] = {"free", "lottery", "miracle", "miracle", "prize"};
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (strstr(email, spamWords[i]) != NULL)
        {
            return 1;
        }
    }

    // Check for suspicious formatting
    if (strstr(email, "!!!"))
    {
        return 1;
    }

    // Check for excessive punctuation
    if (strstr(email, "!!!!") || strstr(email, "???") || strstr(email, "----"))
    {
        return 1;
    }

    // Check for keyword stuffing
    if (strlen(email) > 500)
    {
        return 1;
    }

    // Return 0 if no spam detected
    return 0;
}

int main()
{
    // Get the email to analyze
    char email[1000];
    printf("Enter the email: ");
    scanf("%s", email);

    // Detect spam
    int isSpam = detectSpam(email);

    // Print the results
    if (isSpam == 1)
    {
        printf("Sorry, your email has been flagged as spam.\n");
    }
    else
    {
        printf("Your email is safe.\n");
    }

    return 0;
}