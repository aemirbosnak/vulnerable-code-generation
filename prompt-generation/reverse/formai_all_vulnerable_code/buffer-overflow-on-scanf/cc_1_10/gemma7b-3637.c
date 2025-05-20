//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWD_LEN 256

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int passwd_len;

    printf("Enter a password: ");
    scanf("%s", passwd);
    passwd_len = strlen(passwd);

    if (passwd_len < 8)
    {
        printf("Password too short.\n");
    }
    else if (passwd_len > MAX_PASSWD_LEN)
    {
        printf("Password too long.\n");
    }
    else if (!isupper(passwd[0]) && !isdigit(passwd[0]))
    {
        printf("Password must start with an uppercase letter or number.\n");
    }
    else if (!islower(passwd[passwd_len - 1]) && !isdigit(passwd[passwd_len - 1]))
    {
        printf("Password must end with an lowercase letter or number.\n");
    }
    else if (has_common_words(passwd))
    {
        printf("Password too common.\n");
    }
    else
    {
        printf("Password acceptable.\n");
    }

    return 0;
}

int has_common_words(char *passwd)
{
    char *common_words[] = {"apple", "banana", "orange", "grape", "apricot"};
    int i;

    for (i = 0; i < 5; i++)
    {
        if (strcmp(passwd, common_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}