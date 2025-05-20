//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define FILE_NAME "passwords.txt"
#define HASH_CONST 5381

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User users[MAX_USERS];
int user_count = 0;

unsigned long hash(const char *str) {
    unsigned long hash = HASH_CONST;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

void load_users() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // No users found yet
    }
    
    while (fscanf(file, "%s %s", users[user_count].username, users[user_count].password) != EOF) {
        user_count++;
    }
    
    fclose(file);
}

void save_users() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error saving users.\n");
        return;
    }

    for (int i = 0; i < user_count; i++) {
        fprintf(file, "%s %s\n", users[i].username, users[i].password);
    }

    fclose(file);
}

int find_user(const char *username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1; // User not found
}

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);
    
    if (find_user(username) != -1) {
        printf("Username already exists!\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    
    save_users();
    printf("User registered successfully!\n");
}

int authenticate_user() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    int index = find_user(username);
    if (index == -1 || strcmp(users[index].password, password) != 0) {
        printf("Authentication failed!\n");
        return 0;
    }

    printf("Authentication successful!\n");
    return 1;
}

void generate_secure_password(char *password) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    int length = 12; // Example password length
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0'; // Null-terminate the string
}

void change_password() {
    if (!authenticate_user()) {
        return;
    }

    char new_password[PASSWORD_LEN];
    generate_secure_password(new_password);
    printf("Your new secure password is: %s\n", new_password);
    
    int index = find_user(users[user_count - 1].username);
    strcpy(users[index].password, new_password);
    save_users();
}

void display_menu() {
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Change Password\n");
    printf("4. Exit\n");
}

int main() {
    load_users();
    
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                authenticate_user();
                break;
            case 3:
                change_password();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}