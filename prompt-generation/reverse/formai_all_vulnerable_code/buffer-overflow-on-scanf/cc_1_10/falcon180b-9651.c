//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 16

int main() {
    char password[PASSWORD_LENGTH + 1];
    int i, j, k;
    int uppercase = 1;
    int lowercase = 1;
    int numbers = 1;
    int special_chars = 1;

    // Get user preferences
    printf("Enter 1 to include uppercase letters, 0 otherwise: ");
    scanf("%d", &uppercase);
    printf("Enter 1 to include lowercase letters, 0 otherwise: ");
    scanf("%d", &lowercase);
    printf("Enter 1 to include numbers, 0 otherwise: ");
    scanf("%d", &numbers);
    printf("Enter 1 to include special characters, 0 otherwise: ");
    scanf("%d", &special_chars);

    // Initialize character sets
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers_chars[] = "0123456789";
    char special_chars_chars[] = "!@#$%^&*()_-+=[{]}\\|;:'\",<.>/?`~";

    // Combine character sets based on user preferences
    char charset[256] = { 0 };
    for (i = 0; i < strlen(uppercase_chars); i++) {
        charset[uppercase_chars[i]] = 1;
    }
    for (i = 0; i < strlen(lowercase_chars); i++) {
        charset[lowercase_chars[i]] = 1;
    }
    for (i = 0; i < strlen(numbers_chars); i++) {
        charset[numbers_chars[i]] = 1;
    }
    for (i = 0; i < strlen(special_chars_chars); i++) {
        charset[special_chars_chars[i]] = 1;
    }

    // Generate password
    srand(time(NULL));
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        do {
            k = rand() % 256;
        } while (charset[k] == 0);
        password[i] = k;
    }
    password[PASSWORD_LENGTH] = '\0';

    // Display password
    printf("Your secure password is: %s\n", password);

    return 0;
}