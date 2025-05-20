//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8
#define NUM_SPECIAL_CHARACTERS 5

const char SPECIAL_CHARACTERS[] = "!@#$%^&*()_+|=-<>?{}[]";

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = "";
    int passwordLength = 0, numSpecialCharacters = 0;
    int i, j, k;
    char specialChar;
    int randomNumber;

    srand(time(NULL));

    do {
        printf("Please enter the desired length of your password (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &passwordLength);
    } while (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH);

    numSpecialCharacters = passwordLength / 4;

    if (numSpecialCharacters < NUM_SPECIAL_CHARACTERS) {
        numSpecialCharacters = NUM_SPECIAL_CHARACTERS;
    }

    for (i = 0; i < numSpecialCharacters; i++) {
        j = rand() % (passwordLength - numSpecialCharacters) + 1;
        specialChar = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];

        for (k = passwordLength - 1; k > j; k--) {
            password[k] = password[k-1];
        }

        password[j] = specialChar;
    }

    for (i = 0; i < passwordLength; i++) {
        if (password[i] == '\0') {
            password[i] = (char) ((rand() % 26) + 'a');
        }
    }

    password[passwordLength] = '\0';

    printf("Your password is: %s\n", password);

    return 0;
}