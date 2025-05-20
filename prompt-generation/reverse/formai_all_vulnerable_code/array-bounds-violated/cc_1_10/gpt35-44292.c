//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, num, upper, lower, special;
    char password[100];
    int i, j;

    // Welcome message
    printf("Welcome to the Secure Password Generator! Let's generate a happy password!\n");

    // Get user input for password requirements
    printf("How long would you like your password to be? (Enter a number between 8 and 100): ");
    scanf("%d", &length);

    printf("How many numbers should your password contain? (Enter a number between 1 and %d): ", length);
    scanf("%d", &num);

    printf("How many uppercase letters should your password contain? (Enter a number between 1 and %d): ", length - num);
    scanf("%d", &upper);

    printf("How many lowercase letters should your password contain? (Enter a number between 1 and %d): ", length - num - upper);
    scanf("%d", &lower);

    printf("How many special characters should your password contain? (Enter a number between 1 and %d): ", length - num - upper - lower);
    scanf("%d", &special);

    // Check that requirements are valid
    if (num + upper + lower + special != length) {
        printf("Requirements do not match password length. Please try again.\n");
        return 1;
    }

    // Seed random number generator
    srand(time(0));

    // Generate password
    for (i = 0; i < num; i++) {
        password[i] = (rand() % 10) + '0';  // Add a random number to the password
    }
    for (j = 0; j < upper; j++) {
        password[num + j] = (rand() % 26) + 'A';  // Add a random uppercase letter to the password
    }
    for (j = 0; j < lower; j++) {
        password[num + upper + j] = (rand() % 26) + 'a';  // Add a random lowercase letter to the password
    }
    char specials[] = "!@#$%^&*()";  // An array of special characters
    for (j = 0; j < special; j++) {
        password[num + upper + lower + j] = specials[rand() % 10];  // Add a random special character to the password
    }
    password[length] = '\0';  // Null terminate the password string

    // Shuffle the password
    for (i = 0; i < length; i++) {
        j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Print the password
    printf("Your happy password is: %s\n", password);

    // Happy message
    printf("Congratulations on generating a happy password! Stay secure and stay happy!\n");

    return 0;
}