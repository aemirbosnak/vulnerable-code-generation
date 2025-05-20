//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Declare Function Prototype
void generatePassword(char*, int);

// Main function
int main(){
    int length;
    char password[25];  // set maximum length of password to 25
    char choice;

    do
    {
        // Ask user for preferred password length
        printf("Enter the length of password (minimum length 8): ");
        scanf("%d", &length);

        // Check if entered length is valid
        if (length < 8)
        {
            printf("Password length must be at least 8 characters long\n");
            continue;
        }

        // Call function to generate secure password
        generatePassword(password, length);

        // Display generated password
        printf("\nGenerated Password: %s\n", password);

        // Ask if user wants to generate another password
        printf("\nDo you want to generate another password? (y/n): ");
        scanf(" %c", &choice);

    } while (tolower(choice) == 'y');

    return 0;
}

// Function to generate secure password
void generatePassword(char *password, int length){
    srand(time(0)); // Seed for random number generator
    int i, j, randomNum;
    char randChar;

    // Create string of lowercase letters
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";

    // Create string of uppercase letters
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Create string of numbers
    char numbers[] = "1234567890";

    // Create string of special characters
    char specialchars[] = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";

    // Initialize variables
    int numLowercase = length/3;
    int numUppercase = length/3;
    int numNumbers = length/3;
    int numSpecialChars = length - numLowercase - numUppercase - numNumbers;

    // Create temporary password
    char tempPassword[length+1]; // set the length of password to make room for '\0'
    tempPassword[length] = '\0';

    // Add lowercase letters
    for(i=0; i<numLowercase; i++){
        randomNum = rand() % strlen(lowercase);
        randChar = lowercase[randomNum];
        tempPassword[i] = randChar;
    }

    // Add uppercase letters
    for(j=i; j<(i+numUppercase); j++){
        randomNum = rand() % strlen(uppercase);
        randChar = uppercase[randomNum];
        tempPassword[j] = randChar;
    }

    // Add numbers
    for(i=j; i<(j+numNumbers); i++){
        randomNum = rand() % strlen(numbers);
        randChar = numbers[randomNum];
        tempPassword[i] = randChar;
    }

    // Add special characters
    for(j=i; j<(i+numSpecialChars); j++){
        randomNum = rand() % strlen(specialchars);
        randChar = specialchars[randomNum];
        tempPassword[j] = randChar;
    }

    // Shuffle the password
    for(i=0;i<length;i++){
        randomNum = rand()%length;
        randChar = tempPassword[i];
        tempPassword[i] = tempPassword[randomNum];
        tempPassword[randomNum] = randChar;
    }

    // Copy the generated password to the password variable in main
    strcpy(password, tempPassword);
}