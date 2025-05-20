//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <string.h>

// Function to generate a unique secure password
char* generateSecurePassword()
{
    char password[20] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_+={}[]|;':,.<>/?~";
    int index = 0;
    int length = strlen(password);
    char* generatedPassword = (char*)malloc(sizeof(char) * 20);

    // Generate a random index for the password
    for (int i = 0; i < 20; i++)
    {
        index = (rand() % length);
        generatedPassword[i] = password[index];
    }

    // Shuffle the password to ensure uniqueness
    for (int i = 0; i < 20; i++)
    {
        int j = rand() % 20;
        char temp = generatedPassword[i];
        generatedPassword[i] = generatedPassword[j];
        generatedPassword[j] = temp;
    }

    return generatedPassword;
}

// Function to check if the password meets the security requirements
int isSecurePassword(char* password)
{
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    // Check if the password contains at least one uppercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUppercase = 1;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLowercase = 1;
        }
    }

    // Check if the password contains at least one digit
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = 1;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '_' || password[i] == '=' || password[i] == '+' || password[i] == '{' || password[i] == '}' || password[i] == '|' || password[i] == ';' || password[i] == ':' || password[i] == '<' || password[i] == '>' || password[i] == '[' || password[i] == ']' || password[i] == '"' || password[i] == '~')
        {
            hasSpecialChar = 1;
        }
    }

    // Check if the password meets the security requirements
    if (hasUppercase && hasLowercase && hasDigit && hasSpecialChar)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to print the password
void printPassword(char* password)
{
    printf("Password: %s\n", password);
}

int main()
{
    char* securePassword = generateSecurePassword();

    if (isSecurePassword(securePassword))
    {
        printPassword(securePassword);
    }
    else
    {
        printf("Password is not secure!\n");
    }

    free(securePassword);

    return 0;
}