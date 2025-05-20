//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define SYMBOLS "!@#$%^&*()_+{}|:<>?-=[];'\\,.\""

char *generate_password(int length);

int main(void)
{
    int length;
    char *password;

    /* seed RNG */
    srand(time(NULL));

    printf("How long would you like your password to be? (at least 8 characters)\n");
    scanf("%d", &length);

    while ((length < MIN_LENGTH) || (length > MAX_LENGTH))
    {
        printf("Invalid input. Password length must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        printf("Please enter a valid length:\n");
        scanf("%d", &length);
    }

    password = generate_password(length);
    printf("Your new password is: %s\n", password);
    free(password);

    return 0;
}

char *generate_password(int length)
{
    char *password;
    int i, num_chars, index;

    /* allocate memory for the password */
    password = (char *) malloc((length + 1) * sizeof(char));

    /* randomize number of non-alphabetic characters in the password */
    num_chars = length / 2 + (rand() % (length / 2));

    /* fill password with letters */
    for (i = 0; i < length - num_chars; i++)
    {
        /* 50/50 chance for uppercase vs lowercase */
        if (rand() % 2)
            password[i] = rand() % 26 + 'A';
        else
            password[i] = rand() % 26 + 'a';
    }

    /* add non-alphabetic characters to password */
    for (; i < length; i++)
    {
        /* 25% chance for a symbol vs a number */
        if (rand() % 4 == 0)
            password[i] = SYMBOLS[rand() % sizeof(SYMBOLS)];
        else
            password[i] = rand() % 10 + '0';
    }

    /* shuffle characters in password */
    for (i = length - 1; i > 0; i--)
    {
        index = rand() % (i + 1);
        /* swap two characters */
        password[i] ^= password[index];
        password[index] ^= password[i];
        password[i] ^= password[index];
    }

    /* null-terminate the password */
    password[length] = '\0';

    return password;
}