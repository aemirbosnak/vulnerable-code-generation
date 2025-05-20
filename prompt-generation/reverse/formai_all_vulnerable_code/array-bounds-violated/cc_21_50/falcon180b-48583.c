//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    double complexity;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove the newline character from the input
    length = strlen(password);
    if (password[length-1] == '\n') {
        password[length-1] = '\0';
        length--;
    }

    // Calculate the complexity of the password
    complexity = 0.0;
    if (length >= 8) {
        complexity += 1.0;
    }
    if (isalpha(password[0])) {
        complexity += 1.0;
    }
    if (isdigit(password[0])) {
        complexity += 1.0;
    }
    if (isalpha(password[length-1])) {
        complexity += 1.0;
    }
    if (isdigit(password[length-1])) {
        complexity += 1.0;
    }
    if (islower(password[0]) && isupper(password[0])) {
        complexity += 1.0;
    }
    if (islower(password[length-1]) && isupper(password[length-1])) {
        complexity += 1.0;
    }
    if (islower(password[0]) && isdigit(password[0])) {
        complexity += 1.0;
    }
    if (islower(password[length-1]) && isdigit(password[length-1])) {
        complexity += 1.0;
    }
    if (isupper(password[0]) && isdigit(password[0])) {
        complexity += 1.0;
    }
    if (isupper(password[length-1]) && isdigit(password[length-1])) {
        complexity += 1.0;
    }
    if (islower(password[0]) && isupper(password[length-1])) {
        complexity += 1.0;
    }
    if (isupper(password[0]) && islower(password[length-1])) {
        complexity += 1.0;
    }

    // Print the result
    printf("Password strength: %.0f%%\n", (complexity / 10.0) * 100.0);

    return 0;
}