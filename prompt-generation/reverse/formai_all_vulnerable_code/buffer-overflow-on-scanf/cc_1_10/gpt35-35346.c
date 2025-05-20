//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function declaration
int generateRandomInt(int min, int max);
char* generatePassword(int length);

int main() {
    int passwordLength;
  
    // user input for password length
    printf("Enter desired password length: ");
    scanf("%d", &passwordLength);
    
    // generate password
    char* password = generatePassword(passwordLength);
    printf("Generated Password: %s\n", password);
    
    // free password memory
    free(password);
    password = NULL;
    
    return 0;
}

// function definition to generate random integer between min and max values
int generateRandomInt(int min, int max) {
    // seed the random generator
    srand(time(NULL));
    
    // generate random integer between min and max values
    int randomInt = (rand() % (max - min + 1)) + min;
    
    return randomInt;
}

// function definition to generate password of given length
char* generatePassword(int length) {
    // declare arrays for character sets
    char* lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    char* uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* numericChars = "0123456789";
    char* specialChars = "!@#$%^&*()_+{}:\"<>?,./;'[]\\-=";
    
    // calculate the length of each character set
    int lowercaseLength = strlen(lowercaseChars);
    int uppercaseLength = strlen(uppercaseChars);
    int numericLength = strlen(numericChars);
    int specialLength = strlen(specialChars);
    
    // allocate memory for password as character array
    char* password = (char*) malloc(sizeof(char) * (length + 1));
    
    // generate password by selecting random characters from the different character sets
    for(int i = 0; i < length; i++) {
        // select random character set
        int randomSet = generateRandomInt(1, 4);
        
        // select random character from character set
        char randomChar;
        switch(randomSet) {
            case 1:
                randomChar = lowercaseChars[generateRandomInt(0, lowercaseLength - 1)];
                break;
            case 2:
                randomChar = uppercaseChars[generateRandomInt(0, uppercaseLength - 1)];
                break;
            case 3:
                randomChar = numericChars[generateRandomInt(0, numericLength - 1)];
                break;
            case 4:
                randomChar = specialChars[generateRandomInt(0, specialLength - 1)];
                break;
        }
        
        // add the selected character to the password
        password[i] = randomChar;
    }
    
    // add terminator character to the end of password
    password[length] = '\0';
    
    return password;
}