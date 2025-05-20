//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 32
#define ENCRYPTION_KEY "this_is_a_secret"

typedef struct {
    char service[50];
    char encrypted_password[128];
} PasswordEntry;

PasswordEntry password_list[MAX_PASSWORDS];
int password_count = 0;

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(EXIT_FAILURE);
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)ENCRYPTION_KEY, NULL) != 1)
        handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    ciphertext[ciphertext_len] = '\0'; // Null-terminate the ciphertext
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)ENCRYPTION_KEY, NULL) != 1)
        handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, strlen((char *)ciphertext)) != 1) handleErrors();
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    plaintext[plaintext_len] = '\0'; // Null-terminate the plaintext
}

void add_password() {
    if (password_count >= MAX_PASSWORDS) {
        printf("Maximum password limit reached.\n");
        return;
    }

    char password[PASSWORD_LENGTH];
    printf("Enter the service name: ");
    scanf(" %49s", password_list[password_count].service);
    printf("Enter the password: ");
    scanf(" %31s", password);

    unsigned char encrypted_password[128];
    encrypt((unsigned char *)password, strlen(password), encrypted_password);
    strcpy(password_list[password_count].encrypted_password, (char *)encrypted_password);
    password_count++;

    printf("Password for %s added successfully.\n", password_list[password_count - 1].service);
}

void retrieve_password() {
    char service[50];
    printf("Enter the service name to retrieve the password: ");
    scanf(" %49s", service);

    for (int i = 0; i < password_count; i++) {
        if (strcmp(password_list[i].service, service) == 0) {
            unsigned char decrypted_password[PASSWORD_LENGTH];
            decrypt((unsigned char *)password_list[i].encrypted_password, decrypted_password);
            printf("Retrieved password for %s: %s\n", password_list[i].service, decrypted_password);
            return;
        }
    }
    printf("No password found for %s.\n", service);
}

void display_passwords() {
    printf("Stored Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("%d. %s\n", i + 1, password_list[i].service);
    }
}

int main() {
    int option;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Retrieve Password\n");
        printf("3. Display All Passwords\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                retrieve_password();
                break;
            case 3:
                display_passwords();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}