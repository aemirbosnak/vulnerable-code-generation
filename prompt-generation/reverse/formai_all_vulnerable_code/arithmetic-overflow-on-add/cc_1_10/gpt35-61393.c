//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to generate a secure password */
char* generatePassword(int length)
{
    /* Arrays for password components */
    char* lowercase = "abcdefghijklmnopqrstuvwxyz";
    char* uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numbers = "0123456789";
    char* symbols = "!@#$%^&*()_+{}|[]\\:\";'<>?,./";
    char* password = (char*) malloc((length + 1) * sizeof(char));
    password[length] = '\0';

    srand(time(NULL)); /* Seed the random number generator */

    /* Add random characters */
    for (int i = 0; i < length; i++)
    {
        int component = rand() % 4; /* Choose a random component */
        int index;

        switch (component)
        {
            case 0: /* Lowercase */
                index = rand() % strlen(lowercase);
                password[i] = lowercase[index];
                break;
            case 1: /* Uppercase */
                index = rand() % strlen(uppercase);
                password[i] = uppercase[index];
                break;
            case 2: /* Numbers */
                index = rand() % strlen(numbers);
                password[i] = numbers[index];
                break;
            case 3: /* Symbols */
                index = rand() % strlen(symbols);
                password[i] = symbols[index];
                break;
        }
    }

    return password;
}

int main()
{
    int length;

    printf("My dearest, please tell me the desired length of your secure password:\n");
    scanf("%d", &length);

    char* password = generatePassword(length);

    printf("My sweet love, your secure password is: %s\n", password);

    free(password); /* Free the password memory */

    return 0;
}