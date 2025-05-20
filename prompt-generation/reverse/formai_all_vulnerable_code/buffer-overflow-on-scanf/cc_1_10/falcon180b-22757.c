//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter
bool is_letter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a string is a valid name
bool is_valid_name(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!is_letter(name[i])) {
            return false;
        }
    }
    return true;
}

// Function to sanitize a name
void sanitize_name(char *name) {
    int i;
    for (i = 0; i < strlen(name); i++) {
        if (!is_letter(name[i])) {
            name[i] = '\0';
        }
    }
}

// Function to check if a string is a valid email address
bool is_valid_email(char *email) {
    int i;
    for (i = 0; i < strlen(email); i++) {
        if (!isalnum(email[i]) && email[i]!= '@' && email[i]!= '.') {
            return false;
        }
    }
    return true;
}

// Function to sanitize an email address
void sanitize_email(char *email) {
    int i;
    for (i = 0; i < strlen(email); i++) {
        if (!isalnum(email[i]) && email[i]!= '@' && email[i]!= '.') {
            email[i] = '\0';
        }
    }
}

int main() {
    char name[100];
    char email[100];

    printf("Enter your name: ");
    scanf("%s", name);
    if (!is_valid_name(name)) {
        printf("Invalid name! Please enter a valid name.\n");
        return 1;
    }
    sanitize_name(name);
    printf("Your name is: %s\n", name);

    printf("Enter your email: ");
    scanf("%s", email);
    if (!is_valid_email(email)) {
        printf("Invalid email! Please enter a valid email.\n");
        return 1;
    }
    sanitize_email(email);
    printf("Your email is: %s\n", email);

    return 0;
}