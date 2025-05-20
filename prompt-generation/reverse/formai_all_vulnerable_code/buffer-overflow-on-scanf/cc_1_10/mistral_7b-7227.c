//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 32
#define ALPHABET_SIZE 26
#define NUMERIC_SIZE 10
#define SPECIAL_CHARS_SIZE 12

#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-={[}]:;\"'<>,.?/~`|"

char *generate_password(int length) {
    char *password;
    char ch;
    int count, i, j, random_index;

    password = (char *)calloc(length + 1, sizeof(char));

    if (!password) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        count = 0;
        ch = rand() % 3;

        switch (ch) {
            case 0:
                // Generate a random character from the alphabet.
                random_index = rand() % ALPHABET_SIZE;
                ch = ALPHABET[random_index];
                break;
            case 1:
                // Generate a random number.
                random_index = rand() % NUMERIC_SIZE;
                ch = NUMERIC[random_index];
                break;
            case 2:
                // Generate a random special character.
                random_index = rand() % SPECIAL_CHARS_SIZE;
                ch = SPECIAL_CHARS[random_index];
                break;
            default:
                // If the switch statement fails, set the character to a random alphabet character.
                random_index = rand() % ALPHABET_SIZE;
                ch = ALPHABET[random_index];
                break;
        }

        // Add the character to the password.
        password[i] = ch;

        // Check for duplicate characters.
        for (j = 0; j < i; j++) {
            if (password[i] == password[j]) {
                // If a duplicate character is found, generate a new one and try again.
                i--;
                break;
            }
        }
    }

    password[length] = '\0';

    return password;
}

int main() {
    int length;
    char *password;

    printf("Enter the desired password length (min. %d, max. %d): ", MIN_LEN, MAX_LEN);
    scanf("%d", &length);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Invalid password length.\n");
        return 1;
    }

    password = generate_password(length);

    if (password) {
        printf("Generated password: %s\n", password);
        free(password);
    }

    return 0;
}