//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define NUM_SPECIAL_CHARS 6

void generatePassword(int length, char* password);

int main()
{
    char password[MAX_PASSWORD_LENGTH+1]; // Initialize password character array
    int passwordLength; 
    
    // Get user input for password length
    printf("Enter desired password length (8-20 characters): ");
    scanf("%d", &passwordLength);
    
    // Check if password length is within acceptable range
    while (passwordLength > MAX_PASSWORD_LENGTH || passwordLength < MIN_PASSWORD_LENGTH) {
        printf("Invalid length\n");
        printf("Enter desired password length (8-20 characters): ");
        scanf("%d", &passwordLength);
    }
    
    generatePassword(passwordLength, password);
    
    // Output generated password
    printf("Your new password is: %s\n", password);
    
    return 0;
}

void generatePassword(int length, char* password)
{
    srand(time(NULL)); // Seed random number generator with current time
    char possibleChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=~`;:'\",./<>?[]{}|"; // Includes all possible characters
    
    int numSpecialChars = 0; // Counter for number of special characters in password so far
    
    // Generate first half of password using only letters and numbers
    for (int i=0; i<length/2; i++) {
        password[i] = possibleChars[rand() % (strlen(possibleChars)-NUM_SPECIAL_CHARS)]; // Randomly choose character from possible characters, ensuring no special characters
    }
    
    // Generate second half of password, adding special characters
    for (int i=length/2; i<length; i++) {
        password[i] = possibleChars[rand() % strlen(possibleChars)]; // Randomly choose character from possible characters
        
        // Add special character if not enough in password yet
        if (numSpecialChars < NUM_SPECIAL_CHARS && (password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || 
                                                     password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || 
                                                     password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+' || 
                                                     password[i]=='=' || password[i]=='~' || password[i]==';' || password[i]==':' || 
                                                     password[i]=='\'' || password[i]=='\"' || password[i]==',' || password[i]=='.' || 
                                                     password[i]=='/' || password[i]=='<' || password[i]=='>' || password[i]=='?' || 
                                                     password[i]=='[' || password[i]==']' || password[i]=='{' || password[i]=='}' || password[i]=='|')) {
            numSpecialChars++;
        }
        
        // Replace with a special character if too many in password already
        else if (numSpecialChars >= NUM_SPECIAL_CHARS) {
            password[i] = possibleChars[rand() % (strlen(possibleChars)-NUM_SPECIAL_CHARS)] + rand() % NUM_SPECIAL_CHARS; // Choose random letter/number and add special character
        }
    }
    
    password[length] = '\0'; // Terminate password string with null character
}