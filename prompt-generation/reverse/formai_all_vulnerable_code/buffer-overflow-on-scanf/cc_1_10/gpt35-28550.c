//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

bool is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

bool is_special(char c)
{
    return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '}'));
}

char generate_random_char(bool lowercase, bool uppercase, bool digit, bool special)
{
    char c = '\0';
    bool valid_char = false;
    
    while (!valid_char)
    {
        int rand_num = rand() % 95 + 32; // ASCII codes from 32 to 126 are visible, printable characters
        c = (char) rand_num;
        
        if (lowercase && is_lowercase(c))
            valid_char = true;
        else if (uppercase && is_uppercase(c))
            valid_char = true;
        else if (digit && is_digit(c))
            valid_char = true;
        else if (special && is_special(c))
            valid_char = true;
    }
    
    return c;
}

int main()
{
    srand(time(NULL)); // seed random number generator with current time
    
    int password_length = 0;
    
    while (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Enter the desired password length (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
        
        if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
            printf("Invalid length. Please choose a password length between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    }
    
    bool lowercase = false;
    bool uppercase = false;
    bool digit = false;
    bool special = false;
    
    while (!lowercase && !uppercase && !digit && !special)
    {
        printf("Select the desired character types to include:\n");
        printf("Include lowercase letters? (y/n): ");
        char lc_response = getchar(); // consume newline character in buffer
        lc_response = getchar();
        lowercase = (lc_response == 'y');
        
        printf("Include uppercase letters? (y/n): ");
        char uc_response = getchar(); // consume newline character in buffer
        uc_response = getchar();
        uppercase = (uc_response == 'y');
        
        printf("Include digits? (y/n): ");
        char digit_response = getchar(); // consume newline character in buffer
        digit_response = getchar();
        digit = (digit_response == 'y');
        
        printf("Include special characters? (y/n): ");
        char special_response = getchar(); // consume newline character in buffer
        special_response = getchar();
        special = (special_response == 'y');
        
        if (!lowercase && !uppercase && !digit && !special)
            printf("Invalid input. Please select at least one character type to include.\n");
    }
    
    printf("Generating password...\n");
    
    char password[MAX_PASSWORD_LENGTH + 1]; // add 1 for terminating null character
    int i;
    for (i = 0; i < password_length; i++)
    {
        char c = generate_random_char(lowercase, uppercase, digit, special);
        password[i] = c;
    }
    password[password_length] = '\0'; // add terminating null character
    
    printf("The generated password is: %s\n", password);
    
    return 0;
}