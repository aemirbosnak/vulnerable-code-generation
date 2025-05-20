//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 12
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+"

void romantic_intro() {
    printf("As the stars twinkle above us, my dear, let us embark on a journey\n");
    printf("to create a secure password, one that embodies the bond we share.\n");
    printf("Together, we shall craft a guardian for your secrets, \n");
    printf("woven with the threads of love, complexity, and beauty.\n\n");
}

char generate_random_char() {
    return CHAR_SET[rand() % strlen(CHAR_SET)];
}

void generate_secure_password(char* password, int length) {
    for(int i = 0; i < length; i++) {
        password[i] = generate_random_char();
    }
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char password[MAX_PASSWORD_LENGTH + 1]; // To hold the password
    int length;

    romantic_intro(); // Start with a romantic introduction

    // Prompt the user for the desired password length
    printf("How long would you like your password to be (between %d and %d)? ", 
            MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    // Check the validity of the length
    while(length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Oh darling, that number seems unworthy! Please choose a length between %d and %d: ", 
                MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }

    // Generate the password
    generate_secure_password(password, length);

    // Output the romantic creation 
    printf("\nWith a whisper of love and a sprinkle of magic, your secure password is:\n");
    printf("%s\n", password);
    printf("May it guard your heart and secrets, forever entwined in the dance of safety.\n");

    // Sweet ending
    printf("\nRemember, my love, that a strong password is just one of the many\n");
    printf("ways to protect what matters most. Until we meet again, stay safe.\n");

    return 0;
}