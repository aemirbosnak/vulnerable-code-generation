//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUM_SPECIAL_CHARACTERS 10

const char *special_characters = "!@#$%^&*()-_=+[]{}|;:',.<>?/";
const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *lower_case = "abcdefghijklmnopqrstuvwxyz";
const char *numbers = "0123456789";

char generate_random_character(const char *characters) {
    return characters[rand() % strlen(characters)];
}

void generate_password(char *password, int length) {
    for (int i = 0; i < length; i++) {
        switch (rand() % 4) {
            case 0:
                password[i] = generate_random_character(upper_case);
                break;
            case 1:
                password[i] = generate_random_character(lower_case);
                break;
            case 2:
                password[i] = generate_random_character(numbers);
                break;
            case 3:
                password[i] = generate_random_character(special_characters);
                break;
        }
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL));
    
    int password_length;
    printf("Welcome to Secure Password Generator!\n");
    printf("Please enter the desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &password_length);
    
    if (password_length < MIN_LENGTH || password_length > MAX_LENGTH) {
        printf("Error: Length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return EXIT_FAILURE;
    }
    
    char password[MAX_LENGTH + 1];
    
    generate_password(password, password_length);
    
    printf("Your generated secure password is: %s\n", password);
    
    return EXIT_SUCCESS;
}