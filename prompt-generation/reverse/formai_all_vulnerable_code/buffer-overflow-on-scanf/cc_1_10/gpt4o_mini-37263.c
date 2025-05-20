//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define SPECIAL_CHARACTERS "!@#$%^&*()-=_+[]{}|;:',.<>?/`~"
#define ALPHABETS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define TOTAL_CHARACTERS (strlen(ALPHABETS) + strlen(NUMBERS) + strlen(SPECIAL_CHARACTERS))

void generate_password(char *password) {
    srand(time(NULL)); // Seed for randomness: may the odds be ever in your favor

    // Ensuring we have at least one of each character type
    password[0] = ALPHABETS[rand() % strlen(ALPHABETS)];
    password[1] = NUMBERS[rand() % strlen(NUMBERS)];
    password[2] = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];

    // Filling the rest with random characters
    for (int i = 3; i < PASSWORD_LENGTH; i++) {
        password[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[
            rand() % (strlen(ALPHABETS) + strlen(NUMBERS))
        ];
    }

    // Shuffling the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

void tell_a_joke() {
    printf("Why do programmers prefer dark mode?\n");
    printf("Because light attracts bugs!\n");
}

void display_password(char *password) {
    printf("Here is your (hopefully) secure password: \"%s\"\n", password);
    printf("If it gets hacked, don't blame me, I’m just a simplistic automaton!\n\n");
}

int main() {
    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
    int password_count;

    printf("Welcome to the Wacky Password Generator! 🤖\n");
    printf("We'll cook you a nice password in just a jiffy! 🥳\n");
    tell_a_joke();

    printf("\nHow many passwords do you want? (Please, more than zero...): ");
    while (scanf("%d", &password_count) != 1 || password_count <= 0) {
        printf("Oops! I can't compute that! Try again (more than zero please): ");
        while (getchar() != '\n'); // Clear buffer
    }

    printf("\nOkay, let's bake some delicious passwords!\n");
    
    for (int i = 0; i < password_count; i++) {
        generate_password(password);
        display_password(password);
    }

    printf("Remember to eat your veggies and change your passwords regularly!🥦🔑\n");
    printf("Goodbye, and may your secret codes be ever in your favor! 🎉\n");

    return 0;
}