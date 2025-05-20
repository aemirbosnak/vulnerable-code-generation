//FormAI DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants for program
#define PASSWORD_LENGTH 12
#define MAXIMUM_ATTEMPTS 3
#define USERS_DB "users.txt"

// Define structure for user data
typedef struct {
    char username[20];
    char password[PASSWORD_LENGTH + 1];
} User;

// Function to read a line of text from user (with buffer overflow check)
char *read_line(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0; // remove newline character
    if (strlen(str) == size - 1) { // check for buffer overflow
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    return str;
}

// Function to check if a password meets complexity requirements
int is_valid_password(char *password) {
    int length = strlen(password);
    if (length != PASSWORD_LENGTH) {
        return 0;
    }
    int uppercase = 0, lowercase = 0, digits = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
        } else if (isupper(password[i])) {
            uppercase = 1;
        } else if (isdigit(password[i])) {
            digits = 1;
        } else {
            return 0; // invalid characters
        }
    }
    return uppercase && lowercase && digits;
}

// Function to read user data from file
void read_users(User **users, int *n_users) {
    FILE *file = fopen(USERS_DB, "r");
    if (file == NULL) {
        *n_users = 0;
        return;
    }
    fscanf(file, "%d", n_users); // read number of users
    *users = calloc(*n_users, sizeof(User)); // allocate memory for users
    for (int i = 0; i < *n_users; i++) {
        fscanf(file, "%s %s", (*users)[i].username, (*users)[i].password);
    }
    fclose(file);
}

// Function to write user data to file
void write_users(User *users, int n_users) {
    FILE *file = fopen(USERS_DB, "w");
    fprintf(file, "%d\n", n_users); // write number of users
    for (int i = 0; i < n_users; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(file);
}

// Function to add a new user
void add_user(User **users, int *n_users) {
    printf("Enter new username: ");
    char username[20];
    read_line(username, 20);
    for (int i = 0; i < *n_users; i++) {
        if (strcmp(username, (*users)[i].username) == 0) {
            printf("Error: username already exists\n");
            return;
        }
    }
    printf("Enter new password: ");
    char password[PASSWORD_LENGTH + 1];
    read_line(password, PASSWORD_LENGTH + 1);
    if (!is_valid_password(password)) {
        printf("Error: invalid password format\n");
        return;
    }
    *n_users += 1;
    *users = realloc(*users, *n_users * sizeof(User));
    strcpy((*users)[*n_users - 1].username, username);
    strcpy((*users)[*n_users - 1].password, password);
    write_users(*users, *n_users);
    printf("User added successfully\n");
}

// Function to check user login credentials
int check_login(User *users, int n_users, char *username, char *password) {
    for (int i = 0; i < n_users; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to prompt user for login
int login(User *users, int n_users) {
    int attempts = 0;
    while (attempts < MAXIMUM_ATTEMPTS) {
        printf("Enter username: ");
        char username[20];
        read_line(username, 20);
        printf("Enter password: ");
        char password[PASSWORD_LENGTH + 1];
        read_line(password, PASSWORD_LENGTH + 1);
        if (check_login(users, n_users, username, password)) {
            printf("Login successful\n");
            return 1;
        } else {
            printf("Error: invalid username or password\n");
            attempts += 1;
        }
    }
    printf("Maximum login attempts reached\n");
    return 0;
}

// Main function
int main() {
    // Read user data from file
    User *users;
    int n_users;
    read_users(&users, &n_users);
    
    // Prompt user for action
    char action[20];
    while (1) {
        printf("\nChoose action: (l)ogin, (a)dd user, (q)uit\n");
        read_line(action, 20);
        if (strcmp(action, "l") == 0) {
            login(users, n_users);
        } else if (strcmp(action, "a") == 0) {
            add_user(&users, &n_users);
        } else if (strcmp(action, "q") == 0) {
            break;
        } else {
            printf("Error: invalid action\n");
        }
    }
    
    // Free memory and exit
    free(users);
    return 0;
}