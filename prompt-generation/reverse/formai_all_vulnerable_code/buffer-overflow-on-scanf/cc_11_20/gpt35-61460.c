//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
/* 
   The Secure Password Generator 
   by Sherlock Holmes
  
   This program generates a secure password consisting of random 
   upper and lowercase letters, numerals, and special characters.
  
   To begin, please enter the length of the password that you 
   require (between 8 and 32 characters):
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, count, letters, digits, special;
    char password[33];
    char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789`~!@#$%^&*()_+-=[]{}\\|;:'\",.<>/ ?";

    /* Seed the random number generator */
    srand(time(NULL));

    printf("Good day! I am Sherlock Holmes, and I am here to generate a secure password for you.\n\n");
    printf("Please enter the length of the password that you require (between 8 and 32 characters):\n");
    scanf("%d", &length);

    /* Validate the user input */
    if (length < 8 || length > 32)
    {
        printf("I apologize, but the length of the password must be between 8 and 32 characters.\n");
        return 0;
    }
    else
    {
        printf("Very good. Generating password now...\n");
    }

    /* Initialize the counts */
    count = letters = digits = special = 0;

    /* Generate the password */
    while (count < length)
    {
        /* Choose a random character from the pool */
        int index = rand() % (sizeof(pool) - 1);

        /* Classify the character */
        if ((pool[index] >= 'A' && pool[index] <= 'Z') || (pool[index] >= 'a' && pool[index] <= 'z'))
        {
            /* Letter */
            if (letters < length / 2)
            {
                password[count++] = pool[index];
                letters++;
            }
        }
        else if (pool[index] >= '0' && pool[index] <= '9')
        {
            /* Digit */
            if (digits < length / 4)
            {
                password[count++] = pool[index];
                digits++;
            }
        }
        else
        {
            /* Special character */
            if (special < length / 4)
            {
                password[count++] = pool[index];
                special++;
            }
        }
    }

    /* Shuffle the password */
    for (int i = 0; i < length; i++)
    {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    /* Print the password */
    printf("\nYour secure password is: %s\n", password);

    return 0;
}