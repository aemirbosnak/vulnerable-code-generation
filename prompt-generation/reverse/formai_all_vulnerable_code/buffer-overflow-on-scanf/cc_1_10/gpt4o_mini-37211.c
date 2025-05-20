//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 5
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char username[20];
    char key[20];
} User;

void generate_key(char *key, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int n = 0; n < length; n++) {
        int key_index = rand() % (sizeof(charset) - 1);
        key[n] = charset[key_index];
    }
    key[length] = '\0';
}

void encrypt(const char *message, const char *key, char *encrypted) {
    for (size_t i = 0; i < strlen(message); i++) {
        encrypted[i] = message[i] ^ key[i % strlen(key)];
    }
    encrypted[strlen(message)] = '\0';
}

void decrypt(const char *encrypted, const char *key, char *decrypted) {
    for (size_t i = 0; i < strlen(encrypted); i++) {
        decrypted[i] = encrypted[i] ^ key[i % strlen(key)];
    }
    decrypted[strlen(encrypted)] = '\0';
}

void display_menu() {
    printf("\n--- Cryptography System ---\n");
    printf("1. Generate Key\n");
    printf("2. Encrypt Message\n");
    printf("3. Decrypt Message\n");
    printf("4. Exit\n");
    printf("---------------------------\n");
    printf("Select an option: ");
}

int main() {
    srand(time(0));
    User users[MAX_USERS];
    int user_count = 0;
    char message[MAX_MESSAGE_LENGTH];
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];
    
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (user_count >= MAX_USERS) {
                printf("Maximum number of users reached!\n");
                continue;
            }
            printf("Enter username: ");
            scanf("%s", users[user_count].username);
            generate_key(users[user_count].key, 16);
            printf("Generated Key for %s: %s\n", users[user_count].username, users[user_count].key);
            user_count++;
        } 
        else if (choice == 2) {
            char username[20];
            printf("Enter your username: ");
            scanf("%s", username);
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].username, username) == 0) {
                    printf("Enter message to encrypt: ");
                    getchar(); // Consume newline
                    fgets(message, MAX_MESSAGE_LENGTH, stdin);
                    message[strcspn(message, "\n")] = 0; // Remove newline
                    encrypt(message, users[i].key, encrypted);
                    printf("Encrypted Message: %s\n", encrypted);
                    break;
                }
            }
        } 
        else if (choice == 3) {
            char username[20];
            printf("Enter your username: ");
            scanf("%s", username);
            for (int i = 0; i < user_count; i++) {
                if (strcmp(users[i].username, username) == 0) {
                    printf("Enter message to decrypt: ");
                    getchar(); // Consume newline
                    fgets(encrypted, MAX_MESSAGE_LENGTH, stdin);
                    encrypted[strcspn(encrypted, "\n")] = 0; // Remove newline
                    decrypt(encrypted, users[i].key, decrypted);
                    printf("Decrypted Message: %s\n", decrypted);
                    break;
                }
            }
        } 
        else if (choice == 4) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}