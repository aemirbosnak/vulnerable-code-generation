//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Define a struct to store password information
struct password {
    char *username;
    char *password;
    int age;
};

// Define a function to read password information from a file
struct password read_passwords(const char *file_path) {
    struct password password;
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Error opening file");
        return password;
    }

    // Read username and password from file
    fscanf(file, "%s %s %d", password.username, password.password, &password.age);

    // Close file and return password information
    fclose(file);
    return password;
}

// Define a function to write password information to a file
void write_passwords(const char *file_path, struct password password) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write username, password, and age to file
    fprintf(file, "%s %s %d", password.username, password.password, password.age);

    // Close file
    fclose(file);
}

// Define a function to check if a password is valid
bool check_password(struct password password, char *password_input) {
    // Check if the input password matches the stored password
    if (strcmp(password_input, password.password) == 0) {
        // Password is valid, return true
        return true;
    }

    // Password is invalid, return false
    return false;
}

// Define a function to display the password information
void display_passwords(struct password password) {
    printf("Username: %s\nPassword: %s\nAge: %d\n", password.username, password.password, password.age);
}

int main() {
    // Read password information from a file
    struct password password = read_passwords("passwords.txt");

    // Check if the input password is valid
    if (check_password(password, "hello")) {
        // Password is valid, display the password information
        display_passwords(password);
    } else {
        // Password is invalid, display an error message
        printf("Invalid password, try again!\n");
    }

    // Write the password information to a file
    write_passwords("passwords.txt", password);

    return 0;
}