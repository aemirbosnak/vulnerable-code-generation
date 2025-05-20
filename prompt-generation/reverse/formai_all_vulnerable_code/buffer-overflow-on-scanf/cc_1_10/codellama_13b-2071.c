//Code Llama-13B DATASET v1.0 Category: Password management ; Style: synchronous
/*
 * C Password Management Example Program
 *
 * This program demonstrates how to create and manage passwords using the C programming language.
 * It uses a synchronous style of programming, where the program is executed sequentially from top to bottom.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 16

// Function to create a new password
void create_password(char *password, int length) {
    // Generate a random password
    for (int i = 0; i < length; i++) {
        password[i] = 'A' + (rand() % 26);
    }
}

// Function to check if a password is valid
int check_password(char *password, int length) {
    // Check if the password is the correct length
    if (length != MAX_PASSWORD_LENGTH) {
        return 0;
    }

    // Check if the password contains only letters and digits
    for (int i = 0; i < length; i++) {
        if (!isalpha(password[i]) && !isdigit(password[i])) {
            return 0;
        }
    }

    // Check if the password contains at least one letter and one digit
    int contains_letter = 0;
    int contains_digit = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            contains_letter = 1;
        } else if (isdigit(password[i])) {
            contains_digit = 1;
        }
    }
    if (!contains_letter || !contains_digit) {
        return 0;
    }

    // Check if the password contains no duplicates
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (password[i] == password[j]) {
                return 0;
            }
        }
    }

    // If all checks pass, return 1
    return 1;
}

// Function to change a password
void change_password(char *old_password, char *new_password) {
    // Check if the old password is valid
    if (!check_password(old_password, MAX_PASSWORD_LENGTH)) {
        printf("Invalid old password\n");
        return;
    }

    // Check if the new password is valid
    if (!check_password(new_password, MAX_PASSWORD_LENGTH)) {
        printf("Invalid new password\n");
        return;
    }

    // Change the password
    strcpy(old_password, new_password);
    printf("Password changed successfully\n");
}

int main() {
    // Create a new password
    char password[MAX_PASSWORD_LENGTH + 1];
    create_password(password, MAX_PASSWORD_LENGTH);
    printf("New password: %s\n", password);

    // Change the password
    char old_password[MAX_PASSWORD_LENGTH + 1];
    char new_password[MAX_PASSWORD_LENGTH + 1];
    strcpy(old_password, password);
    printf("Enter new password: ");
    scanf("%s", new_password);
    change_password(old_password, new_password);

    return 0;
}