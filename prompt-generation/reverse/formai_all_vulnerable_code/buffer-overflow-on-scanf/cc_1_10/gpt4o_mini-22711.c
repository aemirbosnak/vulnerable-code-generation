//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128
#define MIN_LENGTH 8

void generatePassword(char *password, int length);
void shuffleString(char *str, int length);
void printUsage();

int main() {
    int length;
    char password[MAX_LENGTH + 1];  // +1 for null terminator
    
    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to the Secure Password Generator!\n");
    printUsage();
    
    printf("Enter desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    
    // Validate length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password length should be between %d and %d. Exiting.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    generatePassword(password, length);
    
    printf("Generated Password: %s\n", password);
    
    return 0;
}

void generatePassword(char *password, int length) {
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+[]{};:,.<>?";
    
    // Ensure password contains at least one of each type
    password[0] = lower[rand() % strlen(lower)];
    password[1] = upper[rand() % strlen(upper)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill the rest of the password
    const char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{};:,.<>?";
    
    for (int i = 4; i < length; i++) {
        password[i] = allChars[rand() % strlen(allChars)];
    }
    
    // Shuffle the password to ensure randomness
    shuffleString(password, length);
    password[length] = '\0';  // Null terminate the string
}

void shuffleString(char *str, int length) {
    for (int i = 0; i < length - 1; i++) {
        int j = i + rand() % (length - i);  // Random index from i to length-1
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void printUsage() {
    printf("Usage:\n");
    printf("1. The password will be generated with a combination of:\n");
    printf("   - Lowercase letters (a-z)\n");
    printf("   - Uppercase letters (A-Z)\n");
    printf("   - Digits (0-9)\n");
    printf("   - Special characters (!@#$%^&*()-_=+[]{};:,.<>?)\n");
    printf("2. Minimum password length is %d and maximum is %d.\n\n", MIN_LENGTH, MAX_LENGTH);
}