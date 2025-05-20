//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 12
#define NUM_SPECIAL_CHARS 10

// Romantic elements to spark the mood
const char *romantic_characters = "🌹💞💖💘🌺";
const char *password_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789"
                                  "!@#$%^&*()_-+=<>?/{}~|";

// Function to love the randomness of password generation
void love_randomization() {
    srand(time(NULL));
}

// Heartfelt function to generate a romantic password
void generate_romantic_password(char *password, int length) {
    int i;
    int special_index;
    
    // Let's sprinkle some romantic characters in the password
    for (i = 0; i < length; i++) {
        // Introduce some love into the password
        if (i % 5 == 0 && i != 0) {
            special_index = rand() % strlen(romantic_characters);
            password[i] = romantic_characters[special_index];
        } else {
            // Ensure characters are chosen from our delightful character set
            special_index = rand() % strlen(password_characters);
            password[i] = password_characters[special_index];
        }
    }
    password[length] = '\0'; // Null-terminate the string
}

// Function to seduce our romantic password lovers
void display_password(char *password) {
    printf("Your romantic password is: %s\n", password);
}

// Lovely function to ensure we have the right password length
int is_password_length_valid(int length) {
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Darling, please choose a length between %d and %d!\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }
    return 1;
}

// Heartwarming main function inviting users to create a romantic password
int main() {
    char password[MAX_PASSWORD_LENGTH + 1]; // Adding one for the null terminator
    int length;

    // Whispering sweet suggestions to the user
    printf("Welcome, beloved. Let's create a romantic password together.\n");

    // Let's give our beloved the choice of length
    printf("How many characters would you like your password to have? (Minimum: %d, Maximum: %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    if (scanf("%d", &length) != 1) {
        printf("The embrace of a valid number was not felt. Exiting...\n");
        return 1;
    }

    // Ensure the length is valid; if not, won't generate the password
    if (!is_password_length_valid(length)) {
        return 1;
    }

    // Initiate randomization to invite some serendipity
    love_randomization();
    // Generate the romantic password with a sprinkle of our heart
    generate_romantic_password(password, length);
    
    // Showcase the dazzling creation
    display_password(password);

    return 0;
}