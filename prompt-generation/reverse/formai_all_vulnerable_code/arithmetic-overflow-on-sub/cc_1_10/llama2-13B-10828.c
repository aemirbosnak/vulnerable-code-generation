//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024

// Structure to hold the user's date of birth and the encrypted text
typedef struct {
    int day, month, year;
    char encrypted_text[MAX_LENGTH];
} user_info_t;

// Function to get the user's date of birth
void get_user_birthdate(user_info_t *user_info) {
    printf("Enter your date of birth (dd/mm/yyyy): ");
    fgets(user_info->day, 3, stdin);
    fgets(user_info->month, 2, stdin);
    fgets(user_info->year, 4, stdin);
}

// Function to encrypt text using the Caesar cipher
void encrypt_text(user_info_t *user_info, char *text) {
    int shift = user_info->year - 1900;
    int i, j;

    // Calculate the number of shifted characters
    int num_shifted = strlen(text);

    // Shift the characters
    for (i = 0; i < num_shifted; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = (c + shift) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c + shift - 'A') % 26;
        }
        text[i] = c;
    }
}

int main() {
    user_info_t user_info;
    char text[MAX_LENGTH];

    // Get the user's date of birth
    get_user_birthdate(&user_info);

    // Ask the user for the text to encrypt
    printf("Enter the text to encrypt: ");
    fgets(text, MAX_LENGTH, stdin);

    // Encrypt the text
    encrypt_text(&user_info, text);

    // Print the encrypted text
    printf("Encrypted text: %s\n", text);

    return 0;
}