//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main() {
    char password[PASSWORD_LENGTH + 1] = {0};
    printf("Welcome to the Secure Password Generator!\n");
    srand(time(NULL));

    // Define character sets
    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers_chars[] = "0123456789";
    char special_chars[] = "!@#$%^&*()_+{}[]|\\:;\"'<>,.?/~`";

    // Prompt user for password complexity
    int complexity = 0;
    printf("What level of password complexity would you like?\n");
    printf("1. Low (only lowercase letters)\n");
    printf("2. Medium (lowercase and uppercase letters)\n");
    printf("3. High (lowercase, uppercase, and numbers)\n");
    printf("4. Very High (lowercase, uppercase, numbers, and special characters)\n");
    scanf("%d", &complexity);

    // Generate password
    switch (complexity) {
        case 1:
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                password[i] = lowercase_chars[rand() % strlen(lowercase_chars)];
            }
            break;
        case 2:
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                password[i] = (rand() % 2 == 0)? lowercase_chars[rand() % strlen(lowercase_chars)] : uppercase_chars[rand() % strlen(uppercase_chars)];
            }
            break;
        case 3:
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                password[i] = (rand() % 3 == 0)? lowercase_chars[rand() % strlen(lowercase_chars)] : (rand() % 2 == 0)? uppercase_chars[rand() % strlen(uppercase_chars)] : numbers_chars[rand() % strlen(numbers_chars)];
            }
            break;
        case 4:
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                password[i] = special_chars[rand() % strlen(special_chars)];
            }
            break;
        default:
            printf("Invalid password complexity level.\n");
            return 1;
    }

    // Print password
    printf("Your secure password is: %s\n", password);

    return 0;
}