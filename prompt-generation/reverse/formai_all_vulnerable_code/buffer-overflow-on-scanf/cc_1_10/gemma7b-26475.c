//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PASSWD_LEN 255

int main()
{
    char passwd[MAX_PASSWD_LEN];
    int pass_len;
    int strength = 0;
    char msg[100];

    printf("Let's crack that password, baby!\n");

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", passwd);

    // Calculate the password length
    pass_len = strlen(passwd);

    // Check if the password meets the minimum length requirement
    if (pass_len < 8)
    {
        strcpy(msg, "Your password is too short, my friend. Try again!");
        goto fail;
    }

    // Check if the password contains numbers
    for (int i = 0; i < pass_len; i++)
    {
        if (isdigit(passwd[i]))
            strength++;
    }

    // Check if the password contains letters
    for (int i = 0; i < pass_len; i++)
    {
        if (islower(passwd[i]) || isupper(passwd[i]))
            strength++;
    }

    // Check if the password contains special characters
    for (int i = 0; i < pass_len; i++)
    {
        if (!isalnum(passwd[i]))
            strength++;
    }

    // Calculate the password strength percentage
    strength = (strength / pass_len) * 100;

    // Print the password strength
    printf("Your password strength is: %d%%", strength);

    // Success!
    return 0;

fail:
    // Print the error message
    printf("%s\n", msg);

    return 1;
}