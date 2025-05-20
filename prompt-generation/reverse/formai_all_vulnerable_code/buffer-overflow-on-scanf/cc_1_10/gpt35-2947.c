//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define PASSWORD_LENGTH 16

struct password {
    char username[30];
    char password[PASSWORD_LENGTH + 1];
};

struct password passwords[MAX_PASSWORDS];
int password_count = 0;

void save_password(char *username, char *password);
void view_passwords();
void search_password(char *username);
char *encrypt_password(char *password);
char *decrypt_password(char *password);

int main() {
    int choice;
    printf("Welcome to Password Manager\n");

    do {
        printf("\n");
        printf("1. Add a Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                {
                    char username[30];
                    char password[PASSWORD_LENGTH + 1];

                    printf("Enter username: ");
                    fgets(username, 30, stdin);
                    username[strcspn(username, "\n")] = 0;

                    printf("Enter password: ");
                    fgets(password, PASSWORD_LENGTH + 1, stdin);
                    password[strcspn(password, "\n")] = 0;

                    save_password(username, password);
                    printf("Password saved successfully.\n");
                }
                break;

            case 2:
                view_passwords();
                break;

            case 3:
                {
                    char username[30];

                    printf("Enter username: ");
                    fgets(username, 30, stdin);
                    username[strcspn(username, "\n")] = 0;

                    search_password(username);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void save_password(char *username, char *password) {
    struct password new_password;

    strcpy(new_password.username, username);
    strcpy(new_password.password, encrypt_password(password));

    passwords[password_count] = new_password;
    password_count++;
}

void view_passwords() {
    if (password_count == 0) {
        printf("No passwords saved.\n");
    } else {
        for (int i = 0; i < password_count; i++) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", decrypt_password(passwords[i].password));
            printf("\n");
        }
    }
}

void search_password(char *username) {
    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Username: %s\n", passwords[i].username);
            printf("Password: %s\n", decrypt_password(passwords[i].password));
            return;
        }
    }

    printf("Password for username '%s' not found.\n", username);
}

char *encrypt_password(char *password) {
    int length = strlen(password);
    char *encrypted_password = malloc(length);

    for (int i = 0; i < length; i++) {
        encrypted_password[i] = password[i] + 1;
    }

    return encrypted_password;
}

char *decrypt_password(char *password) {
    int length = strlen(password);
    char *decrypted_password = malloc(length);

    for (int i = 0; i < length; i++) {
        decrypted_password[i] = password[i] - 1;
    }

    return decrypted_password;
}