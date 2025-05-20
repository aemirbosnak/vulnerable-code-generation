//FormAI DATASET v1.0 Category: Password management ; Style: distributed
// Password management program in a distributed style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_USERS 10

// Struct to store user info
typedef struct {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

// Array to store all users
user_t users[MAX_USERS];

// Lock for updating user array
pthread_mutex_t user_lock = PTHREAD_MUTEX_INITIALIZER;

// Function to check if a user exists
int user_exists(char* name) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new user
void add_user(char* name, char* password) {
    pthread_mutex_lock(&user_lock);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strlen(users[i].name) == 0) {
            strcpy(users[i].name, name);
            strcpy(users[i].password, password);
            break;
        }
    }

    pthread_mutex_unlock(&user_lock);
}

// Function to update a user's password
void update_password(char* name, char* password) {
    pthread_mutex_lock(&user_lock);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, name) == 0) {
            strcpy(users[i].password, password);
            break;
        }
    }

    pthread_mutex_unlock(&user_lock);
}

// Function to delete a user
void delete_user(char* name) {
    pthread_mutex_lock(&user_lock);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, name) == 0) {
            memset(&users[i], 0, sizeof(user_t));
            break;
        }
    }

    pthread_mutex_unlock(&user_lock);
}

// Function to check if a password is strong
int is_password_strong(char* password) {
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }
    int num_count = 0, upper_count = 0, lower_count = 0, special_count = 0;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (c >= '0' && c <= '9') {
            num_count++;
        } else if (c >= 'A' && c <= 'Z') {
            upper_count++;
        } else if (c >= 'a' && c <= 'z') {
            lower_count++;
        } else {
            special_count++;
        }
    }
    if (num_count < 2 || upper_count < 2 || lower_count < 2 || special_count < 2) {
        return 0;
    }
    return 1;
}

// Function to handle password change requests
void* password_change_handler(void* arg) {
    char* name = (char*) arg;

    char current_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];

    printf("%s, Enter your current password: ", name);
    scanf("%s", current_password);

    char* current_password_to_check = strdup(current_password);
    if (!user_exists(name) || strcmp(users[user_exists(name)].password, current_password_to_check) != 0) {
        printf("Incorrect Password\n");
        return NULL;
    }

    printf("Enter new password : ");
    scanf("%s", new_password);

    if (!is_password_strong(new_password)) {
        printf("Password is not strong. Password should have atleast 8 characters including 2 Uppercase letters, 2 Lowercase letters and 2 Special Characters.\n");
        return NULL;
    }

    update_password(name, new_password);
    printf("Password updated successfully for %s\n", name);

    return NULL;
}

// Function to handle registration requests
void* registration_handler(void* arg) {
    char* name = (char*) arg;

    if (user_exists(name)) {
        printf("Registration Failed: %s already exists\n", name);
        return NULL;
    }

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (!is_password_strong(password)) {
        printf("Password is not strong. Password should have atleast 8 characters including 2 Uppercase letters, 2 Lowercase letters and 2 Special Characters.\n");
        return NULL;
    }

    add_user(name, password);
    printf("Registration Successful for %s\n", name);

    return NULL;
}

// Main function
int main() {
    // Initializing the user array
    memset(users, 0, sizeof(users));

    printf("Welcome to the Password Management System\n");

    while (1) {
        printf("\n1. Register\n");
        printf("2. Change Password\n");
        printf("3. Delete Account\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char name[50];
            printf("Enter your name: ");
            scanf("%s", name);
            pthread_t tid;
            pthread_create(&tid, NULL, registration_handler, (void*) name);
            pthread_join(tid, NULL);
        } else if (choice == 2) {
            char name[50];
            printf("Enter your name: ");
            scanf("%s", name);
            pthread_t tid;
            pthread_create(&tid, NULL, password_change_handler, (void*) name);
            pthread_join(tid, NULL);
        } else if (choice == 3) {
            char name[50];
            printf("Enter your name: ");
            scanf("%s", name);
            delete_user(name);
            printf("Account deleted successfully for %s\n", name);
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}