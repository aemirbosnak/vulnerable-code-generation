//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

// function to generate a random password
char* generate_password(int length) {
    char* password = (char*) malloc(length + 1); // allocate memory for the password
    if (password == NULL) {
        printf("Error: Failed to allocate memory for password.\n");
        exit(1);
    }

    // initialize the password with random characters
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 94 + 33; // generate a random character between '!' and '~'
    }
    password[length] = '\0'; // null-terminate the password

    return password;
}

// function to print the password to the console
void print_password(char* password) {
    printf("Your new password is: %s\n", password);
}

// function to free the memory used by the password
void free_password(char* password) {
    free(password);
}

// function to get a password length from the user
int get_password_length() {
    int length = 0;
    while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Please enter the desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    }
    return length;
}

// main function
int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int length = get_password_length();
    char* password = generate_password(length);
    print_password(password);
    free_password(password);

    return 0;
}