//Code Llama-13B DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LEN 128

// Define the number of attempts allowed for the password
#define MAX_ATTEMPTS 3

// Structure to store a password entry
typedef struct {
    char password[MAX_PASSWORD_LEN];
    char username[MAX_PASSWORD_LEN];
} password_entry_t;

// Function to prompt the user for a password
void prompt_for_password(password_entry_t *entry) {
    printf("Enter your username: ");
    scanf("%s", entry->username);
    printf("Enter your password: ");
    scanf("%s", entry->password);
}

// Function to validate the password
int validate_password(password_entry_t *entry) {
    if (strlen(entry->password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    if (!isalpha(entry->password[0])) {
        printf("Password must start with a letter.\n");
        return 0;
    }
    if (!isdigit(entry->password[1])) {
        printf("Password must have at least one digit.\n");
        return 0;
    }
    if (!isalpha(entry->password[2])) {
        printf("Password must have at least one letter.\n");
        return 0;
    }
    return 1;
}

// Function to store the password
void store_password(password_entry_t *entry) {
    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "%s %s\n", entry->username, entry->password);
    fclose(fp);
}

// Function to load the password
void load_password(password_entry_t *entry) {
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fscanf(fp, "%s %s\n", entry->username, entry->password);
    fclose(fp);
}

// Main function
int main() {
    password_entry_t entry;
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        prompt_for_password(&entry);
        if (validate_password(&entry)) {
            store_password(&entry);
            break;
        }
        attempts++;
    }
    if (attempts == MAX_ATTEMPTS) {
        printf("Maximum number of attempts reached.\n");
        return 1;
    }
    load_password(&entry);
    printf("Your username is: %s\n", entry.username);
    printf("Your password is: %s\n", entry.password);
    return 0;
}