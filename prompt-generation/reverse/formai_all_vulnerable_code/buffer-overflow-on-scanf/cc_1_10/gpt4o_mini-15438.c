//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS 100
#define PASS_LENGTH 20
#define USER_LENGTH 30

typedef struct {
    char username[USER_LENGTH];
    char password[PASS_LENGTH];
} PasswordEntry;

PasswordEntry password_list[MAX_PASS];
int password_count = 0;

void add_password(const char *username, const char *password) {
    if (password_count < MAX_PASS) {
        strncpy(password_list[password_count].username, username, USER_LENGTH);
        strncpy(password_list[password_count].password, password, PASS_LENGTH);
        password_count++;
        printf("Password added for user: %s\n", username);
    } else {
        printf("Password storage is full!\n");
    }
}

void view_passwords() {
    if (password_count == 0) {
        printf("No passwords stored.\n");
        return;
    }
    printf("\nStored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("User: %s, Password: %s\n", password_list[i].username, password_list[i].password);
    }
    printf("Total stored passwords: %d\n", password_count);
}

void delete_password(const char *username) {
    for (int i = 0; i < password_count; i++) {
        if (strncmp(password_list[i].username, username, USER_LENGTH) == 0) {
            for (int j = i; j < password_count - 1; j++) {
                password_list[j] = password_list[j + 1];
            }
            password_count--;
            printf("Password deleted for user: %s\n", username);
            return;
        }
    }
    printf("No password found for user: %s\n", username);
}

void password_statistics() {
    if (password_count == 0) {
        printf("No passwords to analyze.\n");
        return;
    }
    
    int total_length = 0;
    int min_length = PASS_LENGTH;
    int max_length = 0;

    for (int i = 0; i < password_count; i++) {
        int len = strlen(password_list[i].password);
        total_length += len;
        if (len < min_length) {
            min_length = len;
        }
        if (len > max_length) {
            max_length = len;
        }
    }

    double average_length = (double)total_length / password_count;

    printf("\nPassword Statistics:\n");
    printf("Total passwords stored: %d\n", password_count);
    printf("Average password length: %.2f\n", average_length);
    printf("Shortest password length: %d\n", min_length);
    printf("Longest password length: %d\n", max_length);
}

int main() {
    int choice;
    char username[USER_LENGTH];
    char password[PASS_LENGTH];
    
    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Password Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline after the last input

        switch (choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, USER_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0; // Remove new line char

                printf("Enter password: ");
                fgets(password, PASS_LENGTH, stdin);
                password[strcspn(password, "\n")] = 0; // Remove new line char

                add_password(username, password);
                break;

            case 2:
                view_passwords();
                break;

            case 3:
                printf("Enter username to delete: ");
                fgets(username, USER_LENGTH, stdin);
                username[strcspn(username, "\n")] = 0; // Remove new line char
                
                delete_password(username);
                break;

            case 4:
                password_statistics();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}