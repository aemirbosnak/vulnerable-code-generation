//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define USERNAME_MAX 32
#define PASSWORD_MAX 64
#define SHA256_DIGEST_LENGTH 32

typedef struct {
    char username[USERNAME_MAX];
    unsigned char password_hash[SHA256_DIGEST_LENGTH];
} User;

User users[100];
int user_count = 0;

// Function prototypes
void add_user();
void display_users();
void generate_salt(unsigned char salt[16]);
void hash_password(const char* password, unsigned char* hash, const unsigned char* salt);
void secure_delete(char* data, size_t length);

// SHA256 and other functions would go here (omitting exact implementation for brevity)
void sha256(const char* input, size_t length, unsigned char* output);
void produce_secure_password(const char* password);

int main() {
    int choice;
    
    printf("Welcome to the Paranoid Password Management System\n");
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please try again.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }
        
        switch (choice) {
            case 1: 
                add_user();
                break;
            case 2: 
                display_users();
                break;
            case 3: 
                printf("Exiting application. Stay safe!\n");
                return 0;
            default: 
                printf("Invalid option. Please select again.\n");
                break;
        }
    }
    return 0;
}

void add_user() {
    char password[PASSWORD_MAX];
    unsigned char salt[16];

    if (user_count >= 100) {
        printf("User storage full. Cannot add more users.\n");
        return;
    }

    printf("Enter username (max %d characters): ", USERNAME_MAX - 1);
    scanf("%s", users[user_count].username);
    
    printf("Enter a secure password: ");
    scanf("%s", password); // This is not ideal (password should be input securely)

    generate_salt(salt);
    hash_password(password, users[user_count].password_hash, salt);
    
    user_count++;
    printf("User added securely! Stay paranoid!\n");
}

void display_users() {
    printf("List of users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("User %d: %s\n", i + 1, users[i].username);
    }
}

void generate_salt(unsigned char salt[16]) {
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        salt[i] = rand() % 256;
    }
}

void hash_password(const char* password, unsigned char* hash, const unsigned char* salt) {
    char salted_password[PASSWORD_MAX + 16];
    snprintf(salted_password, sizeof(salted_password), "%s", password);
    strncat(salted_password, (char*)salt, 16);

    // Simple hash function for example purposes
    sha256(salted_password, strlen(salted_password), hash);
}

void secure_delete(char* data, size_t length) {
    volatile char *p = data;
    while (length--) *p++ = 0;
}

void sha256(const char* input, size_t length, unsigned char* output) {
    // Insert SHA256 implementation here (e.g., using OpenSSL or another library)
    // This example function is left unimplemented for brevity
    // Just ensure output is populated securely! 
}

void produce_secure_password(const char* password) {
    // Example function to produce a very secure password
    // This does not necessarily generate, but you can customize to requirements
}