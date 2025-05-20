//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main()
{
    char password [50];
    printf("Please enter a password: ");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    // check password length
    if(length < 8)
    {
        printf("Your password is too short. It must be at least 8 characters in length.\n");
    }
    else
    {
        score++;
    }

    // check for uppercase letters
    int i;
    for(i = 0; i < length; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
        {
            score++;
            break;
        }
    }

    // check for lowercase letters
    for(i = 0; i < length; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
        {
            score++;
            break;
        }
    }

    // check for numbers
    for(i = 0; i < length; i++)
    {
        if(password[i] >= '0' && password[i] <= '9')
        {
            score++;
            break;
        }
    }

    // check for special characters
    for(i = 0; i < length; i++)
    {
        if((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '^') || (password[i] == '_') || (password[i] == '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            score++;
            break;
        }
    }

    // print password strength based on score
    if(score == 1)
    {
        printf("Weak password. Please include uppercase letters, lowercase letters, numbers, and special characters.\n");
    }
    else if(score == 2)
    {
        printf("Moderate password. Please include more types of characters.\n");
    }
    else if(score == 3)
    {
        printf("Strong password. Please include more types of characters.\n");
    }
    else if(score == 4)
    {
        printf("Very strong password. Good job!\n");
    }

    return 0;
}