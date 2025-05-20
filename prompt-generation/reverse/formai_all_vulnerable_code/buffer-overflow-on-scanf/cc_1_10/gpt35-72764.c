//FormAI DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 50
#define MAX_SALT_LENGTH 16
#define MAX_PASSWORD_LENGTH 32
#define MAX_USERNAME_LENGTH 20
#define MAX_WRONG_ATTEMPTS 3

typedef struct {
    char salt[MAX_SALT_LENGTH];
    char hash[MAX_PASSWORD_LENGTH];
} Password;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    Password password;
} User;

User users[MAX_PASSWORDS];
int num_users = 0;

void generate_salt(char *salt) {
    const char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./";
    int num_chars = strlen(characters);
    srand(time(NULL));
    
    for (int i = 0; i < MAX_SALT_LENGTH - 1; i++) {
        salt[i] = characters[rand() % num_chars];
    }
    salt[MAX_SALT_LENGTH - 1] = '\0';
}


void generate_hash(const char *password, const char *salt, char *hash) {
    char input[MAX_PASSWORD_LENGTH + MAX_SALT_LENGTH];
    strcpy(input, password);
    strcat(input, salt);
    unsigned char output[32];
    SHA256(input, strlen(input), output);
    for (int i = 0; i < 32; i++) {
        sprintf(&hash[i*2], "%02x", output[i]);
    }
}


int authenticate(const char *username, const char* password) {
    User *user = NULL;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user = &users[i];
            break;
        }
    }
    if (user == NULL) {
        return 0;
    }
    
    char hash[MAX_PASSWORD_LENGTH];
    generate_hash(password, user->password.salt, hash);
    if (strcmp(hash, user->password.hash) == 0) {
        return 1;
    } else {
        return 0;
    }
}


int check_username_validity(const char *username) {
    if (strlen(username) > MAX_USERNAME_LENGTH) {
        return 0;
    }
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 0;
        }
    }
    return 1;
}


void add_user() {
    if (num_users == MAX_PASSWORDS) {
        printf("Cannot add more users. Password database is full.\n");
        return;
    }
    char username[MAX_USERNAME_LENGTH];
    printf("Enter a new username (maximum %d characters):\n", MAX_USERNAME_LENGTH);
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';
    if (!check_username_validity(username)) {
        printf("Invalid username. Username already exists or is too long.\n");
        return;
    }
    
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password (maximum %d characters):\n", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';
    
    char salt[MAX_SALT_LENGTH];
    generate_salt(salt);
    char hash[MAX_PASSWORD_LENGTH];
    generate_hash(password, salt, hash);
    
    User user;
    strcpy(user.username, username);
    strcpy(user.password.salt, salt);
    strcpy(user.password.hash, hash);
    users[num_users] = user;
    num_users++;
    
    printf("User successfully added.\n");
}


void change_password(const char *username) {
    User *user = NULL;
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            user = &users[i];
            break;
        }
    }
    if (user == NULL) {
        printf("Invalid username. User not found.\n");
        return;
    }
    
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a new password (maximum %d characters):\n", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';
    
    char salt[MAX_SALT_LENGTH];
    generate_salt(salt);
    char hash[MAX_PASSWORD_LENGTH];
    generate_hash(password, salt, hash);
    
    strcpy(user->password.salt, salt);
    strcpy(user->password.hash, hash);
    
    printf("Password successfully changed.\n");
}


int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int wrong_attempts = 0;
    
    while (1) {
        printf("Welcome to the Password Manager.\n");
        printf("1. Log in\n");
        printf("2. Add a new user\n");
        printf("3. Change password\n");
        printf("4. Exit\n");
        printf("Please make a choice (1-4):\n");
        scanf("%d", &choice);
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                if (wrong_attempts >= MAX_WRONG_ATTEMPTS) {
                    printf("Too many incorrect attempts. Program exiting.\n");
                    return 1;
                }
                printf("Enter your username:\n");
                fgets(username, MAX_USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';
                printf("Enter your password:\n");
                fgets(password, MAX_PASSWORD_LENGTH, stdin);
                password[strcspn(password, "\n")] = '\0';
                if (authenticate(username, password)) {
                    printf("Login successful.\n");
                    wrong_attempts = 0;
                } else {
                    printf("Incorrect username or password.\n");
                    wrong_attempts++;
                }
                break;
            case 2:
                add_user();
                break;
            case 3:
                printf("Enter your username:\n");
                fgets(username, MAX_USERNAME_LENGTH, stdin);
                username[strcspn(username, "\n")] = '\0';
                change_password(username);
                break;
            case 4:
                printf("Program exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1-4.\n");
                break;
        }
    }
}