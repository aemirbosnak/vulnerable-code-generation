//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20
int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Prompt the user for the desired password length
    printf("Enter the desired password length (between 8 and 20 characters): ");
    int password_length;
    scanf("%d", &password_length);
    
    // Check if the password length is valid
    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Invalid password length. Please enter a value between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }
    
    // Generate a random string of characters
    char password[password_length];
    for (int i = 0; i < password_length; i++)
    {
        password[i] = 'a' + rand() % 26;
    }
    
    // Print the generated password
    printf("Your new password is: %s\n", password);
    
    // Get the user's confirmation
    printf("Is this the password you want? (y/n): ");
    char confirm[3];
    scanf(" %s", confirm);
    
    // Check if the user's confirmation is valid
    if (strcmp(confirm, "y") == 0)
    {
        printf("Great! Your new password is %s.\n", password);
    }
    else
    {
        printf("Sorry, I didn't understand that. Please try again.\n");
    }
    
    return 0;
}