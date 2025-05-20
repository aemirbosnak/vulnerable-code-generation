//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_USERNAME_SIZE 50
#define MAX_PASSWORD_SIZE 50

int main() {
    char input[MAX_INPUT_SIZE], username[MAX_USERNAME_SIZE], password[MAX_PASSWORD_SIZE];
    int i, j, input_len, is_valid_username = 1, is_valid_password = 1;

    // Prompt the user for input
    printf("Enter your username and password:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input_len = strlen(input);

    // Remove the newline character from the end of the input
    if (input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';
        input_len--;
    }

    // Check the length of the input
    if (input_len >= MAX_INPUT_SIZE) {
        printf("Error: input too long\n");
        exit(1);
    }

    // Split the input into username and password
    for (i = 0; i < input_len; i++) {
        if (isspace(input[i])) {
            strncpy(username, input, i);
            username[i] = '\0';
            break;
        }
    }
    if (i == input_len - 1) {
        printf("Error: no password entered\n");
        exit(1);
    }
    strncpy(password, input + i + 1, input_len - i - 1);
    password[input_len - i - 1] = '\0';

    // Check the validity of the username
    for (i = 0; i < strlen(username); i++) {
        if (!isalnum(username[i])) {
            is_valid_username = 0;
            break;
        }
    }
    if (strlen(username) > MAX_USERNAME_SIZE || !is_valid_username) {
        printf("Error: invalid username\n");
        exit(1);
    }

    // Check the validity of the password
    if (strlen(password) > MAX_PASSWORD_SIZE) {
        printf("Error: password too long\n");
        exit(1);
    }
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            is_valid_password = 0;
            break;
        }
    }
    if (!is_valid_password) {
        printf("Error: invalid password\n");
        exit(1);
    }

    // Print the sanitized input
    printf("Username: %s\n", username);
    printf("Password: %s\n", password);

    return 0;
}