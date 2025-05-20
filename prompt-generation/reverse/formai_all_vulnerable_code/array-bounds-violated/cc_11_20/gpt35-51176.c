//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
// Romeo and Juliet style URL Sanitizer Program
// By your friendly neighborhood chatbot

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Oh URL! URL! wherefore art thou URL?\n");
    printf("Deny thy errors and refuse thy flaws\n");
    printf("Or, if thou wilt not, be but sworn my love\n");
    printf("And I’ll no longer be a chatbot.\n\n");

    // Prompt user for input
    printf("Enter a URL to sanitize: \n");
    char url[200];
    fgets(url, 200, stdin);

    // Remove any whitespace at the beginning or end of the URL
    int i = 0;
    while (isspace(url[i]))
    {
        i++;
    }
    int j = strlen(url) - 1;
    while (isspace(url[j]))
    {
        j--;
    }
    url[j+1] = '\0';
    memmove(url, url+i, strlen(url)-i+1); // Use memmove to shift the string

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0)
    {
        printf("Ah, my love, thou art a URL of good standing\n");

        // Replace any unsafe characters with their URL-encoded equivalents
        char safe_url[400];
        int k = 0;
        for (i = 0; url[i] != '\0'; i++)
        {
            if (url[i] == ' ')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '2';
                safe_url[k++] = '0';
            }
            else if (url[i] == '\"')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '2';
                safe_url[k++] = '2';
            }
            else if (url[i] == '<')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '3';
                safe_url[k++] = 'C';
            }
            else if (url[i] == '>')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '3';
                safe_url[k++] = 'E';
            }
            else if (url[i] == '#')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '2';
                safe_url[k++] = '3';
            }
            else if (url[i] == '%')
            {
                safe_url[k++] = '%';
                safe_url[k++] = '2';
                safe_url[k++] = '5';
            }
            else
            {
                safe_url[k++] = url[i];
            }
        }
        safe_url[k] = '\0';
        printf("Thou art now cleansed of any impurities:\n%s", safe_url);
    }
    else
    {
        printf("Alas, thou art not a URL of good standing\n");
    }

    printf("\nBut soft! What error through yonder window breaks?\n");
    printf("It is not the program, for it doth compile and run without errors.\n");
    return 0;
}