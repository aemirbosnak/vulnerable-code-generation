//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20 // maximum length of the password
#define MIN_LENGTH 8 // minimum length of the password
#define CHAR_TYPES 4 // character types to include in password

// character arrays for different types of characters
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+-=[]{}|;'\"<>,./?";

void generatePassword(char *password, int length) {
    int i, j, randIndex;
    char charset[MAX_LENGTH];

    // seed the random number generator
    srand(time(0));

    // initialize the charset array with all possible characters
    sprintf(charset, "%s%s%s%s", lowercase, uppercase, numbers, symbols);

    // randomly select characters from the charset array to create the password
    for (i = 0; i < length; i++) {
        randIndex = rand() % strlen(charset);
        password[i] = charset[randIndex];
    }
}

int main() {
    int length, i, j, k, charTypeCount;
    char password[MAX_LENGTH];
    int charTypes[CHAR_TYPES] = {0}; // array to keep track of number of characters from each type

    printf("Welcome to the Secure Password Generator!");
    printf("\nEnter the desired length of the password (%d - %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("\nInvalid password length. Please enter a value between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // randomly select character types to include in the password
    for (i = 0; i < CHAR_TYPES; i++) {
        charTypeCount = 0;
        do {
            j = rand() % CHAR_TYPES;
        } while (charTypes[j] || (i == j && i != CHAR_TYPES - 1)); // ensure each type is chosen at least once

        charTypes[j] = 1;

        // add characters from the selected type to the password
        switch (j) {
            case 0:
                generatePassword(password + charTypeCount, length / CHAR_TYPES + length % CHAR_TYPES);
                break;
            case 1:
                generatePassword(password + charTypeCount, length / CHAR_TYPES + length % CHAR_TYPES);
                break;
            case 2:
                generatePassword(password + charTypeCount, length / CHAR_TYPES);
                break;
            case 3:
                generatePassword(password + charTypeCount, length / CHAR_TYPES);
                break;
            default:
                break;
        }

        for (k = 0; k < length / CHAR_TYPES + (j < length % CHAR_TYPES); k++) {
            charTypeCount++;
        }
    }

    // shuffle the password using Fisher-Yates algorithm
    for (i = length - 1; i > 0; i--) {
        j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("\nYour secure password is: %s\n", password);

    return 0;
}