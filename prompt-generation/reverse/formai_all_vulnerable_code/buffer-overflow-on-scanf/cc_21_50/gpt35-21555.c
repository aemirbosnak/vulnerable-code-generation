//FormAI DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Surreal Password Management System

int main()
{
    char password[50];
    int password_length;
    int password_strength = 0;
    int is_valid_password = 0;

    printf("Welcome to the Surreal Password Management System\n");
    printf("Please enter your new password: ");
    scanf("%s", password);

    password_length = strlen(password);

    // Check password length
    if (password_length < 8)
    {
        printf("Password length must be at least 8 characters\n");
    }
    else
    {
        printf("Password length is valid\n");
        password_strength += 1;
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            password_strength += 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            password_strength += 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < password_length; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            password_strength += 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < password_length; i++)
    {
        if ((password[i] >= '!' && password[i] <= '/') ||
            (password[i] >= ':' && password[i] <= '@') ||
            (password[i] >= '[' && password[i] <= '^') ||
            (password[i] >= '{' && password[i] <= '~'))
        {
            password_strength += 1;
            break;
        }
    }

    // Check overall strength level
    if (password_strength == 1)
    {
        printf("Weak password. Please choose a stronger one.\n");
    }
    else if (password_strength == 2)
    {
        printf("Moderate password. Consider improving it.\n");
    }
    else if (password_strength == 3)
    {
        printf("Strong password. Well done!\n");
    }
    else if (password_strength == 4)
    {
        printf("Surreal password. The universe applauds your creativity.\n");
    }
    else
    {
        printf("Error: Invalid password strength level\n");
        exit(1);
    }

    // Check for repeating characters
    for (int i = 0; i < password_length - 1; i++)
    {
        if (password[i] == password[i + 1])
        {
            printf("Password contains repeating characters. Please choose a different one.\n");
            is_valid_password = 0;
            exit(1);
        }
    }

    // Check for palindrome password
    int is_palindrome = 1;

    for (int i = 0; i < password_length / 2; i++)
    {
        if (password[i] != password[password_length - i - 1])
        {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome)
    {
        printf("Palindromic password detected. This could be a sign of greater things to come.\n");
    }

    // Check for prime password length
    int is_prime = 1;

    for (int i = 2; i < password_length; i++)
    {
        if (password_length % i == 0)
        {
            is_prime = 0;
            break;
        }
    }

    if (is_prime)
    {
        printf("The length of your password is prime. This bodes well for your future.\n");
    }

    printf("Password is valid and accepted by the surreal universe.\n");

    return 0;
}