//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
void generate_password(int length, char *password) {
    // Surprise! We have different character types!
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+[]{}|;:,.<>?~";

    // Let's gather all the characters in a big surprise bag!
    const char *all_characters = strcat(strcat(strcat(strcat(strdup(lowercase), uppercase), digits), special), "\0");

    // Essential: Seed the random number generator
    srand(time(NULL));

    // Surprise! Ensure at least one character from each category is included
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill the rest of the password with random characters from our big surprise bag
    for (int i = 4; i < length; i++) {
        password[i] = all_characters[rand() % (strlen(all_characters) - 1)];
    }

    // Shuffle the password to avoid any predictable patterns! 
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Null-terminate the password string
    password[length] = '\0';
}

// Main function where the magic begins!
int main() {
    printf("Welcome to the Ultimate Secure Password Generator! 🎉\n");
    
    // User defines password length
    int length;
    printf("Surprise! Choose a password length (at least 8 characters): ");
    scanf("%d", &length);

    // Ensuring the length is suitable for a secure password
    if (length < 8) {
        printf("Whoa! That's too short! Please choose at least 8 characters.\n");
        return 1;
    }

    // Prepare a place to store the password
    char *password = (char *)malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("Oh no! Memory allocation failed! 😱\n");
        return 1;
    }

    // Generate the password!
    generate_password(length, password);
    
    // Output the generated password
    printf("🎊 Here's your generated secure password: %s\n", password);

    // Free up memory to avoid memory leaks (also a nice surprise!)
    free(password);

    // Ending with excitement!
    printf("Thank you for using the Ultimate Secure Password Generator! Stay safe! 🔐\n");
    return 0;
}