//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

void sanitize_user_input(char *name)
{
    // Remove all non-alphabetic characters from the name
    char *p = name;
    while (*p)
    {
        if (!isalnum(*p))
        {
            *p = '\0';
        }
        p++;
    }

    // Normalize the name to uppercase
    char *q = name;
    while (*q)
    {
        *q = toupper(*q);
        q++;
    }

    // Check if the name is too long
    if (strlen(name) > MAX_NAME_LENGTH)
    {
        name = NULL;
    }
}

int main()
{
    char name[MAX_NAME_LENGTH] = "";

    printf("Enter your name: ");
    scanf("%s", name);

    sanitize_user_input(name);

    if (name)
    {
        printf("Welcome, %s!", name);
    }
    else
    {
        printf("Error: Invalid name.");
    }

    return 0;
}