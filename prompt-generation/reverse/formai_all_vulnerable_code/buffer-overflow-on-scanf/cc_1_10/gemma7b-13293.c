//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASS_LEN 1024

void check_pass_strength(char *pass)
{
    int i, pass_len = strlen(pass);
    char upper_case_flag = 0, lower_case_flag = 0, number_flag = 0, symbol_flag = 0;

    for (i = 0; i < pass_len; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            lower_case_flag = 1;

        else if (pass[i] >= 'A' && pass[i] <= 'Z')
            upper_case_flag = 1;

        else if (pass[i] >= '0' && pass[i] <= '9')
            number_flag = 1;

        else if (pass[i] >= '!' && pass[i] <= '~')
            symbol_flag = 1;
    }

    if (pass_len < 8)
    {
        printf("Password too short!\n");
    }
    else if (lower_case_flag == 0)
    {
        printf("Missing lowercase letter!\n");
    }
    else if (upper_case_flag == 0)
    {
        printf("Missing uppercase letter!\n");
    }
    else if (number_flag == 0)
    {
        printf("Missing number!\n");
    }
    else if (symbol_flag == 0)
    {
        printf("Missing symbol!\n");
    }
    else
    {
        printf("Password strong!\n");
    }
}

int main()
{
    char pass[MAX_PASS_LEN];

    printf("Enter your password: ");
    scanf("%s", pass);

    check_pass_strength(pass);

    return 0;
}