//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random integer between lower and upper bounds
int generateRandomNumber(int lower, int upper) {
    return rand() % (upper - lower + 1) + lower;
}

// Function to generate a random character
char generateRandomChar() {
    int charType = generateRandomNumber(1, 4); // 1 --> Uppercase, 2 --> Lowercase, 3 --> Number, 4 --> Special Character
    switch(charType) {
        case 1: // Uppercase Character
            return generateRandomNumber(65, 90);
        case 2: // Lowercase Character
            return generateRandomNumber(97, 122);
        case 3: // Number
            return generateRandomNumber(48, 57);
        case 4: // Special Character
            return generateRandomNumber(33, 47);
        default:
            return generateRandomNumber(65, 90);
    }
}

int main() {
    int passwordLength;
    printf("Enter the length of the password: ");
    scanf("%d", &passwordLength);

    char *password = (char *) malloc((passwordLength + 1) * sizeof(char)); // Allocate memory for password string
    srand(time(NULL)); // Seed the random number generator with current time

    int i;
    for(i = 0; i < passwordLength; i++) {
        password[i] = generateRandomChar();
    }
    password[passwordLength] = '\0'; // Terminate the password string with null character

    // Check if the password is secure
    int uppercaseCount = 0, lowercaseCount = 0, numberCount = 0, specialCount = 0;
    for(i = 0; i < passwordLength; i++) {
        if(password[i] >= 65 && password[i] <= 90) // Uppercase Character
            uppercaseCount++;
        else if(password[i] >= 97 && password[i] <= 122) // Lowercase Character
            lowercaseCount++;
        else if(password[i] >= 48 && password[i] <= 57) // Number
            numberCount++;
        else if((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) // Special Character
            specialCount++;
    }

    // If the password is not secure, add random characters to the password until it becomes secure
    while(uppercaseCount == 0 || lowercaseCount == 0 || numberCount == 0 || specialCount == 0) {
        int index = generateRandomNumber(0, passwordLength - 1);
        char newChar = generateRandomChar();
        if(newChar >= 65 && newChar <= 90) // Uppercase Character
            uppercaseCount++;
        else if(newChar >= 97 && newChar <= 122) // Lowercase Character
            lowercaseCount++;
        else if(newChar >= 48 && newChar <= 57) // Number
            numberCount++;
        else if((newChar >= 33 && newChar <= 47) || (newChar >= 58 && newChar <= 64) || (newChar >= 91 && newChar <= 96) || (newChar >= 123 && newChar <= 126)) // Special Character
            specialCount++;
        password[index] = newChar;
    }

    printf("Secure Password: %s", password);
    free(password); // Free the memory allocated for password
    return 0;
}