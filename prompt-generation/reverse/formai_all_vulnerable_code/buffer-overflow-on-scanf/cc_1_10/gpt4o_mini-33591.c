//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 16
#define SALT_LENGTH 8

typedef struct {
    char service[50];
    char username[50];
    char password[PASSWORD_LENGTH + 1];
    char salt[SALT_LENGTH + 1];
} PasswordEntry;

PasswordEntry password_db[MAX_PASSWORDS];
int password_count = 0;

void generate_salt(char* salt) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < SALT_LENGTH; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        salt[i] = charset[key];
    }
    salt[SALT_LENGTH] = '\0';
}

void encrypt_password(const char* password, char* encrypted_password, const char* salt) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        encrypted_password[i] = password[i] ^ salt[i % SALT_LENGTH]; // Simple XOR encryption
    }
    encrypted_password[PASSWORD_LENGTH] = '\0';
}

void decrypt_password(const char* encrypted_password, char* decrypted_password, const char* salt) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        decrypted_password[i] = encrypted_password[i] ^ salt[i % SALT_LENGTH];
    }
    decrypted_password[PASSWORD_LENGTH] = '\0';
}

void add_password(const char* service, const char* username, const char* password) {
    if (password_count >= MAX_PASSWORDS) {
        printf("Database full! Cannot add more passwords.\n");
        return;
    }

    strncpy(password_db[password_count].service, service, sizeof(password_db[password_count].service));
    strncpy(password_db[password_count].username, username, sizeof(password_db[password_count].username));

    generate_salt(password_db[password_count].salt);
    encrypt_password(password, password_db[password_count].password, password_db[password_count].salt);
    
    password_count++;
    printf("Password for %s successfully added!\n", service);
}

void display_passwords() {
    printf("\n=== Password Vault ===\n");
    for (int i = 0; i < password_count; i++) {
        printf("Service: %s\n", password_db[i].service);
        printf("Username: %s\n", password_db[i].username);
        printf("Password: [Hidden]\n");
    }
    printf("=======================\n");
}

void retrieve_password(const char* service) {
    for (int i = 0; i < password_count; i++) {
        if (strcmp(service, password_db[i].service) == 0) {
            char decrypted_password[PASSWORD_LENGTH + 1];
            decrypt_password(password_db[i].password, decrypted_password, password_db[i].salt);
            printf("Service: %s\n", password_db[i].service);
            printf("Username: %s\n", password_db[i].username);
            printf("Password: %s\n", decrypted_password);
            return;
        }
    }
    printf("No entry found for service: %s\n", service);
}

void clear_passwords() {
    password_count = 0;
    printf("All passwords have been cleared from the vault.\n");
}

void print_menu() {
    printf("\n--- Password Management System ---\n");
    printf("1. Add Password\n");
    printf("2. Display Passwords\n");
    printf("3. Retrieve Password\n");
    printf("4. Clear Vault\n");
    printf("5. Exit\n");
}

int main() {
    srand(time(NULL));
    int choice;
    char service[50], username[50], password[PASSWORD_LENGTH + 1];

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter Service: ");
                fgets(service, sizeof(service), stdin);
                service[strcspn(service, "\n")] = 0; // Remove trailing newline

                printf("Enter Username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0; // Remove trailing newline

                printf("Enter Password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0; // Remove trailing newline

                add_password(service, username, password);
                break;

            case 2:
                display_passwords();
                break;

            case 3:
                printf("Enter Service to retrieve: ");
                fgets(service, sizeof(service), stdin);
                service[strcspn(service, "\n")] = 0; // Remove trailing newline
                
                retrieve_password(service);
                break;

            case 4:
                clear_passwords();
                break;

            case 5:
                printf("Exiting the system. Stay safe in the shadows!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}