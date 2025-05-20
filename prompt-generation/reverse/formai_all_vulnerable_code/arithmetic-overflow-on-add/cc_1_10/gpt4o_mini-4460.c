//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a secure password
void generate_password(char *password, int length) {
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";
    const char *special_chars = "!@#$%^&*()_+=-{}[]|:;\"'<>,.?/";

    // Combine all characters into one array
    const char *all_chars = strcat(strcat(strcat(strcat(strdup(lowercase), uppercase), digits), special_chars), "\0");
    
    // Seed the random number generator
    srand(time(NULL));

    // Ensure the password meets complexity
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special_chars[rand() % strlen(special_chars)];

    // Fill the rest of the password with random characters
    for (int i = 4; i < length; i++) {
        password[i] = all_chars[rand() % (strlen(lowercase) + strlen(uppercase) + strlen(digits) + strlen(special_chars))];
    }

    // Shuffle the password to avoid predictable patterns
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the string
    password[length] = '\0';
}

int main() {
    int length;
    
    // Input length from user
    printf("Enter the desired length of the password (minimum 8 characters): ");
    scanf("%d", &length);

    // Validate input length
    if (length < 8) {
        printf("Password length must be at least 8 characters.\n");
        return 1;
    }

    // Allocate memory for the password
    char *password = (char *)malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Generate the password
    generate_password(password, length);
    
    // Display the generated password
    printf("Generated Secure Password: %s\n", password);

    // Free allocated memory
    free(password);

    return 0;
}