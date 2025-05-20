//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;

    // Get the password from the user
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);

    // Remove the newline character from the password
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    // Check the strength of the password
    int lowercase = 0, uppercase = 0, numbers = 0, symbols = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercase = 1;
            } else if (isupper(password[i])) {
                uppercase = 1;
            }
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else if (isalpha(password[i]) || isdigit(password[i]) || ispunct(password[i])) {
            symbols = 1;
        }
    }

    // Print the strength of the password
    if (lowercase && uppercase && numbers && symbols) {
        printf("Your password is very strong.\n");
    } else if ((lowercase || uppercase) && numbers && symbols) {
        printf("Your password is strong.\n");
    } else if ((lowercase || uppercase) && symbols) {
        printf("Your password is good.\n");
    } else if (lowercase || uppercase) {
        printf("Your password is weak.\n");
    } else if (numbers && symbols) {
        printf("Your password is very weak.\n");
    } else {
        printf("Your password is extremely weak.\n");
    }

    return 0;
}