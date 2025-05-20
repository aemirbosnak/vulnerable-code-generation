//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 5
#define MAX_PASSWORD_LENGTH 20

/* Function Declarations */
void createPassword(char* password);
int isStrongPassword(char* password);
void encryptPassword(char* password);
void decryptPassword(char* password, char* key);
void displayPasswords(char* passwords[], int numPasswords);

/* Main Function */
int main()
{

    char* passwords[MAX_PASSWORDS];
    char key[MAX_PASSWORD_LENGTH];
    char choice;
    int numPasswords = 0;

    printf("Welcome to Password Manager!\n\n");

    do {
        printf("What would you like to do?\n\n");
        printf("1. Create New Password\n");
        printf("2. Display Passwords\n");
        printf("3. Quit\n\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);
        fflush(stdin);

        switch (choice) {
            

            case '1': // Create New Password
            {
                char password[MAX_PASSWORD_LENGTH];
                
                createPassword(password);
                
                if(isStrongPassword(password)) {
                    encryptPassword(password);
                    
                    passwords[numPasswords] = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
                    strcpy(passwords[numPasswords], password);
                    numPasswords++;
                    
                    printf("\nPassword Successfully Created and Encrypted.\n\n");
                } else {
                    printf("\nThe Password is not Strong Enough.\n\n");
                }
                
                break;
            }

            case '2': // Display Passwords
            {
                if(numPasswords == 0) {
                    printf("\nThere are no Passwords Stored.\n\n");
                } else {
                    printf("\nDisplaying Stored Passwords:\n\n");
                    displayPasswords(passwords, numPasswords);
                }
                
                break;
            }

            case '3': // Quit
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid Choice. Please Try Again.\n\n");
                break;
        }
        
    } while (choice != '3');
    
    // Free allocated memory
    for(int i=0; i<numPasswords; i++) {
        free(passwords[i]);
    }

    return 0;
}


/*
 * Generate a new Password
 */
void createPassword(char* password) {
    
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+,./<>?;':\"[]\\{}|`~";
    int numCharacters = strlen(characters);
    int passwordLength;
    
    // Generate Random Password Length between 8 and MAX_PASSWORD_LENGTH
    srand(time(NULL));
    passwordLength = rand() % (MAX_PASSWORD_LENGTH-8+1) + 8;
    
    // Generate Random Characters for Password
    for(int i=0; i<passwordLength; i++) {
        password[i] = characters[rand() % numCharacters];
    }
    
    password[passwordLength] = '\0';
}


/*
 * Check if Password is Strong
 */
int isStrongPassword(char* password) {
    
    int numUpperCase = 0, numLowerCase = 0, numNumbers = 0, numSpecialCharacters = 0;
    int passwordLength = strlen(password);
    
    // Check if Password Contains required Characters
    for(int i=0; i<passwordLength; i++) {
        
        if(password[i] >= 'A' && password[i] <= 'Z') {
            numUpperCase++;
        }
        
        if(password[i] >= 'a' && password[i] <= 'z') {
            numLowerCase++;
        }
        
        if(password[i] >= '0' && password[i] <= '9') {
            numNumbers++;
        }
        
        if((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
            numSpecialCharacters++;
        }
        
    }
    
    // Check if Password is Strong
    if(numUpperCase > 0 && numLowerCase > 0 && numNumbers > 0 && numSpecialCharacters > 0 && passwordLength >= 8) {
        return 1;
    } else {
        return 0;
    }
}


/*
 * Encrypt Password
 */
void encryptPassword(char* password) {
    
    char key[MAX_PASSWORD_LENGTH];
    int keyLength;
    
    // Generate Random Key Length between 8 and MAX_PASSWORD_LENGTH
    srand(time(NULL));
    keyLength = rand() % (MAX_PASSWORD_LENGTH-8+1) + 8;

    // Generate Random Characters for Key
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    int numCharacters = strlen(characters);

    for(int i=0; i<keyLength; i++) {
        key[i] = characters[rand() % numCharacters];
    }
    
    key[keyLength] = '\0';
    
    // Encrypt Password using Key
    for(int i=0; i<strlen(password); i++) {
        password[i] = password[i] ^ key[i % keyLength];
    }
    
    // Save Key at the End of Password
    strcat(password, key);
}


/*
 * Decrypt Password
 */
void decryptPassword(char* password, char* key) {
    
    int keyLength = strlen(key);
    
    // Decrypt Password using Key
    for(int i=0; i<strlen(password)-keyLength; i++) {
        password[i] = password[i] ^ key[i % keyLength];
    }
    
    // Remove Key from End of Password
    password[strlen(password)-keyLength] = '\0';
}


/*
 * Display Stored Passwords
 */
void displayPasswords(char* passwords[], int numPasswords) {
    
    char key[MAX_PASSWORD_LENGTH];
    
    for(int i=0; i<numPasswords; i++) {
        
        printf("Password %d: ", i+1);
        
        // Get Key from Password and Decrypt Password
        strcpy(key, passwords[i]+strlen(passwords[i])-MAX_PASSWORD_LENGTH);
        decryptPassword(passwords[i], key);
        
        // Display Decrypted Password
        printf("%s\n", passwords[i]);
    }
}