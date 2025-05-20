//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define FILE_NAME "cyber_users.dat"

typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void clear_screen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void print_header() {
    clear_screen();
    printf("=== Cyberpunk User Management System ===\n");
    printf("      Powered by Neon Light Tech      \n");
    printf("========================================\n");
}

void save_user(User user) {
    FILE *file = fopen(FILE_NAME, "a+b");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
}

void read_users() {
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Existing Users:\n");
    while (fread(&user, sizeof(User), 1, file)) {
        printf("Username: %s\n", user.username);
    }
    fclose(file);
}

int is_username_taken(const char* username) {
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 0;  // Assume username is not taken if file can't be opened
    }

    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0) {
            fclose(file);
            return 1;  // Username is taken
        }
    }
    fclose(file);
    return 0;  // Username is available
}

void register_user() {
    User new_user;
    print_header();
    
    printf("Enter username: ");
    fgets(new_user.username, sizeof(new_user.username), stdin);
    new_user.username[strcspn(new_user.username, "\n")] = '\0'; // Remove newline

    if (is_username_taken(new_user.username)) {
        printf("Username already taken! Try again.\n");
        sleep(2);
        return;
    }

    printf("Enter password: ");
    fgets(new_user.password, sizeof(new_user.password), stdin);
    new_user.password[strcspn(new_user.password, "\n")] = '\0'; // Remove newline

    save_user(new_user);
    printf("User registered successfully.\n");
    sleep(2);
}

void login_user() {
    User user;
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int found = 0;

    print_header();
    
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Remove newline

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline

    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            found = 1;
            break;
        }
    }
    fclose(file);

    if (found) {
        printf("Login successful! Welcome %s.\n", username);
    } else {
        printf("Invalid username or password. Try again.\n");
    }
    sleep(2);
}

void main_menu() {
    int choice;

    do {
        print_header();
        printf("1. Register User\n");
        printf("2. Login\n");
        printf("3. View Users\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                read_users();
                sleep(2);
                break;
            case 4:
                printf("Exiting... Stay safe in the neon streets.\n");
                sleep(2);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                sleep(2);
                break;
        }
    } while (choice != 4);
}

int main() {
    main_menu();
    return 0;
}