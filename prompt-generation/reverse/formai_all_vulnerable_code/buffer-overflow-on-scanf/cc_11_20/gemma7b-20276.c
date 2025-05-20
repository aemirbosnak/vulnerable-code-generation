//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASS_LEN 255

int main()
{
    char pass[MAX_PASS_LEN];
    int i, strength = 0, min_chars = 0, max_chars = 0, num_nums = 0, has_symbols = 0;

    printf("Enter your password: ");
    scanf("%s", pass);

    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
            min_chars++;
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
            max_chars++;
        else if (pass[i] >= '0' && pass[i] <= '9')
            num_nums++;
        else if (pass[i] >= '!' && pass[i] <= '~')
            has_symbols++;
    }

    strength = (min_chars > 0) ? 1 : 0;
    strength += (max_chars > 0) ? 1 : 0;
    strength += (num_nums > 0) ? 1 : 0;
    strength += (has_symbols > 0) ? 1 : 0;

    switch (strength)
    {
        case 0:
            printf("Your password is weak. Please use a stronger password.\n");
            break;
        case 1:
            printf("Your password is fair. It could be stronger.\n");
            break;
        case 2:
            printf("Your password is good. It meets the recommended criteria.\n");
            break;
        case 3:
            printf("Your password is strong. It is very difficult to crack.\n");
            break;
    }

    return 0;
}