//Gemma-7B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pw_manager(char **pwd, int index)
{
    char new_pwd[20];
    int i = 0;

    printf("Enter a new password: ");
    scanf("%s", new_pwd);

    if (index == -1)
    {
        *pwd = malloc(20);
        strcpy(*pwd, new_pwd);
    }
    else
    {
        pwd[index] = malloc(20);
        strcpy(pwd[index], new_pwd);
    }

    for (i = 0; new_pwd[i] != '\0'; i++)
    {
        printf("%c", new_pwd[i]);
    }

    printf("\n");

    if (index == -1)
    {
        printf("New password created!\n");
    }
    else
    {
        printf("Password updated!\n");
    }

    pw_manager(pwd, index + 1);
}

int main()
{
    char **pwd = NULL;
    int index = -1;

    pw_manager(pwd, index);

    return 0;
}