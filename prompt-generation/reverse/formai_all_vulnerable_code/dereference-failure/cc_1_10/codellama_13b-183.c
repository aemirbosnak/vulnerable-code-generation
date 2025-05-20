//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: calm
// SecurePasswordGenerator.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define CHAR_LOWERCASE 26
#define CHAR_UPPERCASE 26
#define CHAR_DIGITS 10
#define CHAR_SPECIAL 32

// Character arrays for generating password
char lowercase[CHAR_LOWERCASE] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[CHAR_UPPERCASE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[CHAR_DIGITS] = "0123456789";
char special[CHAR_SPECIAL] = "!@#$%^&*()_+-=[]{}|;:<>,.?/~`";

// Function to generate a random integer between min and max
int get_random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character from a character array
char get_random_char(char* array, int size) {
    return array[get_random_int(0, size - 1)];
}

// Function to generate a random password
char* generate_password() {
    char* password = malloc(PASSWORD_LENGTH + 1);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (i % 4 == 0) {
            password[i] = get_random_char(uppercase, CHAR_UPPERCASE);
        } else if (i % 4 == 1) {
            password[i] = get_random_char(lowercase, CHAR_LOWERCASE);
        } else if (i % 4 == 2) {
            password[i] = get_random_char(digits, CHAR_DIGITS);
        } else if (i % 4 == 3) {
            password[i] = get_random_char(special, CHAR_SPECIAL);
        }
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

int main() {
    srand(time(NULL));
    char* password = generate_password();
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}