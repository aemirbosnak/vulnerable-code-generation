//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 12
#define MAX_LEN 20

const char *vowels = "aeiouAEIOU";
const char *consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ1234567890!@#$%^&*()_+-={}[]|\\:;\"<>,.?/";
const char *special_chars = "!@#$%^&*()_+-={}[]|\\:;\"<>,.?/";

int main() {
    int length, i, j;
    char password[MAX_LEN + 1];
    char vowel, consonant, special;

    srand(time(NULL));

    printf("Hello there! Let me generate a cheerful and secure password for you.\n");
    printf("Enter the desired length of your password (minimum 12, maximum 20 characters): ");
    scanf("%d", &length);

    if (length < MIN_LEN || length > MAX_LEN) {
        printf("Error: Password length must be between %d and %d characters.\n", MIN_LEN, MAX_LEN);
        return 1;
    }

    password[length] = '\0';

    // First, add some random vowels
    for (i = 0; i < length / 3; i++) {
        do {
            vowel = vowels[rand() % strlen(vowels)];
        } while (strchr(password, vowel) != NULL);

        password[length - i - 1] = vowel;
        length--;
    }

    // Then, add some random consonants
    for (i = 0; i < length / 2; i++) {
        do {
            consonant = consonants[rand() % strlen(consonants)];
        } while (strchr(password, consonant) != NULL);

        password[length - i - 1] = consonant;
        length--;
    }

    // Finally, add some random special characters
    for (i = 0; i < length / 6; i++) {
        do {
            special = special_chars[rand() % strlen(special_chars)];
        } while (strchr(password, special) != NULL);

        password[length - i - 1] = special;
        length--;
    }

    // Shuffle the password
    for (i = 0; i < length - 1; i++) {
        j = rand() % (length - i);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    printf("Here's your cheerful and secure password: %s\n", password);
    return 0;
}