//Code Llama-13B DATASET v1.0 Category: Password management ; Style: configurable
/*
 * Password management example program in a configurable style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a password entry
typedef struct {
    char *username;
    char *password;
} PasswordEntry;

// Function to prompt the user for a password
char *promptPassword() {
    char *password = malloc(sizeof(char) * 100);
    printf("Enter password: ");
    fgets(password, 100, stdin);
    return password;
}

// Function to store a password entry in a file
void storePassword(PasswordEntry *entry) {
    FILE *file = fopen("passwords.txt", "a");
    fprintf(file, "%s:%s\n", entry->username, entry->password);
    fclose(file);
}

// Function to retrieve a password entry from a file
PasswordEntry *retrievePassword(char *username) {
    FILE *file = fopen("passwords.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    while ((read = getline(&line, &len, file)) != -1) {
        char *delim = strchr(line, ':');
        if (delim) {
            *delim = '\0';
            entry->username = strdup(line);
            entry->password = strdup(delim + 1);
            break;
        }
    }
    free(line);
    fclose(file);
    return entry;
}

// Function to delete a password entry from a file
void deletePassword(char *username) {
    FILE *file = fopen("passwords.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        char *delim = strchr(line, ':');
        if (delim) {
            *delim = '\0';
            if (strcmp(line, username) == 0) {
                printf("Deleted password for %s\n", username);
                break;
            }
        }
    }
    free(line);
    fclose(file);
}

// Function to modify a password entry in a file
void modifyPassword(char *username, char *newPassword) {
    FILE *file = fopen("passwords.txt", "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        char *delim = strchr(line, ':');
        if (delim) {
            *delim = '\0';
            if (strcmp(line, username) == 0) {
                char *newLine = malloc(sizeof(char) * 100);
                sprintf(newLine, "%s:%s\n", username, newPassword);
                printf("Modified password for %s\n", username);
                fclose(file);
                file = fopen("passwords.txt", "w");
                fputs(newLine, file);
                free(newLine);
                break;
            }
        }
    }
    free(line);
    fclose(file);
}

int main() {
    char *username = "admin";
    char *password = promptPassword();
    PasswordEntry *entry = retrievePassword(username);
    if (entry) {
        if (strcmp(entry->password, password) == 0) {
            printf("Welcome, %s!\n", username);
        } else {
            printf("Incorrect password.\n");
        }
        free(entry);
    } else {
        printf("User %s not found.\n", username);
    }
    return 0;
}