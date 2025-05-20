//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include<stdio.h>
#include<string.h>

#define MAX_URL_LENGTH 1000

int main()
{
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    int i;
    int invalid_char_count = 0;
    int double_slash_count = 0;
    int period_count = 0;

    for(i=0;i<strlen(url);i++)
    {
        if(url[i] == ':' && url[i+1] != '/' && url[i+2] != '/')
        {
            printf("Invalid URL format. URL should start with http:// or https://\n");
            return -1;
        }

        if((url[i] < 'A' || url[i] > 'Z') && (url[i] < 'a' || url[i] > 'z') && (url[i] < '0' || url[i] > '9') && url[i] != '.' && url[i] != ':' && url[i] != '/' && url[i] != '?' && url[i] != '&' && url[i] != '=' && url[i] != '-')
        {
            invalid_char_count++;
        }

        if(url[i] == ':' && url[i+1] == '/' && url[i+2] == '/')
        {
            double_slash_count++;
        }

        if(url[i] == '.')
        {
            period_count++;
        }
    }

    if(double_slash_count != 1)
    {
        printf("Invalid URL format. URL should contain exactly one instance of '://'\n");
        return -1;
    }

    if(period_count < 1)
    {
        printf("Invalid URL format. URL should contain at least one period '.'\n");
        return -1;
    }

    printf("\n--------------------------------------------------\n");
    printf("Sanitized URL: ");
    for(i=0;i<strlen(url);i++)
    {
        if((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i] <= '9') || 
        url[i] == '.' || url[i] == ':' || url[i] == '/' || url[i] == '?' || url[i] == '&' || url[i] == '=' || url[i] == '-')
        {
            printf("%c", url[i]);
        }
    }
    printf("\n--------------------------------------------------\n");

    if(invalid_char_count > 0)
    {
        printf("There were %d invalid characters in the URL\n", invalid_char_count);
    }

    return 0;
}