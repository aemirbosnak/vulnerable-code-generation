//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character (letter, digit or special character)
char random_char() {
    int random_index;
    char ch;

    // Define character sets
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special_chars[] = "!@#$%^&*()_+-={}[];:\"|,.<>/?`~";

    // Determine which set to choose from based on random number
    if (random_number(0, 3) == 0) {
        random_index = random_number(0, strlen(lowercase) - 1);
        ch = lowercase[random_index];
    } else if (random_number(0, 3) == 1) {
        random_index = random_number(0, strlen(uppercase) - 1);
        ch = uppercase[random_index];
    } else if (random_number(0, 3) == 2) {
        random_index = random_number(0, strlen(digits) - 1);
        ch = digits[random_index];
    } else {
        random_index = random_number(0, strlen(special_chars) - 1);
        ch = special_chars[random_index];
    }

    return ch;
}

// Function to generate a random password
void generate_password(char* password, int length) {
    int i;

    srand(time(NULL)); // Seed random number generator with current time

    for (i = 0; i < length; i++) {
        password[i] = random_char();
    }

    password[length] = '\0'; // Add null terminator
}

int main() {
    int length;
    char password[21]; // Allocate space for password with length of 20 plus null terminator

    printf("Enter password length (between 8 and 20): ");
    scanf("%d", &length);

    if (length < 8 || length > 20) {
        printf("Invalid length, please enter a value between 8 and 20.\n");
        return 1;
    }

    generate_password(password, length);
    printf("Generated password: %s\n", password);

    return 0;
}