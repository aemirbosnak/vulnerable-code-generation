//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 64
#define AES_KEY_LENGTH 16 // 128 bits

typedef struct {
    char account_name[50];
    char encrypted_password[AES_BLOCK_SIZE];
} PasswordEntry;

PasswordEntry password_list[MAX_PASSWORDS];
int password_count = 0;

void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH)) {
        fprintf(stderr, "Key generation failed.\n");
        exit(1);
    }
}

void encrypt_password(const unsigned char *password, unsigned char *encrypted_password, unsigned char *key) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, AES_KEY_LENGTH * 8, &enc_key);
    AES_encrypt(password, encrypted_password, &enc_key);
}

void decrypt_password(const unsigned char *encrypted_password, unsigned char *decrypted_password, unsigned char *key) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, AES_KEY_LENGTH * 8, &dec_key);
    AES_decrypt(encrypted_password, decrypted_password, &dec_key);
}

void add_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Password storage full. Cannot add more passwords.\n");
        return;
    }

    char password[PASSWORD_LENGTH];
    printf("Enter account name: ");
    scanf("%s", password_list[password_count].account_name);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    unsigned char key[AES_KEY_LENGTH];
    generate_key(key);
    encrypt_password((unsigned char *)password, password_list[password_count].encrypted_password, key);
    
    password_count++;
    printf("Password added successfully!\n");
}

void view_passwords() {
    printf("Stored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        unsigned char decrypted_password[PASSWORD_LENGTH];
        unsigned char key[AES_KEY_LENGTH]; // This should retrieve or require a key to decrypt
        decrypt_password(password_list[i].encrypted_password, decrypted_password, key);
        
        printf("Account: %s, Password: %s\n", password_list[i].account_name, decrypted_password);
    }
}

void delete_password() {
    char account_name[50];
    printf("Enter the account name to delete: ");
    scanf("%s", account_name);

    for (int i = 0; i < password_count; i++) {
        if (strcmp(password_list[i].account_name, account_name) == 0) {
            for (int j = i; j < password_count - 1; j++) {
                password_list[j] = password_list[j + 1];
            }
            password_count--;
            printf("Password for %s deleted successfully.\n", account_name);
            return;
        }
    }
    printf("Account not found.\n");
}

void display_menu() {
    printf("\nPassword Management Menu:\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Delete Password\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}