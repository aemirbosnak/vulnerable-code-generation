//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 255

int main()
{
    char password[MAX_PASSWORD_LENGTH];

    printf("Hey there, my friend! Let's see if you can crack this password...\n");

    printf("Enter your password: ");
    scanf("%s", password);

    int password_strength = check_password_strength(password);

    switch (password_strength)
    {
        case 0:
            printf("Oh no! Your password is too weak. It's like a squirrel on a picnic table.\n");
            break;
        case 1:
            printf("Not bad, but could be better. It's like a bicycle lock, but not quite.\n");
            break;
        case 2:
            printf("Pretty strong! It's like a chain on a tank. You're doing great!\n");
            break;
        case 3:
            printf("Wow! Your password is super strong. It's like a nuclear warhead, but without the destruction.\n");
            break;
        default:
            printf("Error! Invalid password strength.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password)
{
    int password_length = strlen(password);

    if (password_length < 8)
    {
        return 0;
    }

    for (int i = 0; i < password_length; i++)
    {
        if (!isalnum(password[i]))
        {
            return 0;
        }
    }

    return 3;
}