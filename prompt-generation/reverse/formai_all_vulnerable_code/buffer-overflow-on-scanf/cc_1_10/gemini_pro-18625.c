//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string contains only digits
int is_digits(const char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only lower case letters
int is_lower(const char *str)
{
    while (*str)
    {
        if (*str < 'a' || *str > 'z')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only upper case letters
int is_upper(const char *str)
{
    while (*str)
    {
        if (*str < 'A' || *str > 'Z')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only alpha-numeric characters
int is_alphanumeric(const char *str)
{
    while (*str)
    {
        if (!((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string contains only printable characters
int is_printable(const char *str)
{
    while (*str)
    {
        if (*str < ' ' || *str > '~')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to check if a string is a valid email address
int is_email(const char *str)
{
    int at_count = 0;
    int dot_count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '@')
        {
            at_count++;
        }
        else if (str[i] == '.')
        {
            dot_count++;
        }
        i++;
    }

    if (at_count != 1 || dot_count < 1)
    {
        return 0;
    }

    return 1;
}

// Function to check if a string is a valid URL
int is_url(const char *str)
{
    int i = 0;

    if (strncmp(str, "http://", 7) != 0 && strncmp(str, "https://", 8) != 0)
    {
        return 0;
    }

    while (str[i] != '\0')
    {
        if (!isalnum(str[i]) && str[i] != '-' && str[i] != '.' && str[i] != '/' && str[i] != ':' && str[i] != '@' && str[i] != '&' && str[i] != '=' && str[i] != '?')
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int main()
{
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (is_digits(input))
    {
        printf("The string contains only digits.\n");
    }
    else if (is_lower(input))
    {
        printf("The string contains only lower case letters.\n");
    }
    else if (is_upper(input))
    {
        printf("The string contains only upper case letters.\n");
    }
    else if (is_alphanumeric(input))
    {
        printf("The string contains only alpha-numeric characters.\n");
    }
    else if (is_printable(input))
    {
        printf("The string contains only printable characters.\n");
    }
    else if (is_email(input))
    {
        printf("The string is a valid email address.\n");
    }
    else if (is_url(input))
    {
        printf("The string is a valid URL.\n");
    }
    else
    {
        printf("The string does not match any of the predefined categories.\n");
    }

    return 0;
}