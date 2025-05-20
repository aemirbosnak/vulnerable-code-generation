//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int get_score(char *password)
{
    int length = strlen(password);
    int score = 0;
    int letters = 0;
    int numbers = 0;
    int symbols = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(password[i]))
        {
            letters++;
            if (i > 0 && !isdigit(password[i - 1]))
            {
                score += 2;
            }
        }
        else if (isdigit(password[i]))
        {
            numbers++;
            if (i > 0 && !isalpha(password[i - 1]))
            {
                score += 2;
            }
        }
        else
        {
            symbols++;
            if (i > 0 && !isdigit(password[i - 1]) && !isalpha(password[i - 1]))
            {
                score += 4;
            }
        }
    }

    // Add points for overall length
    score += length * 4;

    // Add points for extra letters
    score += (letters - length) * 2;

    // Add points for extra numbers
    score += numbers * 4;

    // Add points for extra symbols
    score += symbols * 6;

    // Add bonus points for using a mix of characters
    if (letters > 0 && numbers > 0)
    {
        score += 8;
    }
    if (letters > 0 && symbols > 0)
    {
        score += 12;
    }
    if (numbers > 0 && symbols > 0)
    {
        score += 16;
    }

    return score;
}

int main()
{
    char password[100];
    printf("Enter a password:\n");
    scanf("%s", password);

    int score = get_score(password);

    if (score < 20)
    {
        printf("Password is very weak. Try again.\n");
    }
    else if (score < 40)
    {
        printf("Password is weak. Try again.\n");
    }
    else if (score < 60)
    {
        printf("Password is moderate.\n");
    }
    else if (score < 80)
    {
        printf("Password is strong.\n");
    }
    else
    {
        printf("Password is very strong.\n");
    }

    return 0;
}