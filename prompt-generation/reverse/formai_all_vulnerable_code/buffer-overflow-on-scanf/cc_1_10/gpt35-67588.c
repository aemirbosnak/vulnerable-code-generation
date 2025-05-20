//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_secure_password(int length);

int main()
{   
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of the password: ");
    
    // Read user input for password length
    int length;
    scanf("%d", &length);
    
    // Generate and print password
    char* password = generate_secure_password(length);
    printf("Generated password: %s\n", password);
    
    // Free memory used by password
    free(password);
    
    return 0;
}

char* generate_secure_password(int length)
{   
    // Define character sets to be used in password
    const char* lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
    const char* uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* numbers = "0123456789";
    const char* special_characters = "!@#$%^&*";
    
    // Calculate total size of character set
    int character_set_size = strlen(lowercase_letters) + strlen(uppercase_letters) + strlen(numbers) + strlen(special_characters);
    
    // Allocate memory for password string
    char* password = (char*) malloc((length + 1) * sizeof(char));
    
    // Seed random number generator with current time
    srand((unsigned int) time(NULL));
    
    // Generate random character from character set and add to password
    for (int i = 0; i < length; i++)
    {
        // Choose random character set
        int character_set_index = rand() % 4;
        const char* character_set;
        
        switch (character_set_index)
        {
            case 0:
                character_set = lowercase_letters;
                break;
            
            case 1:
                character_set = uppercase_letters;
                break;
                
            case 2:
                character_set = numbers;
                break;
                
            case 3:
                character_set = special_characters;
                break;
        }
        
        // Choose random character from selected character set
        int character_index = rand() % strlen(character_set);
        char random_character = character_set[character_index];
        
        // Add random character to password
        password[i] = random_character;
    }
    
    // Add null terminator to end of password string
    password[length] = '\0';
    
    return password;
}