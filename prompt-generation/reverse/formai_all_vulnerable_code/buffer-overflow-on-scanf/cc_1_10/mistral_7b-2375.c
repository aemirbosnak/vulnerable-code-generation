//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

// Function to generate random number
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate random character
char rand_char(int is_lower, int is_digit, int is_special) {
    if (is_lower) {
        return rand() % 26 + 'a';
    } else if (is_digit) {
        return rand() % 10 + '0';
    } else {
        char special_chars[] = { '!', '@', '#', '$', '%', '&', '*', '(', ')', '_', '+', '-', '=', '[', ']', '{', '}', '|', ':', ';', '<', '>', '?', '/' };
        return special_chars[rand_int(0, sizeof(special_chars) / sizeof(special_chars[0]))];
    }
    return 0;
}

// Function to generate secure password
void generate_password(char *password, int length) {
    int has_lower = 0, has_digit = 0, has_special = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate password character by character
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            // First character can be anything
            password[i] = rand_char(1, 0, 1);
        } else {
            // Other characters must satisfy certain conditions
            if (!has_lower && (rand() % 2)) {
                password[i] = rand_char(1, 0, 0);
                has_lower = 1;
            } else if (!has_digit && (rand() % 3)) {
                password[i] = rand_char(0, 1, 0);
                has_digit = 1;
            } else {
                password[i] = rand_char(0, 0, 1);
                has_special = 1;
            }
        }
    }

    // Null terminate the password
    password[length] = '\0';
}

int main() {
    int length;
    char password[MAX_LENGTH + 1];

    printf("Enter password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Exiting.\n");
        return 1;
    }

    generate_password(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}