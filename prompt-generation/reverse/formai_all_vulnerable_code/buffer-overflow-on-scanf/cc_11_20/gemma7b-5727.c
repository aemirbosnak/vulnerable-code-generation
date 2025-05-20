//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWD_LEN 255

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int i, strength = 0, min_chars = 0, max_chars = 0, num_nums = 0, has_symbols = 0;

    printf("Enter your password: ");
    scanf("%s", passwd);

    // Iterate over the password to check its strength
    for (i = 0; passwd[i] != '\0'; i++)
    {
        // Check for minimum characters
        if (islower(passwd[i]) || isupper(passwd[i]) || isdigit(passwd[i]) || ispunct(passwd[i]))
            min_chars++;

        // Check for maximum characters
        if (isupper(passwd[i]))
            max_chars++;

        // Check for numerical characters
        if (isdigit(passwd[i]))
            num_nums++;

        // Check for symbols
        if (ispunct(passwd[i]))
            has_symbols++;
    }

    // Calculate the password strength
    strength = (min_chars * 2) + max_chars + num_nums + has_symbols;

    // Print the password strength
    switch (strength)
    {
        case 0:
            printf("Your password is very weak. Please use a stronger password.");
            break;
        case 1:
            printf("Your password is weak. Please use a stronger password.");
            break;
        case 2:
            printf("Your password is moderate. It could be stronger.");
            break;
        case 3:
            printf("Your password is strong. It meets all the criteria.");
            break;
        case 4:
            printf("Your password is very strong. It is highly unlikely to be cracked.");
            break;
    }

    return 0;
}