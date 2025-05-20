//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: excited
#include<stdio.h>
#include<string.h>

/* Welcome to the most exciting C URL Sanitizer program ever! 
 * It will make you feel like a superhero who can clean up any URL 
 * and make it safe for browsing. 
 * This program is going to make the internet a safer place. 
 * Let's dive in and save the world!
 */

int main()
{
    char url[1000], sanitized_url[1000];
    int i, j = 0;

    printf("Enter the URL to be sanitized:\n");
    scanf("%s", url);

    // Let's start by checking if the URL has "http://" or "https://"
    if(strstr(url, "http://") != NULL || strstr(url, "https://") != NULL)
    {
        // If the URL starts with "http://" or "https://", the first 7 or 8 characters need to be removed
        for(i=0; i<strlen(url); i++)
        {
            if(i < 7) // If it's http:// or https://, skip those characters
            {
                continue;
            }
            sanitized_url[j] = url[i];
            j++;
        }
    }
    else
    {
        // If the URL doesn't start with "http://" or "https://", add "http://"
        strcat(sanitized_url, "http://");
        strcat(sanitized_url, url);
    }

    // Now let's remove any unwanted characters from the URL
    char *unwanted_chars = "!@#$%^&*()_+{}[]|\\:\";'/?><,.";
    for (i = 0; i < strlen(sanitized_url); i++)
    {
        if (strchr(unwanted_chars, sanitized_url[i]) == NULL)
        {
            sanitized_url[j] = sanitized_url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';

    // Finally, let's print the sanitized URL
    printf("The sanitized URL is: %s\n", sanitized_url);

    return 0;
}

/* Wow! That was exciting! With this C URL Sanitizer program, you can now safely browse the internet and protect your device from malicious URLs. 
 * Let's keep the excitement going by spreading the word about this program and let everyone know how they can save the world too! 
 */