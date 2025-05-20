//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

char* generate_password(int length);

int main()
{
    int length;
    char* password;

    /* seed random number generator */
    srand(time(NULL));

    printf("Enter the desired password length (up to %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    /* generate password */
    password = generate_password(length);

    printf("Your generated password is: %s\n", password);

    /* free memory */
    free(password);

    return 0;
}

/* function to generate a secure password */
char* generate_password(int length)
{
    int i, rand_num, count_upper = 0, count_lower = 0, count_digit = 0, count_special = 0;
    char* password = (char*) malloc((length + 1) * sizeof(char));

    /* generate random characters for password */
    for (i = 0; i < length; i++)
    {
        rand_num = rand() % 4;

        if (rand_num == 0 && count_upper < 2)
        {
            password[i] = (char) (rand() % 26 + 'A');
            count_upper++;
        }
        else if (rand_num == 1 && count_lower < 2)
        {
            password[i] = (char) (rand() % 26 + 'a');
            count_lower++;
        }
        else if (rand_num == 2 && count_digit < 2)
        {
            password[i] = (char) (rand() % 10 + '0');
            count_digit++;
        }
        else
        {
            password[i] = (char) (rand() % 15 + '!');

            /* make sure special character is not a space */
            while (password[i] == ' ')
            {
                password[i] = (char) (rand() % 15 + '!');
            }

            count_special++;
        }
    }

    /* check if password meets requirements */
    if (count_upper < 2)
    {
        /* add uppercase character if necessary */
        for (i = 0; i < length; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                password[i] = (char) (password[i] - 32);
                break;
            }
        }
    }

    if (count_lower < 2)
    {
        /* add lowercase character if necessary */
        for (i = 0; i < length; i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z')
            {
                password[i] = (char) (password[i] + 32);
                break;
            }
        }
    }

    if (count_digit < 2)
    {
        /* add digit if necessary */
        for (i = 0; i < length; i++)
        {
            if ((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z'))
            {
                password[i] = (char) (rand() % 10 + '0');
                break;
            }
        }
    }

    if (count_special < 2)
    {
        /* add special character if necessary */
        for (i = 0; i < length; i++)
        {
            if ((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >= '0' && password[i] <= '9'))
            {
                password[i] = (char) (rand() % 15 + '!');

                /* make sure special character is not a space */
                while (password[i] == ' ')
                {
                    password[i] = (char) (rand() % 15 + '!');
                }

                break;
            }
        }
    }

    /* add null terminator */
    password[length] = '\0';

    return password;
}