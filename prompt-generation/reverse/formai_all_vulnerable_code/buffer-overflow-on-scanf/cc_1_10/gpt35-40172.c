//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Function to generate a random uppercase letter
char random_uppercase()
{
    return 'A' + rand() % 26;
}

// Function to generate a random lowercase letter
char random_lowercase()
{
    return 'a' + rand() % 26;
}

// Function to generate a random digit
char random_digit()
{
    return '0' + rand() % 10;
}

// Function to generate a random special character
char random_special_char()
{
    char special_chars[] = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";
    return special_chars[rand() % sizeof(special_chars)];
}

// Function to generate a secure password
void generate_password(char *password, int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        int r = rand() % 4;
        switch (r)
        {
            case 0:
                password[i] = random_uppercase();
                break;
            case 1:
                password[i] = random_lowercase();
                break;
            case 2:
                password[i] = random_digit();
                break;
            case 3:
                password[i] = random_special_char();
                break;
        }
    }
    password[length] = '\0';
}

int main()
{
    char password[20];
    int length;
    srand(time(NULL));
    
    printf("Enter the length of your password (minimum 8, maximum 20): ");
    scanf("%d", &length);
    if (length < 8 || length > 20)
    {
        printf("Invalid password length!\n");
        exit(1);
    }
    
    generate_password(password, length);
    printf("Your secure password is: %s\n", password);
    
    return 0;
}