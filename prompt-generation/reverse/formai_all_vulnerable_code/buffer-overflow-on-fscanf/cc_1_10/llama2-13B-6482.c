//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define USERNAME_MAX_LENGTH 20

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    int password_age;
} password_info;

// Function to generate a random password
void generate_password(char *password) {
    int i, j;
    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }
}

// Function to store password information
void store_password(password_info *password) {
    FILE *fp;
    fp = fopen("passwords.dat", "a");
    fprintf(fp, "%s:%s:%d\n", password->username, password->password, password->password_age);
    fclose(fp);
}

// Function to retrieve password information
password_info *retrieve_password(char *username) {
    FILE *fp;
    password_info password;
    fp = fopen("passwords.dat", "r");
    while (fscanf(fp, "%s:%s:%d", &password.username, &password.password, &password.password_age) == 3) {
        if (strcmp(username, password.username) == 0) {
            break;
        }
    }
    fclose(fp);
    return &password;
}

// Function to update password information
void update_password(password_info *password, int age) {
    password->password_age = age;
    store_password(password);
}

int main() {
    password_info *password;
    char username[USERNAME_MAX_LENGTH];
    char password_new[PASSWORD_MAX_LENGTH];

    // Prompt user for username and password
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter your password: ");
    fgets(password_new, sizeof(password_new), stdin);

    // Generate a random password if the user doesn't enter one
    if (password_new[0] == '\0') {
        generate_password(password_new);
    }

    // Store the password information
    password = retrieve_password(username);
    if (password == NULL) {
        printf("No password found for %s\n", username);
        return 1;
    }
    update_password(password, 30); // Update the password every 30 days

    // Print the password information
    printf("Password for %s: %s\n", password->username, password->password);

    return 0;
}