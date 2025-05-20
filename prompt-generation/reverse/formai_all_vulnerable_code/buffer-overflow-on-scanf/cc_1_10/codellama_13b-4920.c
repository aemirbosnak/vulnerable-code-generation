//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to store the password information
struct Password {
    char password[20];
    int length;
    int lowercase;
    int uppercase;
    int numbers;
    int symbols;
};

// Function to check the strength of the password
int check_password(struct Password *password) {
    int score = 0;
    if (password->length < 8) {
        return 0;
    }
    if (password->lowercase == 0) {
        score++;
    }
    if (password->uppercase == 0) {
        score++;
    }
    if (password->numbers == 0) {
        score++;
    }
    if (password->symbols == 0) {
        score++;
    }
    return score;
}

// Main function
int main() {
    // Get the password from the user
    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    // Create a new struct to store the password information
    struct Password pwd;
    strcpy(pwd.password, password);
    pwd.length = strlen(password);
    pwd.lowercase = 0;
    pwd.uppercase = 0;
    pwd.numbers = 0;
    pwd.symbols = 0;

    // Check the password for each character
    for (int i = 0; i < pwd.length; i++) {
        if (islower(password[i])) {
            pwd.lowercase++;
        } else if (isupper(password[i])) {
            pwd.uppercase++;
        } else if (isdigit(password[i])) {
            pwd.numbers++;
        } else {
            pwd.symbols++;
        }
    }

    // Check the strength of the password
    int score = check_password(&pwd);
    if (score == 0) {
        printf("The password is too weak!\n");
    } else if (score == 1) {
        printf("The password is weak!\n");
    } else if (score == 2) {
        printf("The password is average!\n");
    } else if (score == 3) {
        printf("The password is strong!\n");
    } else {
        printf("The password is very strong!\n");
    }

    return 0;
}