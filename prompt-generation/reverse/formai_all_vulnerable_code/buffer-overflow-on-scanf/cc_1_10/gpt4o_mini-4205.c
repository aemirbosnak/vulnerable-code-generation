//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

const char *adjectives[] = {
    "Radiant", "Whimsical", "Ethereal", "Enchanting", "Blissful",
    "Luminous", "Serendipitous", "Charming", "Celestial", "Graceful"
};

const char *nouns[] = {
    "Rose", "Star", "Dream", "Heart", "Moonlight",
    "Ocean", "Whisper", "Harmony", "Flame", "Journey"
};

const char *special_characters = "!@#$%^&*()_+-=[]{}|;:'\",.<>?/`~";
const char *numbers = "0123456789";

void str_shuffle(char *str) {
    int len = strlen(str);
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char *generate_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);
    
    if (!password) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Start building a password with a romantic touch
    strcpy(password, adjectives[rand() % (sizeof(adjectives) / sizeof(adjectives[0]))]);
    strcat(password, nouns[rand() % (sizeof(nouns) / sizeof(nouns[0]))]);
    
    // Add a special character and a number to fulfill password security requirements
    password[strlen(password)] = special_characters[rand() % strlen(special_characters)];
    password[strlen(password)] = numbers[rand() % strlen(numbers)];
    
    // If the password is less than the minimum length, we'd better throw in more characters
    while (strlen(password) < MIN_PASSWORD_LENGTH) {
        password[strlen(password)] = 'a' + (rand() % 26); // add a random lowercase letter
    }
    
    password[MAX_PASSWORD_LENGTH] = '\0'; // Null-terminate the string

    // Shuffle the password to ensure randomness
    str_shuffle(password);
    
    return password;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the Romantic Secure Password Generator!\n");
    printf("May this password keep your heart safe and sound.\n\n");

    int number_of_passwords;
    printf("How many romantic passwords would you like to generate? ");
    scanf("%d", &number_of_passwords);

    if (number_of_passwords <= 0) {
        printf("Ah, but a single password might keep the darkness at bay... Generating one...\n");
        number_of_passwords = 1;
    }

    for (int i = 0; i < number_of_passwords; i++) {
        char *password = generate_password();
        printf("Your romantic password %d is: %s\n", i + 1, password);
        free(password); // Free the allocated memory
    }

    printf("\nRemember, a good password is like a love letter: full of passion and impossible to guess.\n");

    return 0;
}