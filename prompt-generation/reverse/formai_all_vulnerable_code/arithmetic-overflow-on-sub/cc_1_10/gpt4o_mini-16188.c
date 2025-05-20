//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_USERS 5
#define BUFFER_SIZE 256

typedef struct {
    char username[50];
    int shift;
} User;

User users[MAX_USERS];
int user_count = 0;

void *encrypt_message(void *arg) {
    User *user = (User *)arg;
    char message[BUFFER_SIZE];
    char encrypted[BUFFER_SIZE];

    printf("User %s, enter a message to encrypt: ", user->username);
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + user->shift) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + user->shift) % 26 + 'A';
        } else {
            encrypted[i] = message[i];  // Non-alphabetic characters remain unchanged
        }
    }
    encrypted[strlen(message)] = '\0';  // Null-terminate the string

    printf("Encrypted message from %s: %s\n", user->username, encrypted);
    return NULL;
}

void *decrypt_message(void *arg) {
    User *user = (User *)arg;
    char encrypted[BUFFER_SIZE];
    char decrypted[BUFFER_SIZE];

    printf("User %s, enter a message to decrypt: ", user->username);
    fgets(encrypted, sizeof(encrypted), stdin);
    encrypted[strcspn(encrypted, "\n")] = 0;  // Remove newline

    for (int i = 0; encrypted[i] != '\0'; i++) {
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - 'a' - user->shift + 26) % 26 + 'a';
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - 'A' - user->shift + 26) % 26 + 'A';
        } else {
            decrypted[i] = encrypted[i];  // Non-alphabetic characters remain unchanged
        }
    }
    decrypted[strlen(encrypted)] = '\0';  // Null-terminate the string

    printf("Decrypted message from %s: %s\n", user->username, decrypted);
    return NULL;
}

int main() {
    pthread_t threads[MAX_USERS];
    int choice;
    
    // Initialize users
    printf("Enter the number of users (max %d): ", MAX_USERS);
    scanf("%d", &user_count);
    getchar(); // Clear the newline character from buffer

    for (int i = 0; i < user_count; i++) {
        printf("Enter username for user %d: ", i + 1);
        fgets(users[i].username, sizeof(users[i].username), stdin);
        users[i].username[strcspn(users[i].username, "\n")] = 0;  // Remove newline

        printf("Enter shift value for user %d: ", i + 1);
        scanf("%d", &users[i].shift);
        getchar(); // Clear the newline character from buffer
    }

    while (1) {
        printf("\nSelect operation:\n1. Encrypt message\n2. Decrypt message\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        if (choice == 3) {
            break;
        }

        int user_index;
        printf("Select user index (0 to %d): ", user_count - 1);
        scanf("%d", &user_index);
        getchar(); // Clear the newline character from buffer

        if (user_index < 0 || user_index >= user_count) {
            printf("Invalid user index. Please try again.\n");
            continue;
        }

        if (choice == 1) {
            pthread_create(&threads[user_index], NULL, encrypt_message, &users[user_index]);
        } else if (choice == 2) {
            pthread_create(&threads[user_index], NULL, decrypt_message, &users[user_index]);
        } else {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Wait for the thread to complete
        pthread_join(threads[user_index], NULL);
    }

    return 0;
}