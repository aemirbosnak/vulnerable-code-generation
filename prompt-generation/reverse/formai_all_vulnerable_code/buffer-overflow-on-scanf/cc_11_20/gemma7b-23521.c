//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASS_LEN 256

int main()
{
    char pass[MAX_PASS_LEN];
    int i, score = 0, min_score = 0, max_score = 0, pass_len = 0;

    printf("Enter your password: ");
    scanf("%s", pass);

    pass_len = strlen(pass);

    if (pass_len < 8)
    {
        min_score = 1;
    }
    else if (pass_len >= 8 && pass_len < 12)
    {
        min_score = 2;
    }
    else if (pass_len >= 12 && pass_len < 16)
    {
        min_score = 3;
    }
    else if (pass_len >= 16)
    {
        min_score = 4;
    }

    for (i = 0; i < pass_len; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            score++;
        }
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            score++;
        }
        else if (pass[i] >= '0' && pass[i] <= '9')
        {
            score++;
        }
        else if (pass[i] == '$' || pass[i] == '#' || pass[i] == '%')
        {
            score++;
        }
    }

    max_score = score;

    if (min_score > 0)
    {
        printf("Your password has a minimum score of %d.\n", min_score);
    }

    if (max_score > 0)
    {
        printf("Your password has a maximum score of %d.\n", max_score);
    }

    return 0;
}