//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

bool hasUpperCase;
bool hasLowerCase;
bool hasDigit;
bool hasSymbol;

char getRandomUpperCase() {
    return rand() % 26 + 'A';
}

char getRandomLowerCase() {
    return rand() % 26 + 'a';
}

char getRandomDigit() {
    return rand() % 10 + '0';
}

char getRandomSymbol() {
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+'};
    return symbols[rand() % 12];
}

bool isValidPassword(char *password) {
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpperCase = true;
        else if (islower(password[i]))
            hasLowerCase = true;
        else if (isdigit(password[i]))
            hasDigit = true;
        else
            hasSymbol = true;
    }

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH || !hasUpperCase || !hasLowerCase || !hasDigit || !hasSymbol)
        return false;
    else
        return true;
}

char* generatePassword() {
    char *password;
    do {
        int randomLength = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
        password = calloc(randomLength, sizeof(char));

        for (int i = 0; i < randomLength; i++) {
            int randomCharType = rand() % 4;
            switch(randomCharType) {
                case 0:
                    password[i] = getRandomUpperCase();
                    break;
                case 1:
                    password[i] = getRandomLowerCase();
                    break;
                case 2:
                    password[i] = getRandomDigit();
                    break;
                case 3:
                    password[i] = getRandomSymbol();
                    break;
            }
        }
    } while(!isValidPassword(password));

    return password;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n\n");

    printf("How many passwords would you like to generate? ");
    int numPasswords;
    scanf("%d", &numPasswords);

    printf("Generating passwords...\n\n");

    for (int i = 0; i < numPasswords; i++) {
        char *password = generatePassword();
        printf("Password %d: %s\n", i + 1, password);
        free(password);
        hasUpperCase = hasLowerCase = hasDigit = hasSymbol = false;
    }

    printf("\nThank you for using the Secure Password Generator!\n");

    return 0;
}