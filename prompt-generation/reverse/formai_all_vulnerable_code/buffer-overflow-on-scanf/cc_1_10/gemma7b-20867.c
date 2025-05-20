//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASS_LENGTH 128
#define UPPER_LETTERS 'A'
#define LOWER_LETTERS 'a'
#define NUMERIC_DIGITS '0'
#define SYMBOLS "$%^&*()"

int main()
{
    int pass_length;
    char *password;
    time_t t;
    srand(time(&t));

    printf("Enter desired password length: ");
    scanf("%d", &pass_length);

    if (pass_length < 1)
    {
        printf("Error: Password length must be at least 1.\n");
        return 1;
    }

    if (pass_length > MAX_PASS_LENGTH)
    {
        printf("Error: Password length exceeds maximum of %d characters.\n", MAX_PASS_LENGTH);
        return 1;
    }

    password = malloc(pass_length);

    for (int i = 0; i < pass_length; i++)
    {
        switch (rand() % 5)
        {
            case 0:
                password[i] = UPPER_LETTERS + rand() % 26;
                break;
            case 1:
                password[i] = LOWER_LETTERS + rand() % 26;
                break;
            case 2:
                password[i] = NUMERIC_DIGITS + rand() % 10;
                break;
            case 3:
                password[i] = SYMBOLS[rand() % 5];
                break;
            default:
                password[i] = rand() % 256;
                break;
        }
    }

    password[pass_length - 1] = '\0';

    printf("Your generated password is: %s\n", password);

    free(password);

    return 0;
}