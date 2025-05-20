//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32
#define CHARACTER_SET_LENGTH 63
#define NUMERALS "0123456789"
#define UPPER_CASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER_CASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define SPECIAL_CHARACTERS "!@#$%^&*()_+{}:\"|;<>,.?/~`"

void generate_password(char *password, int length) {
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password length is too long.\n");
        exit(1);
    }

    char character_set[CHARACTER_SET_LENGTH];
    int i;

    // Initialize the character set
    for (i = 0; i < CHARACTER_SET_LENGTH; i++) {
        character_set[i] = '\0';
    }

    // Add numerals to the character set
    strncat(character_set, NUMERALS, strlen(NUMERALS));

    // Add upper and lower case letters to the character set
    strncat(character_set, UPPER_CASE_LETTERS, strlen(UPPER_CASE_LETTERS));
    strncat(character_set, LOWER_CASE_LETTERS, strlen(LOWER_CASE_LETTERS));

    // Add special characters to the character set
    strncat(character_set, SPECIAL_CHARACTERS, strlen(SPECIAL_CHARACTERS));

    // Generate the password
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        password[i] = character_set[rand() % CHARACTER_SET_LENGTH];
    }
    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH+1];
    int length;

    printf("Enter password length: ");
    scanf("%d", &length);

    generate_password(password, length);

    printf("Generated password: %s\n", password);

    return 0;
}