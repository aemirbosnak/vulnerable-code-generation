//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{};:,.<>?/"
#define PASSWORD_MAX_LENGTH 128

void generate_password(char *password, int length) {
    const char *char_sets[] = {LOWERCASE, UPPERCASE, DIGITS, SPECIAL_CHARS};
    int char_set_count = sizeof(char_sets) / sizeof(char_sets[0]);
    
    // Ensure each category is represented in the password
    password[0] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[1] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[2] = DIGITS[rand() % strlen(DIGITS)];
    password[3] = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];
    
    // Fill the rest of the password with random choices from all sets
    for (int i = 4; i < length; ++i) {
        const char *selected_set = char_sets[rand() % char_set_count];
        password[i] = selected_set[rand() % strlen(selected_set)];
    }
    
    // Shuffle the password to avoid predictable patterns
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    password[length] = '\0';  // Null-terminate the string
}

int is_valid_length(int length) {
    return (length >= 8 && length <= PASSWORD_MAX_LENGTH);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    int length;
    char password[PASSWORD_MAX_LENGTH + 1];
    
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (8 to %d): ", PASSWORD_MAX_LENGTH);
    scanf("%d", &length);
    
    if (!is_valid_length(length)) {
        printf("Invalid length. Please choose a length between 8 and %d.\n", PASSWORD_MAX_LENGTH);
        return 1;
    }
    
    generate_password(password, length);
    
    printf("Your secure password is: %s\n", password);
    
    return 0;
}