//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 256
#define FILE_NAME "passwords.txt"

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int password_count = 0;

void encrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0xAA; // Simple XOR encryption
    }
    output[strlen(input)] = '\0'; // Null terminate
}

void decrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0xAA; // Simple XOR decryption
    }
    output[strlen(input)] = '\0'; // Null terminate
}

void load_passwords() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return; // File does not exist
    }

    while (fscanf(file, "%s %s %s", passwords[password_count].website, 
                  passwords[password_count].username, 
                  passwords[password_count].password) != EOF) {
        password_count++;
    }
    fclose(file);
}

void save_passwords() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for saving passwords.\n");
        return;
    }

    char encrypted_password[MAX_LENGTH];
    for (int i = 0; i < password_count; i++) {
        encrypt(passwords[i].password, encrypted_password);
        fprintf(file, "%s %s %s\n", passwords[i].website, passwords[i].username, encrypted_password);
    }
    fclose(file);
}

void add_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage is full.\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", passwords[password_count].website);
    printf("Enter username: ");
    scanf("%s", passwords[password_count].username);
    printf("Enter password: ");
    scanf("%s", passwords[password_count].password);

    password_count++;
    save_passwords();
}

void view_passwords() {
    char decrypted_password[MAX_LENGTH];
    for (int i = 0; i < password_count; i++) {
        decrypt(passwords[i].password, decrypted_password);
        printf("Website: %s, Username: %s, Password: %s\n", 
               passwords[i].website, passwords[i].username, decrypted_password);
    }
}

void delete_password() {
    char website[MAX_LENGTH];
    printf("Enter the website of the password to delete: ");
    scanf("%s", website);

    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            for (int j = i; j < password_count - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            password_count--;
            save_passwords();
            printf("Password for %s deleted successfully.\n", website);
            return;
        }
    }
    printf("Password for %s not found.\n", website);
}

void display_menu() {
    printf("\nPassword Manager\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    load_passwords();

    int choice = 0;
    while (choice != 4) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}