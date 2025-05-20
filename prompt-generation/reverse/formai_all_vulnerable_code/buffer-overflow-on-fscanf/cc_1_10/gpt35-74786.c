//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20
#define MAX_USERNAMES 10

/* Structure to hold username and password */
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Credential;

/* Global variable to hold all the credentials */
static Credential credentials[MAX_USERNAMES];

/* Constants to hold the number of credentials and number of attempts allowed */
static const int NUM_CREDENTIALS = 5;
static const int MAX_ATTEMPTS = 3;

/* Function prototypes */
int get_user_input(char *input, size_t length);
bool validate_credentials(char *username, char *password);
bool is_valid_password(char *password);
bool is_valid_username(char *username);
void *save_password(void *arg);

/* Main function */
int main(void) {
    pthread_t password_thread;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    bool authenticated = false;
    int attempts = 0;
    
    // Load credentials from file
    FILE *fp = fopen("passwords.txt", "r");
    if (!fp) {
        fprintf(stderr, "Error: failed to open passwords.txt\n");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < NUM_CREDENTIALS; i++) {
        fscanf(fp, "%s %s\n", credentials[i].username, credentials[i].password);
    }
    fclose(fp);
    
    printf("Welcome to Password Manager\n");
    
    // Loop until user is authenticated or max attempts is reached
    while (!authenticated && attempts < MAX_ATTEMPTS) {
        printf("Please enter your username: ");
        get_user_input(username, MAX_USERNAME_LENGTH);
        printf("Please enter your password: ");
        get_user_input(password, MAX_PASSWORD_LENGTH);
        authenticated = validate_credentials(username, password);
        attempts++;
        if (!authenticated) {
            printf("Invalid username or password\n");
        }
    }
    
    // Handle authentication success or failure
    if (authenticated) {
        printf("Authentication successful\n");
        char new_password[MAX_PASSWORD_LENGTH];
        bool valid_password = false;
        while (!valid_password) {
            printf("Please enter a new password: ");
            get_user_input(new_password, MAX_PASSWORD_LENGTH);
            valid_password = is_valid_password(new_password);
            if (!valid_password) {
                printf("Invalid password, please try again\n");
            } else {
                // Create a new thread to save the password
                pthread_create(&password_thread, NULL, save_password, new_password);
                printf("New password saved\n");
            }
        }
    } else {
        printf("Authentication failed, max attempts reached\n");
    }

    // Exit program
    exit(EXIT_SUCCESS);
}

/* Function to get user input */
int get_user_input(char *input, size_t length) {
    if (fgets(input, length, stdin) == NULL) {
        return 1;
    }
    input[strcspn(input, "\n")] = 0;
    return 0;
}

/* Function to validate credentials */
bool validate_credentials(char *username, char *password) {
    int i;
    for (i = 0; i < NUM_CREDENTIALS; i++) {
        if (strcmp(credentials[i].username, username) == 0 && strcmp(credentials[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

/* Function to check if password is valid */
bool is_valid_password(char *password) {
    int length = strlen(password);
    if (length < 8 || length > 20) {
        return false;
    }
    int i;
    bool has_digit = false;
    bool has_uppercase = false;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = true;
        } else if (isupper(password[i])) {
            has_uppercase = true;
        }
    }
    if (!has_digit || !has_uppercase) {
        return false;
    }
    return true;
}

/* Function to check if username is valid */
bool is_valid_username(char *username) {
    int length = strlen(username);
    if (length < 4 || length > 20) {
        return false;
    }
    int i;
    for (i = 0; i < length; i++) {
        if (!isalnum(username[i])) {
            return false;
        }
    }
    return true;
}

/* Function to save password */
void *save_password(void *arg) {
    char *new_password = (char *) arg;
    printf("Saving new password...\n");
    sleep(3);
    printf("New password saved: %s\n", new_password);
    pthread_exit(NULL);
}