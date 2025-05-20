//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 20

// Structure to store password information
typedef struct {
    char *username;
    char *password;
} password_info_t;

// Function to prompt user for input
void get_input(password_info_t *password) {
    printf("Enter your username: ");
    fgets(password->username, MAX_LENGTH, stdin);
    password->username[strcspn(password->username, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password->password, MAX_LENGTH, stdin);
    password->password[strcspn(password->password, "\n")] = 0;
}

// Function to store passwords in an array
void add_password(password_info_t passwords[], int *num_passwords, const char *username, const char *password) {
    int i;

    for (i = 0; i < *num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            // Password already exists, update the password
            strcpy(passwords[i].password, password);
            break;
        }
    }

    if (i == *num_passwords) {
        // Password does not exist, add it to the array
        passwords[*num_passwords].username = username;
        passwords[*num_passwords].password = password;
        (*num_passwords)++;
    }
}

// Function to print all stored passwords
void print_passwords(password_info_t passwords[], int num_passwords) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("%d. %s (%s)\n", i + 1, passwords[i].username, passwords[i].password);
    }
}

int main() {
    int num_passwords = 0;
    password_info_t passwords[MAX_PASSWORDS];

    // Prompt user for input
    get_input(&passwords[num_passwords]);

    // Add password to the array
    add_password(passwords, &num_passwords, passwords[num_passwords - 1].username, passwords[num_passwords - 1].password);

    // Print all stored passwords
    print_passwords(passwords, num_passwords);

    return 0;
}