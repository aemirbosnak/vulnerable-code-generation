//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, i, j, k;
    char password[100];
    char uppercase_letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_letters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    // Get password length from user
    printf("Enter password length (between 8 and 100): ");
    scanf("%d", &length);

    // Validate password length
    if (length < 8 || length > 100) {
        printf("Invalid password length.\n");
        return 1;
    }

    // Initialize password with empty string
    for (i = 0; i < length; i++) {
        password[i] = '\0';
    }

    // Add at least one character from each character set
    password[0] = uppercase_letters[rand() % strlen(uppercase_letters)];
    password[1] = lowercase_letters[rand() % strlen(lowercase_letters)];
    password[2] = numbers[rand() % strlen(numbers)];
    password[3] = symbols[rand() % strlen(symbols)];

    // Fill the rest of the password with random characters
    for (i = 4; i < length - 4; i++) {
        password[i] = (rand() % 10) + '0';
    }

    // Shuffle the password
    for (i = 0; i < length; i++) {
        j = rand() % length;
        k = password[i];
        password[i] = password[j];
        password[j] = k;
    }

    // Print the password
    printf("Your secure password is: %s\n", password);

    return 0;
}