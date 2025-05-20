//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 6
#define MAX_PASSWORD_LENGTH 20

void generatePassword(char *password, const int length);

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    /* Seed the random number generator */
    srand(time(NULL));

    printf("Welcome to the Password Generator\n\n");

    /* Prompt the user for the desired password length */
    do {
        printf("Enter the desired password length(%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);

        /* Clear the input buffer */
        while (getchar() != '\n')
            ;

        if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
            printf("Error: Password length must be between %d and %d. Try again.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        }
    } while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH);

    /* Generate the password */
    generatePassword(password, length);

    printf("\nGenerated password: %s\n", password);

    return 0;
}

void generatePassword(char *password, const int length) {
    int i, randomIndex;
    char c;
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()_+-={}[]\\|;:'\"<>,.?/~`";

    /* Assign the first character randomly */
    randomIndex = rand() % strlen(lowercase);
    password[0] = lowercase[randomIndex];

    /* Assign half the characters as lowercase */
    for (i = 1; i < length / 2; i++) {
        randomIndex = rand() % strlen(lowercase);
        password[i] = lowercase[randomIndex];
    }

    /* Assign the next quarter as uppercase */
    for (; i < 3 * length / 4; i++) {
        randomIndex = rand() % strlen(uppercase);
        password[i] = uppercase[randomIndex];
    }

    /* Assign the next eighth as digits */
    for (; i < 7 * length / 8; i++) {
        randomIndex = rand() % strlen(digits);
        password[i] = digits[randomIndex];
    }

    /* Assign the last eighth as a special character */
    for (; i < length; i++) {
        randomIndex = rand() % strlen(special);
        password[i] = special[randomIndex];
    }

    /* Shuffle the password characters */
    for (i = 0; i < length; i++) {
        randomIndex = rand() % length;
        c = password[i];
        password[i] = password[randomIndex];
        password[randomIndex] = c;
    }

    /* Add an end-of-string character */
    password[length] = '\0';
}