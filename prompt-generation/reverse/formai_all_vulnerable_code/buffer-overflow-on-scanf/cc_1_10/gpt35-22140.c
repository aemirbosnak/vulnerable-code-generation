//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void shuffle(char *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int c = array[j];
          array[j] = array[i];
          array[i] = c;
        }
    }
}

int main()
{
    int length, num, cap, spec;
    char chars[62] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char passedChars[94] = "!@#$%^&*()_+-={}[]\\|;:\'\",<.>/?`~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // seed for random shuffle
    srand(time(NULL));

    printf("Enter password length: ");
    scanf("%d", &length);

    printf("Enter the number of numeric characters: ");
    scanf("%d", &num);

    printf("Enter the number of uppercase characters: ");
    scanf("%d", &cap);

    printf("Enter the number of special characters: ");
    scanf("%d", &spec);

    // check if required number of characters exceeds length of password
    if (num + cap + spec > length)
    {
        printf("Total number of characters exceeds password length. Please try again.\n");
        return 0;
    }

    char password[length + 1];

    // add numeric characters
    for (int i = 0; i < num; i++)
    {
        password[i] = chars[rand() % 10 + 52];
    }

    // add uppercase characters
    for (int i = num; i < num + cap; i++)
    {
        password[i] = chars[rand() % 26 + 26];
    }

    // add special characters
    for (int i = num + cap; i < num + cap + spec; i++)
    {
        password[i] = passedChars[rand() % 32];
    }

    // add remaining characters
    for (int i = num + cap + spec; i < length; i++)
    {
        password[i] = chars[rand() % 62];
    }

    // shuffle password
    shuffle(password, length);

    password[length] = '\0';

    printf("Generated password: %s\n", password);
    return 0;
}