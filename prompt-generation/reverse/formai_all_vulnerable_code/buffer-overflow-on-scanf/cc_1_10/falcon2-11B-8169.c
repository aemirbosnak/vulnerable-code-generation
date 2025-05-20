//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Function to check the password strength
int checkPasswordStrength(char* password)
{
    int length = strlen(password);
    
    // Check length of the password
    if (length < 8)
        return 0;
    
    // Check if there are any lowercase letters
    if (strchr("abcdefghijklmnopqrstuvwxyz", password[0]) == NULL)
        return 0;
    
    // Check if there are any uppercase letters
    if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", password[0]) == NULL)
        return 0;
    
    // Check if there are any numbers
    if (strchr("0123456789", password[0]) == NULL)
        return 0;
    
    // Check if there are any special characters
    if (strchr("!@#$%^&*()_-+=`~{}[]|\\:;<>,.?/", password[0]) == NULL)
        return 0;
    
    // Check if there are any repeating characters
    for (int i = 1; i < length; i++) {
        if (password[i] == password[i - 1])
            return 0;
    }
    
    return 1;
}

int main()
{
    char password[100];
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    int strength = checkPasswordStrength(password);
    
    if (strength == 1)
        printf("Strong Password!\n");
    else
        printf("Weak Password!\n");
    
    return 0;
}