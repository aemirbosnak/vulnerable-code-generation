//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random uppercase letters
char generateUppercaseLetter() {
    return (char)(rand() % 26 + 65);
}

// Function to generate random lowercase letters
char generateLowercaseLetter() {
    return (char)(rand() % 26 + 97);
}

// Function to generate random digits
char generateDigit() {
    return (char)(rand() % 10 + 48);
}

// Function to generate random symbols
char generateSymbol() {
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*'};
    return symbols[rand() % 8];
}

// Function to generate a secure password
void generatePassword(char password[], int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int choice = rand() % 4;
        switch(choice) {
            case 0:
                password[i] = generateUppercaseLetter();
                break;
            case 1:
                password[i] = generateLowercaseLetter();
                break;
            case 2:
                password[i] = generateDigit();
                break;
            case 3:
                password[i] = generateSymbol();
                break;
        }
    }
    password[length] = '\0';
}

int main() {
    int passwordLength;
    printf("Enter the length of the password: ");
    scanf("%d", &passwordLength);

    char password[passwordLength + 1];
    generatePassword(password, passwordLength);

    printf("\nThe generated password is: %s\n", password);

    return 0;
}