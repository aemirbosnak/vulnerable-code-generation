//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: future-proof
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_URL_LENGTH 2048

//Function to check if a character is valid in a URL
int is_valid_url_char(char c)
{
    if(c >= 'a' && c <= 'z')
        return 1;
    else if(c >= 'A' && c <= 'Z')
        return 1;
    else if(c >= '0' && c <= '9')
        return 1;
    else if(c == '-' || c == '.' || c == '_' || c == '~' || c == '!' || c == '$' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == ';' || c == '=' || c == ':' || c == '@' || c == '[')
        return 1;
    else
        return 0;
}

//Function to sanitize a URL by removing invalid characters
void sanitize_url(char* url)
{
    int i, j;
    char valid_url[MAX_URL_LENGTH];
    valid_url[0] = '\0';

    //Copy valid characters to new string
    for(i = 0; i < strlen(url); i++)
    {
        if(is_valid_url_char(url[i]))
        {
            strncat(valid_url, &url[i], 1);
        }
    }

    //Copy new string back to original string
    strcpy(url, valid_url);
}

int main()
{
    char url[MAX_URL_LENGTH];
    printf("Enter a URL: ");
    scanf("%s", url);

    //Sanitize URL
    sanitize_url(url);

    //Print sanitized URL
    printf("Sanitized URL: %s\n", url);

    return 0;
}